//cicli minimi
#include <iostream>
#include "graph_visit.h"
#include <vector>
#include <set>
#include <map>
#include <algorithm>

//mi serve per dfs e trova tutti i possibili cammini
bool findpath(unidirected_graph& T, int u, int v, std::set<int>& visited, std::vector<int>& path) {
    visited.insert(u);
    path.push_back(u);
    
    if (u == v) {
        return true;
    }
    
    for (int w : T.neighbours(u)) {
        if (!visited.contains(w)) {
            if (findpath(T, w, v, visited, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

//cicli minimi con dfs
std::vector<std::vector<int>> cicli_fondamentali_dfs(unidirected_graph graph) {
    std::vector<std::vector<int>> lista_cicli;
    if (graph.all_nodes().empty()) {
        return lista_cicli;
    }
    
    int m = graph.all_edges().size(); //quanti archi
    int root_node = *graph.all_nodes().begin();//inizio dei nodi

    unidirected_graph T = recurvise_dfs(graph, root_node);
    unidirected_graph C = graph - T;
    
    //ogni ramo del coalbero chiude un ciclo nell'albero T fatto con dfs
    for (auto edge : C.all_edges()) {
        int u = edge.from();
        int v = edge.to();
        
        std::set<int> visited;
        std::vector<int> path;
        
        if (findpath(T, u, v, visited, path)) {
            std::vector<int> ciclo_incidenza(m, 0);
            
            //registro gli archi dell'albero usati nel cammino
            for (size_t i = 0; i < path.size() - 1; ++i) {
                unidirected_edge e_tree(path[i], path[i + 1]);//arco dell'albero
                ciclo_incidenza[graph.edge_number(e_tree)] = 1;
            }
            //aggiungiamo l'arco del coalbero che chiude il ciclo corrente
            ciclo_incidenza[graph.edge_number(edge)] = 1;
            
            lista_cicli.push_back(ciclo_incidenza);
        }
    }
    return lista_cicli;
}

//questo mi serve per de pina
std::vector<int> trova_cammino_minimo_bfs(unidirected_graph& graph, int start, int target) {
    FIFO<int> queue;
    std::map<int, int> pred;
    std::set<int> visited;
    
    queue.put(start);
    visited.insert(start);
    pred[start] = start;
    
    bool found = false;
    
    while (!queue.empty()) {
        int u = queue.get();
        if (u == target) {
            found = true;
            break;
        }
        
        for (int w : graph.neighbours(u)) {
            if (!visited.contains(w)) {
                visited.insert(w);
                pred[w] = u;
                queue.put(w);
            }
        }
    }
    
    std::vector<int> path;//questo ciclo mi serve per risistemare l'oedine in cui ho trovato i nodi e procedo al contrario
    if (found) {
        int curr = target;
        while (curr != start) {
            path.push_back(curr);
            curr = pred[curr];
        }
        path.push_back(start);
        std::reverse(path.begin(), path.end());//inverto l'ordine dei nodi
    }
    return path;
}

//cicli minimi: de pina
std::vector<std::vector<int>> de_pina(unidirected_graph graph) {
    std::vector<std::vector<int>> B;
    if (graph.all_nodes().empty()) {
        return B;
    }
    //inizializzo come dfs
    int m = graph.all_edges().size();
    int root_node = *graph.all_nodes().begin();
    
    unidirected_graph T = recurvise_dfs(graph, root_node);
    unidirected_graph C = graph - T;
    
    int k = C.all_edges().size();
    std::vector<std::vector<int>> S(k, std::vector<int>(m, 0)); //vector con due argomenti: il primo è la dim del vettore e il secondo pone tutti gli elt a quel valore
    
    //inizializzazio dei vettori S_i "attivi" sui rispettivi archi del coalbero
    int i = 0;
    for (auto edge : C.all_edges()) {
        int edge_idx = graph.edge_number(edge);
        S[i][edge_idx] = 1;
        i++;
    }
    
    //calcolo offset dinamico per sdoppiare i nodi nel grafo di lifting G'
    int max_node = 0;
    for (int node : graph.all_nodes()) {
        if (node > max_node) max_node = node;
    }
    int offset = max_node + 1;
    //loop principale
    for (int i = 0; i < k; ++i) {
        
        //costruisco G' in base allo stato attuale di S_i
        std::set<int> empty_nodes;
        std::set<unidirected_edge> empty_edges;
        unidirected_graph graph_prime(empty_nodes, empty_edges);
        
        for (auto edge : graph.all_edges()) {
            int u = edge.from();
            int v = edge.to();
            int e_idx = graph.edge_number(edge);
            
            if (S[i][e_idx] == 1) {
                graph_prime.add_edge(u, v + offset); // u+ -> v-
                graph_prime.add_edge(u + offset, v); // u- -> v+
            } else {
                graph_prime.add_edge(u, v);          // u+ -> v+
                graph_prime.add_edge(u + offset, v + offset); // u- -> v-
            }
        }
        
        std::vector<int> best_C_i;
        int min_edges_count = m + 1;
        
        //ricerca ciclo di peso minimo proiettato esplorando i cammini minimi (v- ->v+)
        for (int v : graph.all_nodes()) {
            std::vector<int> path = trova_cammino_minimo_bfs(graph_prime, v + offset, v);
            if (!path.empty()) {
                std::vector<int> C_mu(m, 0);
                for (size_t l = 0; l < path.size() - 1; ++l) {
                    int curr = path[l];
                    int next = path[l + 1];
                    
                    int u_orig;
					if (curr >= offset) {
						u_orig = curr - offset;
					} 
					else {
						u_orig = curr;
					}	
					
                    int v_orig; 
					if (next>= offset){
						v_orig = next-offset;
					}
                    else{
						v_orig = next;
					}
					
                    unidirected_edge orig_edge(u_orig, v_orig);
                    int orig_idx = graph.edge_number(orig_edge);
                    C_mu[orig_idx] = (C_mu[orig_idx] + 1) % 2;
                }
                
                int active_edges = 0;
				int matching_edges = 0;
                for (int l=0; l<m; ++l) {
                    if (C_mu[l] == 1){
						active_edges++;
						if (S[i][l]==1){
							matching_edges++;
						}
					}
				}
				
				if (active_edges < min_edges_count && (matching_edges % 2 == 1)) {
                    min_edges_count = active_edges;
                    best_C_i = C_mu;
                }
			}
        }
		
		if (best_C_i.empty()) {
            continue;
        }
		
        B.push_back(best_C_i);

        //aggiornamento ortogonale dei restanti vettori di supporto S_j
        for (int j = i + 1; j < k; ++j) {
            int matching_edges = 0;
            for (int l = 0; l < m; ++l) {
                if (best_C_i[l] == 1 && S[j][l] == 1) {
                    matching_edges++;
                }
            }
            
            if (matching_edges % 2 == 1) {
                for (int l = 0; l < m; ++l) {
                    S[j][l] = S[j][l] ^ S[i][l]; //operazione XOR (differenza simmetrica)
                }
            }
        }
    }
    return B;
}