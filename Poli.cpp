#include <iostream>
#include<algorithm>
using namespace std;

#include "Mono.hpp"
#include "Poli.hpp"

Poli::Poli(){
	Mono st;
	append(st);
}

//definir grau
unsigned int Poli::getDgr(){
	return size();
}

bool Poli::empty(){
	return size();
}

//adicionar monomio
void Poli::addMono(Mono m){
	unsigned int mdgr = m.getDgr();
	unsigned int pdgr = getDgr();

	if (mdgr<=pdgr){
		double updCoef = fetch(mdgr).getCoef() + m.getCoef();
		Mono updMono(updCoef, mdgr);
		insert(updMono, mdgr);
	}else{
		for(unsigned int i=pdgr+1; i<mdgr; i++){
			Mono zero;
			append(zero);
		}
		append(m);
	}
}

Poli Poli::operator-(){
	Poli res;
	for(unsigned int i=0; i<this->size(); i++){
		res.addMono(-this->fetch(i));
	}
	return res;
}

Poli Poli::operator+(const Poli* other){
	Poli res;
	for(unsigned int i=0; i<this->size() || i<other->size(); i++){
		res.addMono(this->fetch(i) + other->fetch(i));
	}
	return res;
}

//Poli Poli::operator-(const Poli* other){
//	Poli res;
//	for(unsigned int i=0; i<this->size() || i<other->size(); i++){
//		res.addMono(this->fetch(i) + other->fetch(i));
//	}
//	return res;
//}

Poli Poli::operator*(const Poli* other){
	Poli res;

	return res;
}

ostream& operator<<(ostream& os, const Poli& p){
	cout << "here\n" << p.fetch(0);
	string s = "";
	for(unsigned int i=0; i<p.size(); i++){
		s += p.fetch(i).getString();
	}
    os << s;
    return os;
}
