//is_sorted
#include <optional>
#include <vector>

template<typename T>
std::optional<T>
is_sorted(std::vector<T>& vec)
{
	if (vec.size()==0 || vec.size()<2){ //if size<2 i have nothing to compare
		return {};
	}
	
	for (size_t i=1; i<vec.size(); i++){
		if (vec[i-1]>vec[i])
			return vec[i]; //elt not in order
		
	}
	return {};
}

