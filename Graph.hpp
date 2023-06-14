#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <list>
#include "DisjointSet.hpp"

using namespace std;

class Graph {
    private:
        struct Edge {
            int source, destination, weight;
        };
        bool mode;
        int VERTICES;
        vector<vector<int>> matrixGraph;
        vector<list<int>> listGraph;
        vector<Edge> edgeList;
    public:
        Graph(const string &filename, bool gMode) {
            if (gMode == 1) {
                this->matrixGraph = loadGraphToMatrix(filename);
                this->VERTICES = matrixGraph.size();
                this->mode = gMode;
            }
            if (gMode == 0) {
                this->listGraph = loadGraphToList(filename);
                this->VERTICES = listGraph.size();
                this->mode = gMode;
            }
        }

        ~Graph() {};

        vector<vector<int>> loadGraphToMatrix(const string &filename) {
            ifstream file(filename);
            vector<vector<int>> graph;
            if (!file) {
                cout << "Error opening file: " << filename << endl;
                return graph;
            }

            string line;
            while (getline(file, line)) {
                vector<int> vertice;
                stringstream ss(line);
                string edge;

                while (getline(ss, edge, ',')) {
                    vertice.push_back(stoi(edge));
                }
                graph.push_back(vertice);
            }

            file.close();
            return graph;
        }

        vector<list<int>> loadGraphToList(const string &filename) {
            ifstream file(filename);
            vector<list<int>> graph;
            if (!file) {
                cout << "Error opening file: " << filename << endl;
                return graph;
            }

            string line;
            while (getline(file, line)) {
                list<int> node;
                stringstream ss(line);
                string edge;

                while (getline(ss, edge, ',')) {
                    if (edge == "0")
                        continue;
                    else
                        node.push_back(stoi(edge));
                }
                graph.push_back(node);
            }

            file.close();
            return graph;
        };

        void printEdges() {
            for (auto i : this->edgeList) {
                cout << i.weight << " " << i.source << " " << i.destination << endl;
            }
        }

        void print() {
            for (auto i : this->listGraph) {
                for (auto j : i) cout << j << " ";
                cout << endl;
            }
        }

        void kruskalMST() {
            if (mode) {
                for (int node = 0; node < this->matrixGraph.size(); node++) {
                    for (int connection = 0; connection < this->matrixGraph[node].size(); connection++) {
                        if (matrixGraph[node][connection] == 0) continue;
                        int source = node;
                        int destination = connection;
                        int weight = matrixGraph[node][connection];
                        edgeList.push_back({node, connection, weight});
                    }
                }
            }
            if (!mode) {
                for (int node = 0; node < listGraph.size(); node++) {
                    int connection = 0;
                    for (auto weight : listGraph[node]) {
                        if (node == connection) connection++;
                        edgeList.push_back({node, connection, weight});
                        connection++;
                    }
                }
            }

            sort(edgeList.begin(), edgeList.end(), [](const Edge &edge1, const Edge &edge2) {
                                                            int result = 0;
                                                            if((edge2.weight > edge1.weight) || 
                                                            ((edge2.weight == edge1.weight) && 
                                                            (edge2.destination > edge1.destination)))
                                                            {
                                                                result = 1;
                                                            }
                                                                return result; });

            DS set(VERTICES);
            int weight_sum = 0;

            for (int i = 0; i < edgeList.size(); i++) {
                int weight = edgeList[i].weight;
                int source = edgeList[i].source;
                int destination = edgeList[i].destination;

                if (set.find(source) != set.find(destination)) {
                    set.unite(source, destination);
                    weight_sum += weight;
                    cout << "From: " << source << " To: " << destination << " | Weight: " << weight << endl;
                }
            }
            cout << "Cost: " << weight_sum << endl;
        }

        bool isValidEdge(int u, int v, vector<bool> inMST) {
            if (u == v)
                return false;
            if (inMST[u] == false && inMST[v] == false)
                return false;
            else if (inMST[u] == true && inMST[v] == true)
                return false;
            return true;
        }

        void primMST() {
            vector<bool> inMST(VERTICES, false);
            inMST[0] = true;
            int edge_count = 0, mincost = 0;

            if (mode) {
                while (edge_count < VERTICES - 1) {
                    int min = INT_MAX, a = -1, b = -1;
                    for (int i = 0; i < VERTICES; i++) {
                        for (int j = 0; j < VERTICES; j++) {
                            if (matrixGraph[i][j] < min) {
                                if (isValidEdge(i, j, inMST)) {
                                    min = matrixGraph[i][j];
                                    a = i;
                                    b = j;
                                }
                            }
                        }
                    }
                    if (a != -1 && b != -1) {
                        cout << "From: " << b << " To: " << edge_count++ << " | Weight: " << min << endl;
                        mincost = mincost + min;
                        inMST[b] = inMST[a] = true;
                    }
                }
                cout << "Cost: " << mincost << endl;
            }
            if (!mode) {
                while (edge_count < VERTICES - 1) {
                    int min = INT_MAX, a = -1, b = -1;
                    for (int i = 0; i < VERTICES; i++) {
                        int connection = 0;
                        for (auto j : listGraph[i]) {
                            if (i == connection) connection++;
                            if (j < min) {
                                if (isValidEdge(i, connection, inMST)) {
                                    min = j;
                                    a = i;
                                    b = connection;
                                }
                            }
                            connection++;
                        }
                    }
                    if (a != -1 && b != -1) {
                        cout << "From: " << b << " To: " << edge_count++ << " | Weight: " << min << endl;
                        mincost = mincost + min;
                        inMST[b] = inMST[a] = true;
                    }
                }
                cout << "Cost: " << mincost << endl;
            }
        }
};

#endif