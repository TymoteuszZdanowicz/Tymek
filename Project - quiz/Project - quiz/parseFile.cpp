#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Question.h"

using namespace std;

void odczytDanych(string fileName) {
	vector<Question> pytania;
	fstream plik(fileName);
	if (plik.is_open()) {
		string linijka, trescOdp, tempPunkty;
		string tresc;
		map<char, string> odpowiedzi;
		double punkty;
		char poprawna;
		string pytanie = "Pytanie";
		string odp = "Odp";
		int counter = 0;
		while (getline(plik, linijka)) {
			if (counter == 0) {
				if (linijka.substr(0, 7) == pytanie) {
					tresc = linijka.substr(11, linijka.size());
					counter++;
				}
			}
			if (counter == 1) {
				if (linijka.substr(0, 3) == odp) {
					trescOdp = linijka.substr(6, linijka.size());
					odpowiedzi[linijka[4]] = trescOdp;
				}
				if (linijka[0] == '!') {
					tempPunkty = linijka.substr(1, linijka.size()-3);
					punkty = stod(tempPunkty);
					poprawna = linijka[linijka.size() - 1];
					Question pytanie(tresc, odpowiedzi, punkty, poprawna);
					pytania.push_back(pytanie);
					counter--;
				}
			}
		}
		plik.close();
	}

	//debug
	for (int i = 0; i < pytania.size(); i++) {
		pytania[i].wyswietlPytanie(i);
	}
}