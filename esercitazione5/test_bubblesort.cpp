//test bubble_sort
#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_functions.h"
#include "randfiller.h"

int test_bubblesort() {
    randfiller rf;
    std::vector<int> v;
    int size = 1;

    // Giro 100 volte
    for (int i = 0; i < 100; i++) {
        size = rand() % 100 + 2;
        v.resize(size); 
        rf.fill(v, -100, 100); // riempi il vettore casualmente 
        bubble_sort(v); // Chiami la funzione
        if (!std::is_sorted(v.begin(), v.end())) // SE NON è sortato
            return EXIT_FAILURE; // ALLORA ritorna il fallimento del test
    }

    // Test su un vettore di stringhe 
    std::vector<std::string> vs = { "ciao", "polipo", "gatto", "si", "luna", "hey", "minimo", "test", "nove", "fiore"};
    bubble_sort(vs);
    if (!std::is_sorted(vs.begin(), vs.end()))
        return EXIT_FAILURE; // ritorna il fallimento del test in caso di NON sort 

    return EXIT_SUCCESS; // Se arriva qui ritorni successo perché è andato tutto bene
}

int main() {
    return test_bubblesort();
}

