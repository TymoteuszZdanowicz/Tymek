#pragma once
#include "Dioda.h"
#include "Kolor.h"
#include "Rezystor.h"

class Dioda_led: virtual Rezystor, Dioda, Kolor {
public:
	Dioda_led(double _Uf, double _If, kolory _kolor, double _R);
	~Dioda_led();

	void stan(double _Uzas);
};