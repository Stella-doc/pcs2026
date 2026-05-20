//LIFO
#pragma once
#include <iostream>
#include <stack>

template<typename T>
class LIFO{
	std::stack<T> data;
	
	public:
			LIFO() {} ;
		void put(const T& value){
			data.push(value);
		}
		
		T get(){
			T value = data.top();
			data.pop();
			return value;
		}
		
		bool empty() const{
			return data.empty(); //condizione che definisce true o false
		}
		
};
