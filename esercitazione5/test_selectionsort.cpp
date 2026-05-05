//test selection sort
#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_functions.h"
#include "randfiller.h"

int test_selectionsort() {
    randfiller rf;
    std::vector<int> v;
    int size = 1;

    for (int i = 0; i < 100; i++) {
        size = rand() % 100 + 2;
        v.resize(size); 
        rf.fill(v, -100, 100); 
        selection_sort(v); 
        if (!std::is_sorted(v.begin(), v.end())) 
            return EXIT_FAILURE; 
    }

   
    std::vector<std::string> vs = {"ciao", "polipo", "gatto", "si", "luna", "hey", "minimo", "test", "nove", "fiore"};
    selection_sort(vs);
    if (!std::is_sorted(vs.begin(), vs.end()))
        return EXIT_FAILURE; 
	
    return EXIT_SUCCESS; 
}

int main() {
    return test_selectionsort();
}