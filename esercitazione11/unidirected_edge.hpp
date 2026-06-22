//undirected_edges = arco in un grafo
//archi ordinati in ordine crescente per enrambi gli elt: se sono uguali quelli della pria parte, mi baso sulla seconda parte
#pragma once
#include <iostream>

class unidirected_edge
{
	int start;
	int end;
	
	public:
		int from() const {
			return start;
		};
		
		int to() const {
			return end;
		};
		
		unidirected_edge(int from, int to){
			if (from > to){
				start = to;
				end = from;
			}
			else{
				start = from;
				end = to;
			}
		};
		
		bool operator<(const unidirected_edge& other) const{
			if (from()<other.from()){
				return true;
			}
			if (other.from()<from()){
				return false;
			}
			if (to()<other.to()){
				return true;
			}
			if (other.to()<to()){
				return false;
			}
			return false;
		}
		
		bool operator==(const unidirected_edge& other) const{
			if (from()==other.from() && to()==other.to()){
				return true;
			}
			return false;
		}
		
};

std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge){
	return os<<edge.from()<< "->"<< edge.to();	
}
