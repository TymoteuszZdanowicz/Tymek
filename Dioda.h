#pragma once
#include "Dioda_led.h"

class Dioda {
private:
	double Uf, If;
public:
	Dioda();
	Dioda(double _Uf, double _If);
	~Dioda();

	double odczytaj_Uf(void);
	double odczytaj_If(void);
	bool stan(double _Uzas);
};