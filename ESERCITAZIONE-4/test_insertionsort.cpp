//test insertion_sort
#include <iostream>
#include <vector>
#include "is_sorted.h"
#include "sort_functions.h"
#include "randfiller.h"
#include <algorithm>

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
    rf.fill(dim, 0, 50);
	
	for (size_t t=1; t<dim.size(); t++){
	
		std::vector<int> v;
		v.resize(dim[t]);
		rf.fill(v, -100, 100);
		std::cout<< "-------------------------------------------"<< "\n";
		print_vector(v);
	
		if (is_sorted(v)) { 
			std::cout<<"vettore non ordinato"<<"\n";
			insertion_sort(v);
			print_vector(v);
		}
		
		else {
			std::cout<<"vettore ordinato"<<"\n";
		}
	}	
	
	std::vector<std::string> str_v ={"delta", "foxtrot", "charlie", "echo", "bravo", "alpha"};
	print_vector(str_v);
	insertion_sort(str_v);
	print_vector(str_v);
	
	return EXIT_SUCCESS;
}
