#include <iostream>
#include "Dioda.h"

using namespace std;

Dioda::Dioda() {
	Uf = 0;
	If = 0;
}
Dioda::Dioda(double _Uf, double _If) {
	Uf = _Uf;
	If = _If;
}
Dioda::~Dioda() { cout << "Destruktor dioda" << endl; }
double Dioda::odczytaj_Uf() { return Uf; }
double Dioda::odczytaj_If() { return If; }
bool Dioda::stan(double _Uzas) {
	if (_Uzas > Uf) { return true; }
	else { return false; }
}

