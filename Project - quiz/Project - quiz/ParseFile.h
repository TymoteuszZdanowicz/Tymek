#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Question.h"

using namespace std;

class ParseFile {
public:
	vector<Question> pytania;
	string tresc;
	map<char, string> odpowiedzi;
	double punkty;
	char poprawna;

	string pytanie = "Pytanie";
	string odp = "Odp";
	string linijka, trescOdp, tempPunkty;

	int counter = 0;
	double sumaPunktow = 0;
	int iloscPytan;

	void odczytDanych(string fileName);
};

