
using namespace std;

#include "Mon.h"


//Construtor
Mon::Mon(){
	gr= 0;
	coef=0;
}

Mon::Mon(int _gr, double _coef){
	gr = _gr;
	coef = _coef;
}
//atribuir grau e coeficiente
//void Mon::def(int g, double c){
//		if (g<0){
//			cout<<"Introduziu grau negativo";
//
//		}
//		else{
//			coef=c;
//			gr=g;
//		}
//}
void Mon::setCoef(double _coef){
	coef = _coef;
}

void Mon::setGr(int _gr){
	gr = _gr;
}

//obter coeficiente
double Mon::getCoef() const{
	return coef;
}
//obter grau
int Mon::getGr() const{
		return gr;
}

string Mon::getString() const{
	//temp sol - int cast
	string scoef = to_string((int)coef);
	string sgr = "x^" + to_string(gr);

	if(gr==1){
		sgr = "x";
	}
	if(coef<2){
		scoef.clear();
	}
	if(coef==0 || gr==0){
		sgr.clear();
	}

	return scoef + sgr;
}

ostream& operator<<(ostream& os, const Mon& m){
    os << m.getString();
    return os;
}



