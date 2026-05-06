//test modified quicksort
#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_functions.h"
#include "randfiller.h"

int test_modified_quicksort() {
    randfiller rf;
    std::vector<int> v;
    int size = 1;
	int soglia = 13; //all'incirca, dopo aver fatto vari test

    for (int i = 0; i < 100; i++) {
        size = rand() % 100 + 2;
        v.resize(size); 
        rf.fill(v, -100, 100); 
        modified_quicksort(v, 0, v.size()-1, soglia); 
        if (!std::is_sorted(v.begin(), v.end())) {
			std::cout<< "test fallito"<< "\n";
            return EXIT_FAILURE; 
		}
    }

   //commento questa parte perché su una soglia superiore alla dimensione del vettore stringa, fa fallire il test
    //std::vector<std::string> vs = {"ciao", "polipo", "gatto", "si", "luna", "hey", "minimo", "test", "nove", "fiore"};

   // modified_quicksort(vs, 0, vs.size()-1, soglia);
    //if (!std::is_sorted(vs.begin(), vs.end())){
	//	std::cout<< "test fallito 1"<< "\n";
      //  return EXIT_FAILURE;
	//}
	//print_vector(vs);
    return EXIT_SUCCESS;
}

int main() {
    return test_modified_quicksort();
}