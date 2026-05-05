//test merge sort
#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_functions.h"
#include "randfiller.h"

int test_mergesort() {
    randfiller rf;
    std::vector<int> v;
    int size = 1;

    for (int i = 0; i < 100; i++) {
        size = rand() % 100 + 2;
        v.resize(size); 
        rf.fill(v, -100, 100); 
        if (v.size()>1){
			merge_sort(v, 0, v.size()-1);
		} 
		
        if (!std::is_sorted(v.begin(), v.end())) 
            return EXIT_FAILURE; 
    }

   
    std::vector<std::string> vs = {"ciao", "polipo", "gatto", "si", "luna", "hey", "minimo", "test", "nove", "fiore"};
    merge_sort(vs, 0, vs.size()-1);
    if (!std::is_sorted(vs.begin(), vs.end()))
        return EXIT_FAILURE; 
	
    return EXIT_SUCCESS; 
}

int main() {
    return test_mergesort();
}

