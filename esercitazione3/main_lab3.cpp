#include <iostream>
#include "razionali_lab3.hpp"

int main(void)
{ 
	rational<int> r1(8,7);
	rational<int> r2(1,3);
	rational<int> r3 = r1+r2;
	rational<int> r4=r1-r2;
	rational<int> r5=r1*r2;
	rational<int> r6=r1/r2;
	std::cout<< r3<< "\n"<<r4<<"\n"<<r5<<"\n"<<r6<<"\n"; 
	return 0;
}

// per fare le prove definisco tanti r(a,b) poi applicare le varie operazioni definite nell'hpp

//per eseguire: g++ -std=c++20 main_lab3.cpp -o prog

