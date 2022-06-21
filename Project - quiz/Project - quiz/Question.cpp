#include "Question.h"

Question::Question(string tresc, map<char, string> odpowiedzi, double punkty, char poprawna) {
	this->tresc = tresc;
	this->odpowiedzi = odpowiedzi;
	this->punkty = punkty;
	this->poprawna = poprawna;
}

Question::Question() {
	tresc = "Brak tresci";
	punkty = 0;
	poprawna = 'x';
}

void Question::wyswietlPytanie(int nrPytania) {
	cout << "Pytanie " << nrPytania << ": " << tresc << endl;
	for (auto i : odpowiedzi) {
		cout << i.first << ": " << i.second << endl;
	}
}
void Question::wyswietlOdpowiedzi(int nrPytania) {
	cout << "Pytanie " << nrPytania << ": " << tresc << endl;
	cout << "Poprawna odpowiedz: " << odpowiedzi[poprawna] << endl << endl;
}

	// 0 - dodaje punkty, 1 - nie dodaje punkt�w, 2 - odejmuje punkty
	// w przypadku gdy nie by�o powrotu do pytania i odpowied� jest b��dna nie ma zmiany w sumie punkt�w
	// je�eli si� zmieni�o odpowied� na b��dn�, trzeba odj�� punkty od sumy ko�cowej
int Question::sprawdzOdp(char c) {
	if (byla == 0) {
		if (c == poprawna) {
			byla++;
			return 0;
		}
	}
	if (byla == 1) {
		if (c == poprawna) { return 1; }
		if (c != poprawna) {
			byla--;
			return 2;
		}
	}
}
