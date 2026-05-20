//visita grafi
#include <iostream>
#pragma once
#include <list>
#include <vector>
#include <set>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include "LIFO.h"
#include "FIFO.h"

std::vector<std::list<int>>
lista_adiacenza(unidirected_graph graph){
	std::vector<std::list<int>> array;
	
	std::list<int> lista_vuota; //decimo elt della lista per non fare segmentation falult in graph visit co lista[u]
	array.push_back(lista_vuota);
	
	std::set<int> nodes = graph.all_nodes();
	std::set<unidirected_edge> edges = graph.all_edges();
	
	for (auto node: nodes){
		std::list<int> lista;
		for (auto edge: edges){
			if (node == edge.from()){
				lista.push_back(edge.to());
			}
			if (node == edge.to()){
				lista.push_back(edge.from());
			}
		}
	array.push_back(lista);	
	}
	return array;
}

template<typename T>
unidirected_graph
//DFS -- STACK -- LIFO

graph_visit(const unidirected_graph& graph , const int root_node, LIFO<T> struct_type){
	std::vector<std::list<int>> lista_nodi = lista_adiacenza(graph);
	
	std::set<int> nodi_visitati;
	std::vector<bool> reached(lista_nodi.size(), false);
	std::set<unidirected_edge> final_edges;
		
	struct_type.put(root_node);
	reached[root_node] = true;
	
	while (!struct_type.empty()){
		int u = struct_type.get(); // u = nodo corrente
		nodi_visitati.insert(u);
		
		for (int i : lista_nodi[u]){ //ogni elt i nella lista del nodo u
			if (!reached[i]){// se non è presente in reached allora lo aggiungo
				reached[i]=true;
				struct_type.put(i);
				unidirected_edge edge= {u,i};
				final_edges.insert(edge);
				
			}
		}
	}
	unidirected_graph final_graph(nodi_visitati, final_edges);
	return final_graph;	
}

template<typename T>
unidirected_graph
//BFS -- QUEUE --FIFO
graph_visit(const unidirected_graph graph , const int root_node, FIFO<T> struct_type){
	std::vector<std::list<int>> lista_nodi = lista_adiacenza(graph);
		
	std::set<int> nodi_visitati;
	std::vector<bool> reached(lista_nodi.size(), false);
	std::set<unidirected_edge> final_edges;
		
	struct_type.put(root_node);
	reached[root_node] = true;
	
	while (!struct_type.empty()){
		int u = struct_type.get(); // u = nodo corrente
		nodi_visitati.insert(u);
		
		for (int i : lista_nodi[u]){ //ogni elt i nella lista del nodo u
			if (!reached[i]){// se non è presente in reached allora lo aggiungo
				reached[i]=true;
				struct_type.put(i);
				unidirected_edge edge= {u,i};
				final_edges.insert(edge);
				
			}
		}
	}
	unidirected_graph final_graph(nodi_visitati, final_edges);
	return final_graph;	
}

//funzione ausiliaria per permettere la ricorsione
void dfs_ricorsiva(int u, const std::vector<std::list<int>>& lista_nodi, std::vector<bool>& reached, std::set<int>& nodi_visitati, std::set<unidirected_edge>& final_edges) {
    
    reached[u] = true;
    nodi_visitati.insert(u);
    
    for (int i : lista_nodi[u]) {
        if (!reached[i]) {
            final_edges.insert(unidirected_edge(u, i));
            dfs_ricorsiva(i, lista_nodi, reached, nodi_visitati, final_edges);
        }
    }
}

unidirected_graph recurvise_dfs(unidirected_graph graph, int root_node) {
    
    std::vector<std::list<int>> lista_nodi = lista_adiacenza(graph);
    std::set<int> nodi_visitati;
    std::set<unidirected_edge> final_edges;
    std::vector<bool> reached(lista_nodi.size(), false);
    
    dfs_ricorsiva(root_node, lista_nodi, reached, nodi_visitati, final_edges);
	
    return unidirected_graph(nodi_visitati, final_edges);
} 

template<typename T>
unidirected_graph //suppongo pesi tutti uguali a 1
dijkstra(const unidirected_graph graph, const int root_node, FIFO<T> struct_type){
	std::vector<std::list<int>> lista_nodi = lista_adiacenza(graph);
	int n = lista_nodi.size();
	
	std::vector<int> pred(n); //predecessori
	std::vector<int> dist(n-1); //distanze
	
	std::set<int> nodi_visitati;
    std::set<unidirected_edge> final_edges;
	
	for(int i=0; i<n; i++){
		pred[i]=-1;
		dist[i]=10000; //per evitare infinito
	}
	
	pred[root_node] =root_node;
	dist[root_node] =0;
	nodi_visitati.insert(root_node);
	struct_type.put(root_node);
	
	while(!struct_type.empty()){
		int u = struct_type.get();
		for(int w : lista_nodi[u]){
			if (dist[w]> dist[u]+1){
				dist[w] = dist[u]+1; //essendo tutti i pesi uguali a 1
				pred[w] =u;
				
				nodi_visitati.insert(w);
                unidirected_edge edge(u, w);
                final_edges.insert(edge);
				struct_type.put(w); 
			}
		}
	}
	unidirected_graph final_graph(nodi_visitati, final_edges);
    return final_graph;
}

