#include <iostream>
#include <string>
#include <fstream>
#include "Question.h"
#include "ParseFile.h"
#include "Interface.h"
#include "Results.h"

using namespace std;

int main(int argc, char** argv) {
	string questionFile;
	if (argc == 1) { cout << "Brakuje pliku" << endl; }
	if (argc == 2) {
		questionFile = argv[1];
		fstream fileCheck(questionFile);
		if (!fileCheck) {
			cout << "Niepoprawna nazwa pliku";
			return 0;
		}
		cout << "Dane zostaly odpowiednio wprowadzone." << endl;
		ParseFile odczyt;
		odczyt.odczytDanych(questionFile);
		Interface interfejs(odczyt.pytania, odczyt.sumaPunktow, odczyt.iloscPytan);
		interfejs.wybor();
		Results punkty(interfejs.otrzymanePunkty, interfejs.beginTime, interfejs.endTime);
		punkty.zliczPunkty(odczyt.sumaPunktow);
		punkty.zliczCzas();
	}
	else { cout << "Blad danych" << endl; }
}