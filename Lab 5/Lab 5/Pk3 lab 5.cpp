#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Tablica {
public:
	T* tab;
	long long int poj;

	Tablica() {
		cout << "Konstruktor domy�lny" << endl;
	}

	Tablica(long long int n) {
		poj = n;
		tab = new T[poj];
		cout << "Konstruktor jednoargumentowy" << endl;
	}

	~Tablica() {
		cout << "Destruktor" << endl;
	}

	void wstaw(long long int poz, T warto��) {
		if (poz <= poj) {
			tab[poz] = warto��;
			return;
		}
		cout << "Nie istnieje pozycja w tablicy" << endl;
	}

	void zwr��(long long int poz) {
		if (poz <= poj) {
			cout << tab[poz] << endl;
			return;
		}
		cout << "Nie istnieje pozycja w tablicy" << endl;
	}
};

class singleton {
public:
	string nazwaPliku = "Plik.txt";
	ofstream plik;

	static singleton& getInstance() {
		static singleton inst;
		return inst;
	}

	void zapisDoPliku(string tre��) {
		plik << tre��;
	}

private:
	singleton() {
		
		cout << "Singleton konstruktor domyslny" << endl;
	}
	~singleton() {
		
	}
};

int main() {
	Tablica<double> obiekt(10);

	/*for (int i = 0; i < 10; i++) {
		obiekt.wstaw(i, 3.2);
		obiekt.zwr��(i);
	}*/
	cout << endl;
	obiekt.wstaw(5, 2.2);

	/*for (int i = 0; i < 10; i++) {
		obiekt.zwr��(i);
	}*/
}