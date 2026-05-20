//algoritmi di ricerca per grafi
#include <iostream>
#include <list>
#include "graph_visit.h"
#include <set>

std::set<int> nodes = {1,2,3,4,5,6,7,8,9};
std::set<unidirected_edge> edges = {{1,2},{1,3},{1,4},{1,6},{2,4},{2,5},{2,7},{3,6},{4,6},{4,7},{5,7},{6,7},{6,8},{7,9},{8,9}};
int root_node = *nodes.begin(); //uso questo perchè so già che il primo elemento è il root node che voglio
unidirected_graph g(nodes, edges); //ASTERISCO PER DEFERENZIARE E PRENDERE IL VALORE

LIFO<int> stack;
FIFO<int> queue;
std::set<unidirected_edge> bfs_edges = {{1,2},{1,3},{1,4},{1,6},{2,5},{2,7},{7,9},{6,8}};
std::set<unidirected_edge> dfs_edges = {{1,2},{1,3},{1,4},{1,6},{6,7},{5,7},{6,8},{8,9}};


int main(void){
//dfs	
	unidirected_graph graph1 = graph_visit(g, root_node, stack);
	std::set<unidirected_edge> archi_dfs= graph1.all_edges();
	if (archi_dfs == dfs_edges){
		std::cout<< "ok dfs"<< "\n";
	}
	else {
		std::cout<< "errore dfs"<< "\n";
	}
	
	for ( auto edge : archi_dfs) {
    std::cout << edge << " "; 
	}
	std::cout << "\n";

//bfs	
	unidirected_graph graph2= graph_visit(g, root_node, queue);
	std::set<unidirected_edge> archi_bfs = graph2.all_edges();
	if (archi_bfs == bfs_edges){
		std::cout<< "ok bfs"<< "\n";
	}
	else {
		std::cout<< "errore bfs"<< "\n";
	} 
	
	for ( auto edge : archi_bfs) {
    std::cout << edge << " "; 
	}
	std::cout << "\n";
	
 //recursive dfs	
	unidirected_graph graph3 = graph_visit(g, root_node, stack);
	std::set<unidirected_edge> archi_recursivedfs= graph3.all_edges();
	if (archi_recursivedfs == dfs_edges){
		std::cout<< "ok recursive dfs"<< "\n";
	}
	else {
		std::cout<< "errore recursive dfs"<< "\n";
	}
	
	for ( auto edge : archi_recursivedfs) {
    std::cout << edge << " "; 
	}
	std::cout << "\n"; 
	
//dijkstra	
	unidirected_graph graph4= dijkstra(g, root_node, queue);
	std::set<unidirected_edge> archi_dij = graph4.all_edges();
	if (archi_dij == bfs_edges){ //avendo pesi uguali a 1 è equivalente al bfs
		std::cout<< "ok dij"<< "\n";
	}
	else {
		std::cout<< "errore dij"<< "\n";
	} 
	
	for ( auto edge : archi_dij) {
    std::cout << edge << " "; 
	}
	std::cout << "\n";
	return 0;
}




