//measure sort 
#include <iostream>
#include <algorithm>
#include <vector>
#include "timecounter.h"
#include "sort_functions.h"
#include "randfiller.h"
#include "is_sorted.h"


int main(void){
	timecounter timer;
	randfiller rf;
	
	double total1 = 0.0;
    double total2 = 0.0;
    double total3 = 0.0;
    double total4 = 0.0;
	
	std::vector<int> dim(100); //dim = 700 bubble sort quasi 8 secondi
    for (size_t i = 0; i < dim.size(); ++i) {
		dim[i] = (i + 1) * 4;
	}
	
	for (size_t t=1; t<dim.size(); t++){
	
		std::vector<int> v;
		v.resize(dim[t]);
		rf.fill(v, -100, 100);
	
		if (is_sorted(v) && t % 4==0) { 
			timer.tic();
			bubble_sort(v);
			total1+=timer.toc();
		}
	}
	
	for (size_t t=1; t<dim.size(); t++){
	
		std::vector<int> v;
		v.resize(dim[t]);
		rf.fill(v, -100, 100);
	
		if (is_sorted(v) && t% 4==0) { 
			timer.tic();
			insertion_sort(v);
			total2+= timer.toc();
		}
	}
	
	for (size_t t=1; t<dim.size(); t++){
	
		std::vector<int> v;
		v.resize(dim[t]);
		rf.fill(v, -100, 100);
	
		if (is_sorted(v) && t % 4==0) { 
			timer.tic();
			selection_sort(v);
			total3 += timer.toc();
		}
	}
	
	for (size_t t=1; t<dim.size(); t++){
	
		std::vector<int> v;
		v.resize(dim[t]);
		rf.fill(v, -100, 100);
	
		if (is_sorted(v) && t%4==0) { 
			timer.tic();
			std::sort(v.begin(), v.end());
			total4 += timer.toc();
		}
	}
	
	std::cout<< "bubble sort: " << total1 << "\n";
	std::cout<< "insertion sort: "<< total2 << "\n";
	std::cout<< "selection sort: "<< total3<< "\n";
	std::cout<< "sort: "<< total4<<"\n";
	return EXIT_SUCCESS;
}

