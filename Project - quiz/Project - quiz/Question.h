#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Question {
public:
	int byla = 0;
	string tresc;
	map<char, string> odpowiedzi;
	double punkty;
	char poprawna;
	
	// konstruktory
	Question(string tresc, map<char, string> odpowiedzi, double punkty, char poprawna);
	Question();

	// treœæ i mo¿liwe odpowiedzi
	void wyswietlPytanie(int nrPytania);
	void wyswietlOdpowiedzi(int nrPytania);
	int sprawdzOdp(char c);
};
