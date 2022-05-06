#include <iostream>
#include "Rezystor.h"

using namespace std;

Rezystor::Rezystor() { R = 0; }
Rezystor::Rezystor(double _R) { R = _R; }
Rezystor::~Rezystor() { cout << "Destruktor rezystor" << endl; }

void Rezystor::ustaw(double _R) { R = _R; }
double Rezystor::odczytaj(void) { return R; }
void Rezystor::stan(double _Uzas) {
	cout << R << endl;
}

