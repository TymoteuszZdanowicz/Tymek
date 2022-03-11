#include <iostream>

using namespace std;

class student {
public:
	string nazwisko;
	string imie;
	const int numer_legitymacji;
	int semestr;
	int* srednia[7];

	student():numer_legitymacji(0) {
		nazwisko = "Nowak";
		imie = "Jan";
		semestr = 1;
		cout << "W konstruktorze domyœlnym:" << endl;
		cout << nazwisko << endl;
		cout << imie << endl;
		cout << semestr << endl;
		cout << numer_legitymacji << endl << endl;
	}

	student(string imie, string nazwisko, int semestr, int nr_indexu) :numer_legitymacji(nr_indexu) {
		cout << "Konstruktor wieloargumentowy:" << endl;
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->semestr = semestr;
	}

	void dodaj_srednia(int srednia_semestralna) {
		*srednia[semestr] = srednia_semestralna;
	}

	void wyswietl1() {
		cout << nazwisko << endl;
		cout << imie << endl;
		cout << semestr << endl;
		cout << srednia[semestr] << endl;
		cout << numer_legitymacji << endl;
	}

	~student() {
		cout << "Destruktor" << endl;
	}


};

