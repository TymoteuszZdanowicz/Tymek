#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "Question.h"
#include "parseFile.h"

using namespace std;

int main(int argc, char** argv) {
	string questionFile;
	switch (argc) {
	case 1:
		cout << "Brakuje pliku" << endl;
		break;
	case 2:
		cout << "Dane zostaly odpowiednio wprowadzone." << endl;
		questionFile = argv[1];
		break;
	default:
		cout << "Blad danych" << endl;
	}
	odczytDanych(questionFile);

}