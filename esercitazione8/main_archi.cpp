//main archi
#include <iostream>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

int main(void){
	unidirected_edge edge(5,4);
	unidirected_edge edge1(0,3);
	std::cout<<edge<<"\n"<< edge1<< "\n";
	return 0;
}