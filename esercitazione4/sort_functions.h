//sort function

//bubble sort
#include <optional>
#include <vector>
#include <cmath>
#include <algorithm>

template<typename T>
std::vector<T>
bubble_sort(std::vector<T>& v){
	if (v.size()<2){
		return v;
	}
	
	else{
		for (size_t i=0; i<v.size()-1; i++){
			for (size_t j=0; j< v.size() -i-1; j++){ //can't write v.size()<j<i
				if (v[j+1]<v[j]) {
					std::swap(v[j+1],v[j]);
				}
			}
		}
		
		return v;
	}
}

//insertion sort
template<typename T>
std::vector<T>
insertion_sort(std::vector<T>& v){
	if (v.size()<2){
		return v;
	}
	
	else{
		for (size_t j=1; j<v.size(); j++){
			T key = v[j];
			int i=j-1;
			while (i>=0 && v[i]>key) {
				v[i+1]=v[i];
				i=i-1;
			}
			v[i+1]=key;
		}
		return v;
	}
}

//selection sort
template<typename T>
std::vector<T>
selection_sort(std::vector<T>& v){
	if (v.size()<2){
		return v;
	}
	
	else{
		for (size_t i=0; i<v.size()-1; i++) {
			int min = i;
			for (size_t j=i+1; j<v.size(); j++){
				if (v[j]<v[min]) {
					min = j;
				}
			}
			std::swap(v[i],v[min]);
		}
		return v;
	}
}
