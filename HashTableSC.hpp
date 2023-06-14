#ifndef HASHTABLE_SC_HPP
#define HASHTABLE_SC_HPP

#include <iostream>
#include <list>
#include <cstring>
#include <cmath>
#include <chrono>

using namespace std::chrono;
using namespace std;

class HashTableSC {
    private:
        static const int HTsize = 50;
        list<pair<int, string>> table[HTsize];
    public:
        bool isEmpty();
        int hashFunc(int index);
        void add(int index, string student);
        void remove(int index);
        void showElements();
        void searchForElement(int index);
};

bool HashTableSC::isEmpty() {
    for(int i = 0 ; i < HTsize ; i++)
    {
        if(table[i].size()!=0)
            return true;
        else
            continue;
    }
    return false;
}

int HashTableSC::hashFunc(int index) {
    return index%HTsize;
}

void HashTableSC::add(int index, string student) {
    int Hash = hashFunc(index);
    auto& indeks = table[Hash];
    auto iterator = begin(indeks);
    bool IDexist = false;
    for(; iterator != end(indeks); iterator++) {
        if(iterator->first == index) {
            IDexist = true;
            iterator->second = student;
            break;
        }
    }

    if(!IDexist) {
        indeks.emplace_back(index, student);
    }
    return;
}

void HashTableSC::remove(int index) {
    int Hash = hashFunc(index);
    auto& indeks = table[Hash];
    auto iterator = begin(indeks);
    for(; iterator != end(indeks); iterator++) {
        if(iterator->first == index) {
            iterator = indeks.erase(iterator);
            break;
        }
        else continue;
    }
    return;
}

void HashTableSC::showElements() {
    for(int i=0; i<HTsize; i++) {
        if(table[i].size() == 0) continue;

        auto iterator = table[i].begin();
        for(; iterator != table[i].end(); iterator++) {
            cout<<"Index: "<< iterator->first<<" Student: "<< iterator->second<<endl;
            cout<<endl;
        }
    }
}

void HashTableSC::searchForElement(int index) {
    int Hash = hashFunc(index);
    auto& indeks = table[Hash];
    bool IDexist = false;
    auto iterator = begin(indeks);
    auto start = high_resolution_clock::now();
    for(; iterator != end(indeks); iterator++) {
        if(iterator->first == index) {
            cout<<"Index: "<<iterator->first<<" Name: "<<iterator->second<<endl;
            IDexist = true;
            break;
        }
    }
    if(!IDexist) {
        cout<<"Doesn't exist"<<endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "(Czas wykonania funkcji: "<< duration.count() << " mikrosekund)" << endl;
    return;
}

#endif