//test insertion_sort
#include <iostream>
#include <vector>
#include "is_sorted.h"
#include "sort_functions.h"
#include "randfiller.h"
#include <algorithm>

int test_insertionsort() {
    randfiller rf;
    std::vector<int> v;
    int size = 1;

    for (int i = 0; i < 100; i++) {
        size = rand() % 100 + 2;
        v.resize(size); 
        rf.fill(v, -100, 100); 
        insertion_sort(v); 
        if (!std::is_sorted(v.begin(), v.end())) 
            return EXIT_FAILURE; 
    }

    std::vector<std::string> vs = { "ciao", "polipo", "gatto", "si", "luna", "hey", "minimo", "test", "nove", "fiore"};
    insertion_sort(vs);
    if (!std::is_sorted(vs.begin(), vs.end()))
        return EXIT_FAILURE; 
    return EXIT_SUCCESS; 
}

int main() {
    return test_insertionsort();
}

