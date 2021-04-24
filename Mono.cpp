
using namespace std;

#include "Mono.hpp"


//Construtor
Mono::Mono(){
	dgr = 0;
	coef = 0;
}

Mono::Mono(double _coef, unsigned int _dgr){
	coef = _coef;
	dgr = _dgr;
}

void Mono::setCoef(double _coef){
	coef = _coef;
}

void Mono::setDgr(unsigned int _dgr){
	dgr = _dgr;
}

//obter coeficiente
double Mono::getCoef() const{
	return coef;
}
//obter grau
unsigned int Mono::getDgr() const{
	return dgr;
}

string Mono::getString() const{
	//temp sol - int cast
	string scoef = to_string((unsigned int)coef);
	string sdgr = "x^" + to_string(dgr);

	if(dgr==1){
		sdgr = "x";
	}
	if(coef<2){
		scoef.clear();
	}
	if(coef==0 || dgr==0){
		sdgr.clear();
	}

	return scoef + sdgr;
}

bool Mono::empty(){
	return coef;
}

Mono Mono::operator-(){
	return Mono(-this->coef, this->dgr);
}

Mono Mono::operator+(const Mono& other){
	return Mono(this->coef + other.coef, this->dgr);
}

//Mono Mono::operator-(const Mono& other){
//	return Mono(this->coef + other.coef, this->dgr);
//}

Mono Mono::operator*(const Mono& other){
	return Mono(this->coef * other.coef, this->dgr + other.dgr);
}

ostream& operator<<(ostream& os, const Mono& m){
    os << m.getString();
    return os;
}



