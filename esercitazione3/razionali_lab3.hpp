#include <concepts>
#include <iostream>
#include <numeric>
template<typename I> 
requires std::integral<I>
class rational
{
	I num_;
	I den_;
	bool is_inf=false; //num/0
	bool is_nan=false; // 0/0
	
//this, mi prende ciò che è a sinistra dell'operatore; other quello che ho a destra	
public:
//devo definire delle ulteriori flag per inf e nan da mettere nell'output
	bool is_inf_() const{
		return is_inf;
	};
	//se definisco senza mettere del codice il compilatore le definisce come definizioni non complete
	bool is_nan_() const{
		return is_nan;
	};
	
	rational();
	rational(I num, I den){ 
		num_ = num;
		den_ = den;
		
		if (den_==0 && num_!=0){
			is_inf=true;
		}
		
		if (num_==0 && den_==0){
			is_nan=true;
		}
		
		if (den_<0){
			num_=-num_;
			den_= -den_;
		}	
	};
	
	I num() const{
		return num_;
	}
	
	I den() const{
		return den_;	
	}
	
	void normalize(){ //DEVO DEFINIRE LA FUNZIONE NORMALIzE NEL COSTRUTTORE, ALTRIMENTI IL COMPILATORE NON SA COSA SIA
		if (den_==0)
			return;
		I divisore = std::gcd(num_, den_); //funzione massimo comune divisore, funziona se includo numeric
		num_/=divisore;
		den_/=divisore;
		
		if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
		}
	}
	
//addizione
	rational& operator+=(const rational& other) {
		if (is_nan || other.is_nan) { //casi nan:somma di nan deve dare nan
			return *this;
		}
		
		if (is_inf || other.is_inf){ //casi inf: somma di inf deve fare inf
			return *this;
		}
		
		if (is_inf && other.is_inf){
			return *this;
		}
		
		if (is_nan && other.is_nan){
			return *this;
		}
		
		num_= other.num_*den_ +num_*other.den_; //(a/b)+(c/d)=(ad+bc)/bd
		den_*= other.den_;
		normalize();
		return *this;
	}
	
	
	rational operator+(const rational& other) const {
		rational ret = *this;
		ret+=other;
		return ret;
	}

//moltiplicazione
	rational& operator*=(const rational& other){
		
		if (is_nan || other.is_nan){
			return *this;
		}
		
		if ((is_inf || other.is_inf) && den_==0){
			return *this;
		}
		
		if (is_inf || other.is_inf) {
			if (num_<0||den_<0){
				num_=-num_;
			}
			return *this;
		}
		num_*=other.num_;
		den_*=other.den_;
		normalize();
		return *this;
	}

	rational operator*(const rational& other) const {
		rational ret = *this;
		ret*= other;
		return ret;
	}

//sottrazione	
	rational& operator-=(const rational& other){
		if (is_nan || other.is_nan) { //casi nan:differenze di nana danno nan
			return *this;
		}
		
		if (is_inf || other.is_inf){ //casi inf: differenze di inf danno inf
			return *this;
		}
		num_ = num_*other.den_-other.num_*den_;
		den_ *= other.den_;
		normalize();
		return *this;
	}
	
	rational operator-(const rational& other) const {
		rational ret= *this;
		ret -=other;
		return ret;
	}	

//divisione
	rational& operator/=(const rational& other){
		
		if (is_nan || other.is_nan){
			return *this;
		}
		
		if ((is_inf || other.is_inf) && den_==0){
			return *this;
		}
		
		if (is_inf || other.is_inf) {
			if (num_<0){
				num_=-num_;
			}
			return *this;
		}
		num_*=other.den_;
		den_*=other.num_;
		normalize();
		return *this;
	}
	
	rational operator/(const rational& other) const {
		rational ret = *this;
		ret/=other;
		return ret;
	}
	
};

template<typename I>
requires std::integral<I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r) //dato che implicitamente opeartor prende this come argomento se dentro la classe, l'ho spostato fuori
{
	if(r.is_nan_()){
		os<<"Nan";
	}
	else if (r.is_inf_()){
		os<<"Inf";
	}
	else{
		os<<r.num()<<"/" <<r.den();
	}
	return os;
}
	