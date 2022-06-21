#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Question.h"
#include "Interface.h"

using namespace std;

class Results {
public:
	double otrzymanePunkty;
	time_t czasPocz, czasKonc;
	Results(double otrzymanePunkty, time_t czasPocz, time_t czasKonc);
	void zliczPunkty(double sumaPunktow);
	void zliczCzas();
};
