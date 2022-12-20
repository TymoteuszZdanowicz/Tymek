#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Tablica {
public:
	T* tab;
	long long int poj;

	Tablica() {
		cout << "Konstruktor domyslny" << endl;
	}

	Tablica(long long int n) {
		poj = n;
		tab = new T[poj];
		cout << "Konstruktor jednoargumentowy" << endl;
	}

	~Tablica() {
		cout << "Destruktor" << endl;
	}

	void wstaw(long long int poz, T wartosc) {
		try {
			tab[poz] = wartosc;
		}
		catch (out_of_range ex) {
			cout << "poza zakresem" << endl;
		}
	}

	T zwroc(long long int poz) {
		if (poz <= poj) {
			return tab[poz];
		}
		cout << "Nie istnieje pozycja w tablicy" << endl;
		return 0;
	}
};

template <class T2>
class singleton {
public:
	static singleton& getInstance() {
		static singleton inst;
		return inst;
	}

	void zapisDoPliku(T2 tresc) {
		plik << tresc << " ";
	}

private:
	ofstream plik;
	string nazwaPliku = "Plik.txt";
	
	singleton& operator=(const singleton&) {};
	singleton(const singleton&) {};

	singleton() {
		cout << "Otwieranie pliku" << endl;
		plik.open(nazwaPliku);
	}
	~singleton() {
		cout << "Zamykanie pliku" << endl;
		plik.close();
	}
};

int main() {
	/*Tablica<double> obiekt(10);
	cout << endl;
	obiekt.wstaw(5, 2.2);*/

	//string tresc = "cokolwiek";
	//singleton<string>::getInstance().zapisDoPliku(tresc);

	/*for (int i = 0; i < 10; i++) {
		obiekt.zwroc(i);
	}*/

	unsigned long long x = 1000000000'000'000;
	try {
		Tablica<char> tab1(x);
	}
	catch (exception ex) {

	}

	try {
		x = 1000'000'000;
		Tablica<char> tab2(x);
		tab2.wstaw(x + 2, 'a');
		cout << tab2.tab[x + 2] << endl;
	}
	catch (exception ex) {

	}

	try {
		x = 10;
		Tablica<char> tab3(x);

		for (int i = 0; i < tab3.poj; i++) {
			tab3.wstaw(i, 'b');
		}
		for (int i = 0; i < tab3.poj; i++) {
			singleton<char>::getInstance().zapisDoPliku(tab3.zwroc(i));
		}
	}
	catch (exception ex) {

	}

	//-----------------------------------------
	unsigned long long y = 1000000000'000'000;
	try {
		Tablica<double> tab4(y);
	}
	catch (exception ex) {

	}

	try {
		y = 1000'000'000;
		Tablica<double> tab5(y);
	}
	catch (exception ex) {

	}

	try {
		y = 10;
		Tablica<double> tab6(y);

		for (int i = 0; i < tab6.poj; i++) {
			tab6.wstaw(i, i);
		}
		for (int i = 0; i < tab6.poj; i++) {
			singleton<double>::getInstance().zapisDoPliku(tab6.zwroc(i));
		}
	}
	catch (exception ex) {

	}
}