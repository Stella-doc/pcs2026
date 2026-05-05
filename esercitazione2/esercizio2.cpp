#include <iostream>
#include <math.h>

// minimo, massimo, media, deviazione standard, radice
//potevo farli anche con le funzioni native std::min(), std::max()

static const int N = 10;
double arr[N] ={1,5,6,7,9,8,4,3,2,12};

int main(void){
	double minimo = arr[0];
	for (int i=0; i<N; i++){
		if (arr[i]<minimo){
			minimo = arr[i];
		}
	}
	std::cout<<"minimo = "<< minimo<<"\n";
	
	double massimo = arr[0];
	for (int i=1; i<=N; i++){
		if (arr[i]>massimo){
			massimo = arr[i];
		}
	}
	std::cout<<"massimo = "<<massimo<<"\n";
	
	double somma = 0;
	for (int i=0; i<N; i++){
		somma = arr[i]+somma;
	}
	double media = somma/N;
	std::cout<<"media = "<< media<<"\n";
	
	double arr1[10] = {1,5,6,7,9,8,4,3,2,12};
	for (int i=0; i<N; i++){
		arr1[i]=sqrt(arr1[i]);
		std::cout<<arr1[i]<<"\n";
	}
	double somma1 = 0;
	for (int i=0; i<N; i++){
		double x= arr[i]-media;
		double y=x*x;
		somma1 = somma1+y;
	}
	
	double varianza = somma1/10;
	double dev_standard = sqrt(varianza);
	std::cout<<"deviazione standard = "<<dev_standard<<"\n";

	return 0;
}