// classe grafi
#include <iostream>
#include <set>
#include <stdexcept>
#include "unidirected_edge.hpp"

class unidirected_graph {
	
	std::set<int> nodes;
	std::set<unidirected_edge> edges;
	
	public:
		unidirected_graph(std::set<int> nodes_, std::set<unidirected_edge> edges_){
			nodes = nodes_;
			edges = edges_;
		
			std::set<int> connected_nodes;
			for(auto edge:edges_){
				connected_nodes.insert(edge.from());
				connected_nodes.insert(edge.to());
				
				nodes.insert(edge.from());
				nodes.insert(edge.to());
			}
			
			for (auto node:nodes_){
				if (!connected_nodes.contains(node)){
					unidirected_edge edge(node, node);
					edges.insert(edge);
				}
			}
		};
		//solo nodi: tutti nodi collegati a se stessi
		unidirected_graph(std::set<int> nodes_){
			nodes = nodes_;
			for (auto node: nodes){
				unidirected_edge edge(node, node);
				edges.insert(edge);
			}
		}
		//solo archi: inserisco i nodi con un ciclo
		unidirected_graph(std::set<unidirected_edge> edges_){
			edges = edges_;
			for (auto edge: edges){
				int node1 = edge.from();
				int node2 = edge.to();
				nodes.insert(node1);
				nodes.insert(node2);
			}
		}
		
	//operatore di uguaglianza per i test
		bool operator==(const unidirected_graph& other) const{
			if (edges == other.edges){
				return true;
			}
			else {
				return false;
			}
		}
	
	//costruttore di copia
		unidirected_graph(const unidirected_graph& other){
			nodes = other.nodes;
			edges = other.edges;
		};
	
	//nodi vicini
		std::set<int>
		neighbours(int node){
			std::set<int> neighbours;
			for (auto edge: edges){
				if (node == edge.from()){
					neighbours.insert(edge.to());
				}
				if (node == edge.to()){
					neighbours.insert(edge.from());
				}
			}
		return neighbours;
		}
		
	//aggiungere arco al grafo
		void
		add_edge(int node_from, int node_to){
			unidirected_edge edge(node_from, node_to);
			edges.insert(edge);
			if (!nodes.contains(node_from)){
				nodes.insert(node_from);
			}
			if (!nodes.contains(node_to)){
				nodes.insert(node_to);
			}
		}
	
	//restituisce gli archi
		std::set<unidirected_edge> 
		all_edges(){
			return edges;
		}
		
	//restutuisce i nod
		std::set<int>
		all_nodes(){
			return nodes;
		}
		
	//restituzione numerazione arco in grafo
		int
		edge_number(unidirected_edge target_edge){
			int k=0;
			for (auto edge: edges){
				if (target_edge == edge){
					return k;
				}
				else{
					k=k+1;
				}
			}
		throw std::out_of_range("Arco non presente nel grafo");;
		}
		
		unidirected_edge
		edge_at(int k){
			int i=0;
			for(auto edge: edges){
				if (i==k){
					return edge;
				}
				else{
					i=i+1;
				}
			}
		throw std::out_of_range("Indice fuori dai limiti");
		}
		
		unidirected_graph operator-(const unidirected_graph other){
			std::set<unidirected_edge> difference;
			for (auto edge: edges){
				if (!other.edges.contains(edge)){ //se arco di G NON (!) è in G', allora aggiungo al set difference
					difference.insert(edge);
				}
			}
			return unidirected_graph(difference);
			
		}
};