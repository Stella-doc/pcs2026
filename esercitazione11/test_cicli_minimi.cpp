//test cicli minimi
//test cicli minimi
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "cicli_minimi.h"

//funzione per stampare i cicli in modo carino
void stampa_cicli(unidirected_graph& graph, const std::vector<std::vector<int>>& cicli, const std::string& nome_algoritmo) {
    std::cout<< nome_algoritmo<< std::endl;
    auto edges = graph.all_edges();
    
    std::vector<unidirected_edge> v_edges(edges.begin(), edges.end());

    if (cicli.empty()) {
        std::cout << "Nessun ciclo trovato." << std::endl;
        return;
    }

    int count = 1;
    for (const auto& ciclo : cicli) {
        std::cout << "Ciclo " << count++ << ": ";
        bool primo_arco = true;
        
        for (size_t i = 0; i < ciclo.size(); ++i) {
            if (ciclo[i] == 1) {
                if (!primo_arco) {
                    std::cout << ", ";
                }
                std::cout << "(" << v_edges[i].from() << "-" << v_edges[i].to() << ")";
                primo_arco = false;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
}

int main() {
	//grafo test composto da un quadriltero con un arco obliquo (due triangoli) e un test per i nosi isolati
    std::set<int> nodes = {0, 1, 2, 3, 4};
    std::set<unidirected_edge> edges = {
        unidirected_edge(0, 1),
        unidirected_edge(1, 2),
        unidirected_edge(2, 3),
        unidirected_edge(3, 0),
        unidirected_edge(1, 3),
        unidirected_edge(0, 4)
    };

    unidirected_graph g(nodes, edges);

    //test dfs
    std::vector<std::vector<int>> cicli_dfs = cicli_fondamentali_dfs(g);
    stampa_cicli(g, cicli_dfs, "Cicli Fondamentali DFS");

    //test de pina
    std::vector<std::vector<int>> cicli_depina = de_pina(g);
    stampa_cicli(g, cicli_depina, "Cicli minimi De Pina");

    return 0;
}