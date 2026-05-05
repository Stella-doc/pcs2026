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
	double total5 = 0.0;
	double total6 = 0.0;
	
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
		merge_sort(v,0, v.size()-1);
		total4 += timer.toc();
			
		v=vec[i];
		timer.tic();
		quick_sort(v,0, v.size()-1);
		total5+=timer.toc();
			
		v=vec[i];
		timer.tic();
		std::sort(v.begin(), v.end());
		total6 += timer.toc();
		
	}
	
	double avg1 = total1/100;
	double avg2 = total2/100;
	double avg3 = total3/100;
	double avg4 = total4/100;
	double avg5 = total5/100;
	double avg6 = total6/100;
	
	std::cout<< "bubble sort: " << avg1 << "\n";
	std::cout<< "insertion sort: "<< avg2 << "\n";
	std::cout<< "selection sort: "<< avg3 << "\n";
	std::cout<< "merge sort: "<< avg4 <<"\n";
	std::cout<< "quick sort: "<< avg5 <<"\n";
	std::cout<< "sort: "<< avg6 <<"\n";
	
	return {};
 }

int trova_soglia(void){
	timecounter timer;
	randfiller rf;
	std::vector<std::vector<int>> vec1(100); 
	
	for (int i=0; i<100; i++){ //creo dei vettori più grandi per le soglie
		vec1[i].resize(i);
		rf.fill(vec1[i], -1000, 1000);
	}
	
	for (int i=2; i<100; i++){
		double t_insertion=0.0;
		double t_quick=0.0;
		
		for (int k=0; k<500; k++){ //ripeto i test più volte per evitare che si pianti alla prima volta che la condizione è verificata
			//faccio in modo di trovare una media della soglia
            std::vector<int> v1 = vec1[i];
            timer.tic();
			insertion_sort(v1); 
            t_insertion += timer.toc(); //misuro i tempi per ogni lunghezza di vettore resettando il timer
        
            v1 = vec1[i];
            timer.tic();
            quick_sort(v1, 0, v1.size() - 1);
            t_quick += timer.toc();
        }

        if (t_quick/100 < t_insertion/100) {
            int soglia = i;
            std::cout << "Soglia: " << soglia << "\n"; 
            break; 
        }
    }
    
    return EXIT_SUCCESS;
}	
	
int main(){
	measure_sort(); 
	trova_soglia();
	return {};
}

