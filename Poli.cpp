#include <iostream>
#include<algorithm>
using namespace std;

#include "Mon.h"
#include "Poli.h"

//Contrutor
Poli::Poli(){
	graumax = 0;
}
//definir grau
void Poli::atgrau(int g){
	graumax = g;
}
//adicionar monomio
void Poli::admono(int z, double w){
	Mon u(z,w);
	this->L.ins_nL(u);
}

//criar polinomio
void Poli::cria(int grau){
	int pos=0;
	double a;
//Mono m;
	while(pos<=grau){
		cout<< "Coeficiente a"<<pos<<":";
		cin>>a;
		admono(pos,a);
		pos++;
	}
	atgrau(grau);

}

//soma polinomios
Poli Poli::add(Poli p1, Poli p2){
	int ng=max((&p1)->graumax, (&p2)->graumax);//grau do polinomio resultante
	int aux1=0;
	int aux=0;
	double aux2=0;
	Mon m;
	Poli p3;
	while(aux<=ng){
		if( aux1>((&p1)->graumax)){//caso p2 tenha grau superior a p1
			aux2=(&p2)->L.ver_nLe(aux1).getCoef();
			p3.admono(aux1,aux2);
		}
		else if (aux1>((&p2)->graumax)){//caso p1 tenha grau superior a p2
			aux2=(&p1)->L.ver_nLe(aux1).getCoef();
			p3.admono(aux1,aux2);
		}
		else{
			aux2=((&p1)->L.ver_nLe(aux1).getCoef())+ ((&p2)->L.ver_nLe(aux1).getCoef());
			p3.admono(aux1,aux2);
		}
		aux1++;
	}
	p3.atgrau(ng);
	return p3;
}

//subtra��o
Poli Poli::sub(Poli p1, Poli p2){
	int ng=max((&p1)->graumax, (&p2)->graumax);//grau do polinomio resultante
	int aux=0;
	int aux1=0;
	double aux2=0;
	Mon m;
	Poli p3;
	while(aux<=ng){
		if( aux1>((&p1)->graumax)){//caso p2 tenha grau superior a p1
			aux2=(&p2)->L.ver_nLe(aux1).getCoef();
			aux2=(-1)*aux2;//como e p1-p2, coef de p2 inverte sinal
			p3.admono(aux1,aux2);
		}
		else if (aux1>((&p2)->graumax)){//caso p1 tenha grau superior a p2
			aux2=(&p1)->L.ver_nLe(aux1).getCoef();
			p3.admono(aux1,aux2);
		}
		else{
			aux2=((&p1)->L.ver_nLe(aux1).getCoef())- ((&p2)->L.ver_nLe(aux1).getCoef());
			p3.admono(aux1,aux2);
		}
		aux1++;
	}
	p3.atgrau(ng);
	return p3;
}

Poli Poli::prod(Poli p1, Poli p2){
	int ng=((&p1)->graumax)+((&p2)->graumax);
	double coefs[ng];
	int aux1=0;
	int aux2=0;
	int aux3=0;
	int n1=(&p1)->graumax;
	int n2=(&p2)->graumax;
	double c1;
	double c2;
	Poli p3;
	while(aux1<=n1){
		c1=(&p1)->L.ver_nLe(aux1).getCoef();
		while(aux2<=n2){
			c2=(&p2)->L.ver_nLe(aux2).getCoef();
			coefs[aux1+aux2]+=c1*c2;
			aux2++;
		}
		aux1++;
		aux2=0;
	}
	while(aux3<=ng){
		p3.admono(aux3, coefs[aux3]);
		aux3++;
	}
	return p3;

}

void Poli::ver(){
	int g1=graumax;
	int aux=0;
	cout<<"Polinomio resultante: ";
	while(aux<=g1){
		cout<< L.ver_nLe(aux).getCoef()<<"*x^("<<aux<<")+";
		aux++;
	}
}

