//sort function

//bubble sort
#include <optional>
#include <vector>
#include <cmath>
#include <algorithm>


template<typename T> //function to print vector
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

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
void
insertion_sort(std::vector<T>& v){
	if (v.size()<2){
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

//fusion (merge)
template<typename T>
void 
fusion(std::vector<T>& v, size_t p, size_t q, size_t r) {
    
    size_t n1=q-p+1;
    size_t n2= r-q;

    std::vector<T> L(n1); 
    std::vector<T> R(n2);

    for (size_t i =0; i<n1; i++){
		L[i]=v[p+i];
	}
        
    for (size_t j= 0; j<n2; j++){
        R[j] = v[q+j+1];
	}
	
    size_t i = 0;
    size_t j = 0; 
    size_t k = p; 
	
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
		else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
	//se rimangono elt da un lato o dall'altro li copia e basta
    while (i < n1) v[k++]=L[i++];
    while (j < n2) v[k++]=R[j++];
}

//merge sort
template<typename T>
void 
merge_sort(std::vector<T>& v, size_t sx, size_t dx) {
    
    if (sx < dx) {
        size_t center = sx + (dx - sx) / 2;
        merge_sort(v, sx, center);
        merge_sort(v, center + 1, dx);
        fusion(v, sx, center, dx);
    }
}

//partition
template<typename T>
int
partition(std::vector<T>& v, int p, int r){
	T x=v[r];
	int i=p-1;
	for (int j=p; j<=r-1; j++){
		if (v[j]<=x) {
			i=i+1;
			std::swap(v[i],v[j]);
		}
	}
	std::swap(v[i+1], v[r]);
	return i+1;
}

//quick sort
template<typename T>
void
quick_sort(std::vector<T>& v, int p, int r){ //con size_t da segmentation fault
	
	if (p<r) {
		int q=partition(v,p,r);
		quick_sort(v,p,q-1);
		quick_sort(v,q+1,r);
	}
}
