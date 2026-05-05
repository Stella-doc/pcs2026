//prova esercitazione4
#include <iostream>
#include <vector>
#include <optional>
#include "randfiller.h"
#include "is_sorted.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"

template<typename T> //function to print vector
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(void) {
	randfiller rf;
	
    std::vector<int> dim; //vector of casual dimension
    dim.resize(100);
    rf.fill(dim, 3, 50); 
	
	for (int t=1; t<dim.size(); t++){
	
		std::vector<int> v;
		v.resize(dim[t]);
		rf.fill(v, 0, 100);
		
		print_vector(v);
	
		if (is_sorted(v)) { //is_sorted restituisce vuoto se è ordinato, vuoto = falso | restituisce un valore se non è ordinato, valore = vero 
			std::cout<<"vettore non ordinato"<<"\n";
			bubble_sort(v);
			print_vector(v);
			insertion_sort(v);
			print_vector(v);
			selection_sort(v);
			print_vector(v);
		}
		else {
			std::cout<<"vettore ordinato"<<"\n";
		}
	}	
	return EXIT_SUCCESS;
}