#include "parseFile.h"

void ParseFile::odczytDanych(string fileName) {
	fstream plik(fileName);
	if (plik.is_open()) {
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
					odpowiedzi.clear();
					counter--;
				}
			}
		}
		plik.close();
	}
	iloscPytan = pytania.size();
	for (int i = 0; i < iloscPytan; i++) {
		sumaPunktow += pytania[i].punkty;
	}
}