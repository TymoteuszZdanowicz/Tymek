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

	// tre�� i mo�liwe odpowiedzi
	void wyswietlPytanie(int nrPytania) {
		cout << "Pytanie " << nrPytania << ": " << tresc << endl;
		for (auto i : odpowiedzi) {
			cout << i.first << ": " << i.second << endl;
		}
	}

	// 0 - dodaje punkty, 1 - nie dodaje punkt�w, 2 - odejmuje punkty
	// w przypadku gdy nie by�o powrotu do pytania i odpowied� jest b��dna nie ma zmiany w sumie punkt�w
	// je�eli si� zmieni�o odpowied� na b��dn�, trzeba odj�� punkty od sumy ko�cowej
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
