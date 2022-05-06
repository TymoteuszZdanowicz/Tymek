#pragma once
#include "Dioda_led.h"

class Rezystor:Dioda {
private:
	double R;
public:
	Rezystor();
	Rezystor(double _R);
	~Rezystor();

	void ustaw(double _R);
	double odczytaj(void);
	void stan(double _Uzas);
};