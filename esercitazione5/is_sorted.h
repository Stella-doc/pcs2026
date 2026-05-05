//is_sorted
#include <optional>
#include <vector>
#include <algorithm>

template<typename T>
bool
is_sorted(std::vector<T>& vec)
{
	return std::is_sorted(vec.begin(), vec.end());
	/* if (vec.size()==0 || vec.size()<2){ //if size<2 i have nothing to compare
		return {};
	}
	
	for (size_t i=1; i<vec.size(); i++){
		if (vec[i-1]>vec[i])
			return vec[i]; //elt not in order
		
	}
	return true; // */
}

