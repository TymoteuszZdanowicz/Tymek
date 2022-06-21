#include "Results.h"

Results::Results(double otrzymanePunkty, time_t czasPocz, time_t czasKonc){
	this->otrzymanePunkty = otrzymanePunkty;
	this->czasPocz = czasPocz;
	this->czasKonc = czasKonc;
}
void Results::zliczPunkty(double sumaPunktow) {
	cout << "Uzyskane punkty:" << endl << otrzymanePunkty << "/" << sumaPunktow << endl << (otrzymanePunkty / sumaPunktow) * 100 << "%" << endl;
}
void Results::zliczCzas() {
	cout << "Czas pisania: " << czasKonc - czasPocz << " sekund" << endl;
}
