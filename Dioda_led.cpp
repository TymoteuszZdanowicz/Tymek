#include <iostream>
#include "Dioda_led.h"

using namespace std;

Dioda_led::Dioda_led(double _Uf, double _If, kolory _kolor, double _R) :Dioda(_Uf, _If), Kolor(_kolor), Rezystor(_R) {
	cout << "Konstruktor dioda led" << endl;
}

Dioda_led::~Dioda_led(){
	cout << "Destruktor dioda led" << endl;
}

void Dioda_led::stan(double _Uzas) {
	if (Dioda::stan(_Uzas)) {
		cout << "Swieci" << endl;
		Rezystor::stan(_Uzas);
	}
	else {
		cout << "Nie swieci" << endl;
	}
}