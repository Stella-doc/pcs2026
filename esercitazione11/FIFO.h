//FIFO
#include <iostream>
#include <queue>
#pragma once

template<typename T>
class FIFO{
	std::queue<T> data;
	
	public:
			FIFO() {};
		void put(const T& value){	
			data.push(value);
		}
		
		T get(){
			T value = data.front();
			data.pop();
			return value;
		}
		
		bool empty() const{
			return (data.empty());
		}
};