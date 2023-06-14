#include <iostream>
#include <chrono>
#include "Graph.hpp"
#include "HashTableSC.hpp"
#include "HashTableOA.hpp"

using namespace std;

//vector<vector<int>> GRAPH[vertice][edge]

// Graph ... ("tsp.csv", 1)- Matrix
// Graph .. ("tsp.csv", 0)- Adjacency list

int main() {
    Graph matrix("tsp.csv", 1);
    Graph list("tsp.csv", 0);
    
    cout << "\n|KRUSKAL for MATRIX|\n";
    auto s_kruskal_matrix = chrono::high_resolution_clock::now();
    matrix.kruskalMST();
    auto e_kruskal_matrix = chrono::high_resolution_clock::now();
    auto kruskal_matrix_duration = chrono::duration_cast<chrono::microseconds>(e_kruskal_matrix - s_kruskal_matrix);
    cout << "(Time: " << kruskal_matrix_duration.count() << " microsecs)\n";

    cout << "\n|KRUSKAL for LIST|\n";
    auto s_kruskal_list = chrono::high_resolution_clock::now();
    list.kruskalMST();
    auto e_kruskal_list = chrono::high_resolution_clock::now();
    auto kruskal_list_duration = chrono::duration_cast<chrono::microseconds>(e_kruskal_list - s_kruskal_list);
    cout << "(Time: " << kruskal_list_duration.count() << " microsecs)\n";


    cout << "\n|PRIM for MATRIX|\n";
    auto s_prim_matrix = chrono::high_resolution_clock::now();
    matrix.primMST();
    auto e_prim_matrix = chrono::high_resolution_clock::now();
    auto prim_matrix_duration = chrono::duration_cast<chrono::microseconds>(e_prim_matrix - s_prim_matrix);
    cout << "(Time: " << prim_matrix_duration.count() << " microsecs)\n";

    cout << "\n|PRIM for LIST|\n";
    auto s_prim_list = chrono::high_resolution_clock::now();
    list.primMST();
    auto e_prim_list = chrono::high_resolution_clock::now();
    auto prim_list_duration = chrono::duration_cast<chrono::microseconds>(e_prim_list - s_prim_list);
    cout << "(Time: " << prim_list_duration.count() << " microsecs)\n";


//==================================================================================================================
 
    // HashTableOA HT;
    // HT.add(264200,"Emily");
    // HT.add(264201,"Sarah");
    // HT.add(264202,"Michael");
    // HT.add(264203,"Daniel");
    // HT.add(264204,"Sophia");
    // HT.add(264205,"Sarah");
    // HT.add(264206,"Olivia");
    // HT.add(264207,"Michael");
    // HT.add(264208,"Olivia");
    // HT.add(264209,"John");
    // HT.add(264210,"John");
    // HT.add(264211,"John");
    // HT.add(264212,"Daniel");
    // HT.add(264213,"Emily");
    // HT.add(264214,"Emma");
    // HT.add(264215,"Emma");
    // HT.add(264216,"Daniel");
    // HT.add(264217,"John");
    // HT.add(264218,"Sarah");
    // HT.add(264219,"Olivia");
    // HT.add(264220,"Sarah");
    // HT.add(264221,"James");
    // HT.add(264222,"Sophia");
    // HT.add(264223,"Emily");
    // HT.add(264224,"Sophia");
    // HT.add(264225,"David");
    // HT.add(264226,"John");
    // HT.add(264227,"John");
    // HT.add(264228,"Emma");
    // HT.add(264229,"James");
    // HT.add(264230,"Olivia");
    // HT.add(264231,"Sarah");
    // HT.add(264232,"James");
    // HT.add(264233,"Emily");
    // HT.add(264234,"Sophia");
    // HT.add(264235,"Sarah");
    // HT.add(264236,"David");
    // HT.add(264237,"Daniel");
    // HT.add(264238,"Michael");
    // HT.add(264239,"James");
    // HT.add(264240,"David");
    // HT.add(264241,"Michael");
    // HT.add(264242,"David");
    // HT.add(264243,"Michael");
    // HT.add(264244,"Emma");
    // HT.add(264245,"Sarah");
    // HT.add(264246,"David");
    // HT.add(264247,"Emma");
    // HT.add(264248,"Michael");
    // HT.add(264249,"Sarah");
    // HT.add(264250,"Emily");
    // HT.add(264251,"James");
    // HT.add(264252,"James");
    // HT.add(264253,"John");
    // HT.add(264254,"Olivia");
    // HT.add(264255,"James");
    // HT.add(264256,"Daniel");
    // HT.add(264257,"Daniel");
    // HT.add(264258,"John");
    // HT.add(264259,"Daniel");
    // HT.add(264260,"Sophia");
    // HT.add(264261,"Daniel");
    // HT.add(264262,"John");
    // HT.add(264263,"Emma");
    // HT.add(264264,"Sophia");
    // HT.add(264265,"David");
    // HT.add(264266,"James");
    // HT.add(264267,"Sophia");
    // HT.add(264268,"Emma");
    // HT.add(264269,"David");
    // HT.add(264270,"Daniel");
    // HT.add(264271,"Olivia");
    // HT.add(264272,"Emily");
    // HT.add(264273,"Daniel");
    // HT.add(264274,"Emma");
    // HT.add(264275,"Sophia");
    // HT.add(264276,"John");
    // HT.add(264277,"Michael");
    // HT.add(264278,"Sophia");
    // HT.add(264279,"David");
    // HT.add(264280,"Emma");
    // HT.add(264281,"Daniel");
    // HT.add(264282,"Daniel");
    // HT.add(264283,"Emma");
    // HT.add(264284,"Daniel");
    // HT.add(264285,"Emma");
    // HT.add(264286,"James");
    // HT.add(264287,"Emma");
    // HT.add(264288,"John");
    // HT.add(264289,"David");
    // HT.add(264290,"Emma");
    // HT.add(264291,"Daniel");
    // HT.add(264292,"Sarah");
    // HT.add(264293,"Michael");
    // HT.add(264294,"Daniel");
    // HT.add(264295,"Sophia");
    // HT.add(264296,"David");
    // HT.add(264297,"David");
    // HT.add(264298,"Michael");
    // HT.add(264299,"Olivia");
    // HT.add(264300,"Daniel");
    // HT.add(264301,"Emma");
    // HT.add(264302,"Olivia");
    // HT.add(264303,"Emma");
    // HT.add(264304,"Daniel");
    // HT.add(264305,"Olivia");
    // HT.add(264306,"Sophia");
    // HT.add(264307,"Sophia");
    // HT.add(264308,"Michael");
    // HT.add(264309,"Olivia");
    // HT.add(264310,"David");
    // HT.add(264311,"Michael");
    // HT.add(264312,"Olivia");
    // HT.add(264313,"Olivia");
    // HT.add(264314,"Olivia");
    // HT.add(264315,"Emma");
    // HT.add(264316,"Sophia");
    // HT.add(264317,"Daniel");
    // HT.add(264318,"Olivia");
    // HT.add(264319,"Michael");
    // HT.add(264320,"Emily");
    // HT.add(264321,"Emily");
    // HT.add(264322,"Emma");
    // HT.add(264323,"James");
    // HT.add(264324,"James");
    // HT.add(264325,"Emily");
    // HT.add(264326,"Sophia");
    // HT.add(264327,"Sophia");
    // HT.add(264328,"Olivia");
    // HT.add(264329,"Michael");
    // HT.add(264330,"Emily");
    // HT.add(264331,"David");
    // HT.add(264332,"Emily");
    // HT.add(264333,"James");
    // HT.add(264334,"Olivia");
    // HT.add(264335,"Sophia");
    // HT.add(264336,"Daniel");
    // HT.add(264337,"Emily");
    // HT.add(264338,"James");
    // HT.add(264339,"Emily");
    // HT.add(264340,"Sarah");
    // HT.add(264341,"David");
    // HT.add(264342,"Michael");
    // HT.add(264343,"Sarah");
    // HT.add(264344,"Emily");
    // HT.add(264345,"James");
    // HT.add(264346,"Olivia");
    // HT.add(264347,"Michael");
    // HT.add(264348,"Sarah");
    // HT.add(264349,"John");

    // // HT.showElements();

    // for(int i = 264200; i < 264350; i+=25) {
    //     HT.searchForElement(i);
    //     cout << endl;
    // }

    return 0;
}