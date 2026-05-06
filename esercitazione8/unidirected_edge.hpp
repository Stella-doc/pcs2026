//undirected_edges = arco in un grafo
//archi ordinati in ordine crescente per enrambi gli elt: se sono uguali quelli della pria parte, mi baso sulla seconda parte

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
			start = from;
			end = to;
		};
		
		bool operator<(const unidirected_edge& other) const{
			if (from() < other.from()){
				return true;
			}
			if (other.from()< from()){
				return false;
			}
			
			if (to()< other.to()){
				return true;
			}
			if(other.to()< to()){
				return false;
			}
			return false;
		}
		
		bool operator==(const unidirected_edge& other) const{
			if (from() == other.from() && to() == other.to()){
				return true;
			}
			else {
				return false;
			}
		}
		
		int operator<<(unidirected_edge& other){
			
		}
};

/* int
std::ostream&
operator<<(std::ostream& os, const unidirected_edge& u) //dato che implicitamente opeartor prende this come argomento se dentro la classe, l'ho spostato fuori
{
	if(from > to){
		os<<"Nodo di partenza minore di quello di arrivo: input non valido";
	}
	return os;
} */