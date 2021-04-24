
#include <iostream>
using namespace std;

#include "Mono.hpp"
#include "Poli.hpp"


int main() {
	cout << "runrunrun\n\n";
    Mono m(3,4);
    Mono n(2,2);
    Mono o(-1,0);
    cout << m << " * " << n << " = " << m*n << "\n";

    Poli p;
    p.addMono(m);
    p.addMono(n);
    p.addMono(o);
    cout << p;


	return 0;
}
