//measure sort 
#include <iostream>
#include <algorithm>
#include <vector>
#include "timecounter.h"
#include "sort_functions.h"
#include "randfiller.h"
#include "is_sorted.h"

 
int measure_sort(void){
	timecounter timer;
	randfiller rf;
	
	double total1 = 0.0;
    double total2 = 0.0;
    double total3 = 0.0;
	double total4 = 0.0;
	
	std::vector<std::vector<int>> vec(100); //vettore di vettori
	
	for (int i=0; i<100; i++){ //riempimento dei vettori
		int size= rand()%100+2;
		vec[i].resize(size);
		rf.fill(vec[i], -100, 100);
	}
	
	for (int i=0; i<100; i++){
		
		std::vector<int> v;

		v= vec[i]; 
		timer.tic();
		v=bubble_sort(v);
		total1+=timer.toc();
			
		v=vec[i];//ripristino del vettore disordinato
		timer.tic();
		insertion_sort(v);
		total2+= timer.toc();
			
		v=vec[i];
		timer.tic();
		v=selection_sort(v);
		total3 += timer.toc();
			
		v=vec[i];
		timer.tic();
		std::sort(v.begin(), v.end());
		total4 += timer.toc();
		
	}
	
	double avg1 = total1/100;
	double avg2 = total2/100;
	double avg3 = total3/100;
	double avg4 = total4/100;
	
	std::cout<< "bubble sort: " << avg1 << "\n";
	std::cout<< "insertion sort: "<< avg2 << "\n";
	std::cout<< "selection sort: "<< avg3 << "\n";
	std::cout<< "sort: "<< avg4 <<"\n";
	
	return {};
 }
 
 int main(){
	 return measure_sort();
 }

