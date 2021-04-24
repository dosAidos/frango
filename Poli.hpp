#include <iostream>
#include <algorithm>

#include "LinkedList.hpp"
#include "Mono.hpp"

#ifndef POLI_H
#define POLI_H

using namespace std;

class Poli: public LinkedList<Mono>{
public:
	Poli();
	unsigned int getDgr();
	bool empty();
	void addMono(Mono m);
	Poli operator-();
	Poli operator+(const Poli* other);
//	Poli operator-(const Poli* other);
	Poli operator*(const Poli* other);
	friend ostream& operator<<(ostream& os, const Poli& p);
};
#endif
