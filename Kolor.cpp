#include <iostream>
#include "Kolor.h"

using namespace std;

Kolor::Kolor(kolory _jaki_kolor) { jaki_kolor = _jaki_kolor; }
Kolor::~Kolor() { cout << "Destruktor kolor" << endl; }
void Kolor::ustaw(kolory _jaki_kolor) { jaki_kolor = _jaki_kolor; }
kolory Kolor::odczytaj() { return jaki_kolor; }