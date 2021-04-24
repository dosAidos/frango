#include <iostream>

#ifndef MONO_H
#define MONO_H

using namespace std;

class Mono{
private:
	int dgr;
	double coef;
public:
    Mono();
	Mono(double _coef, unsigned int _dgr);
	void setCoef(double _coef);
	void setDgr(unsigned int _dgr);
	double getCoef() const;
	unsigned int getDgr() const;
	string getString() const;
	bool empty();
	Mono operator-();
	Mono operator+(const Mono& other);
//	Mono operator-(const Mono& other);
	Mono operator*(const Mono& other);
	friend ostream& operator<<(ostream& os, const Mono& m);
};

#endif
