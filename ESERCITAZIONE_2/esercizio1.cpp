#include <iostream>
// esadecimali hanno 16 cifre, dal 10 al 14 ho le prime lettere dell'alfabeto
int main()
{
	double ad[4]={0.0,1.1,2.2,3.3};
	float af[8]={0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7};
	int ai[3]={1,2,3};
	
	int x=1;
	float y=1.1;
	
	(&y)[1]=0;
	
	std::cout<<x<<"\n";
	std::cout<<"ad[2] "<<&ad[2]<<"\n";
	std::cout<<"x "<<&x<<"\n";
	std::cout<<"y "<<&y<<"\n";
	std::cout<<"y+1 "<<&y+1<<"\n";
	
	std::cout<<"indirizzo ad ="<<&ad<<"\n";
	std::cout<<"indirizzo af ="<<&af<<"\n";
	std::cout<<"indirizzo ai ="<<&ai<<"\n";
	
	return 0;
}

//140.724.268.119.616=0x7ffcec033640
//0x7ffcec033600=140.724.268.119.552 la sottrazione fa 64, quindi sono 4 byte
