#include <iostream>
#include <algorithm>

#include "Mon.hpp"
#include "tadLista.hpp"

#ifndef POLI_H
#define POLI_H

using namespace std;

class Poli{
private:
	int graumax;
	tadLista<Mon> L;
public:
    Poli();
	void atgrau(int);
	void admono(int, double);
	void cria(int);
	Poli add(Poli, Poli);
	Poli sub(Poli, Poli);
	Poli prod(Poli, Poli);
	void ver();
};
#endif
