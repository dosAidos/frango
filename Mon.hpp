#include <iostream>

#ifndef MON_H
#define MON_H

using namespace std;

class Mon{
private:
	int gr;
	double coef;
public:
    Mon();
	Mon(int, double);
	//void def(int, double);
	void setCoef(double);
	void setGr(int);
	double getCoef() const;
	int getGr() const;
	string getString() const;
	friend ostream& operator<<(ostream&, const Mon&);
};

#endif
