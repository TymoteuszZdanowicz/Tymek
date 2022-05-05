#pragma once
#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Question {
	int byla = 0;
public:
	string tresc;
	map<char, string> odpowiedzi;
	double punkty;
	char poprawna;
	
	// konstruktor
	Question(string tresc, map<char, string> odpowiedzi, double punkty, char poprawna) {
		this->tresc = tresc;
		this->odpowiedzi = odpowiedzi;
		this->punkty = punkty;
		this->poprawna = poprawna;
	}

	// treœæ i mo¿liwe odpowiedzi
	void wyswietlPytanie(int nrPytania) {
		cout << "Pytanie " << nrPytania << ": " << tresc << endl;
		for (auto i : odpowiedzi) {
			cout << i.first << ": " << i.second << endl;
		}
	}

	// 0 - dodaje punkty, 1 - nie dodaje punktów, 2 - odejmuje punkty
	// w przypadku gdy nie by³o powrotu do pytania i odpowiedŸ jest b³êdna nie ma zmiany w sumie punktów
	// je¿eli siê zmieni³o odpowiedŸ na b³êdn¹, trzeba odj¹æ punkty od sumy koñcowej
	int sprawdzOdp(char c) {
		if (byla == 0) {
			if (c == poprawna) {
				byla++;
				return 0;
			}
		}
		else {
			if (c == poprawna) return 1;
			else return 2;
		}
	}
};

#endif 
