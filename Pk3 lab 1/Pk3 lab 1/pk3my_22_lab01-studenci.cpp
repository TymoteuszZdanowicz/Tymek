// pk3my_22_lab01.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
// ver. 10.10.2022

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct osoba {
	string nazwisko, stanowisko;
	osoba(string a, string b) { nazwisko = a; stanowisko = b; };
	osoba() { nazwisko = ""; stanowisko = ""; }
};

template <typename X> X maks(X a, X b) {
	if (a > b) { 
		return a;
	}
	else { 
		return b;
	}
}

//const char* Y;
//template <typename Y> maks(Y a, Y b) {
//	strcmp(a, b);
//}

template <class T1>
class CPojemnik {
private:
	int n;
	int poj;
	T1* tab;

public:
	CPojemnik() {
		poj = 0;
		cout << "Konstruktor domyslny\n";
	}
	CPojemnik(int poj) {
		CPojemnik::poj = poj;
		cout << "Kostruktor 1arg CPojemnik\n";
	}
	~CPojemnik() {
		cout << "Destruktor CPojemnik\n";
	}

	void wstaw(int miejsce, T1 obiekt) {
		if (n <= poj) {
			tab[miejsce] = obiekt;
			n++;
		}
		else {
			cout << "brak miejsca w tablicy" << endl;
		}
	}

	void dodaj(T1 obiekt) {
		if (n <= poj) {
			tab[poj] = obiekt;
		}
		else {
			poj += 3;
			tab[poj] = obiekt;
		}
	}

	void wyswietl() {
		for (int i = 0; i < poj; i++) {
			cout << tab[i] << endl;
		}
	}
	
};





int main()
{
	cout << "PROSZE WPISAC SWOJE IMIE I NAZWISKO " << endl;
	
	/* Proszę odkomentować tylko kod z //    */
	cout << "\n\t======== ZAD 1 i 2 ==== \n";
	cout << maks(1, 2) << "\tpoprawna odp: 2" << endl;
	cout << maks(20.2, 2.3) << "\tpoprawna odp: 20.2" << endl;
	cout << maks(-2.2, 2.2) << "\tpoprawna odp: 2.2" << endl;
	cout << maks('c', 'a') << "\tpoprawna odp: c" << endl << endl;
	cout << maks<string>("aaaa", "bz") << "\tpoprawna odp: bz" << endl;
	cout << maks<string>("aa", "az") << "\tpoprawna odp: az" << endl;
	cout << maks<string>("aaaa", "bz") << "\tpoprawna odp: bz" << endl;
	cout << maks<string>("aaaaaaa", "a") << "\tpoprawna odp: aaaaaa" << endl;
	cout << maks<string>("aaz", "zzd") << "\tpoprawna odp: zzd" << endl;

	cout << "\n\n\t======== ZAD 3 ======== \n";
	osoba o1("Kowalski", "kucharz"), o2("Nowak", "kelner"), o3("Adamski", "barman");

	CPojemnik mojpoj(o1, o2, o3);
	/*Zadeklaruj obiekt mojpoj typu CPojemnik, który pomieści 3 obiekty typu osoba */
	// ....    /* deklaracja mojpoj */
	//mojpoj.dodaj(o1);
	//mojpoj.dodaj(o2);
	//mojpoj.dodaj(o3);
	//mojpoj.dodaj(o2);
	// 
	cout << "Wstawienie nowej osoby do -1:" << endl;
	//mojpoj.wstaw(o1, -1);
	//mojpoj.wstaw(o1, 0);

	/*Zadeklaruj obiekt mojpoj2 typu CPojemnik, który pomieści 3 obiekty typu double */
	// ....    /* deklaracja mojpoj2 */
	//mojpoj2.dodaj(0.0);
	//mojpoj2.dodaj(1.1);
	//mojpoj2.dodaj(200);
	//mojpoj2.dodaj(3.3);
	//mojpoj2.dodaj(4.4);
	//mojpoj2.dodaj(5.5);
	cout << "\nTablica double mojpoj2 (po pierwszym dodawaniu do tablicy) \n";
	//mojpoj2.wyswietl();
	//mojpoj2.wstaw(2.2, 2);
	cout << "Tablica double mojpoj2 (po wstawieniu na miejsce nr 2)\n";
	//mojpoj2.wyswietl();


	cout << "\n\t======== ZAD 4 ======== \n";
	cout << "\nDane dla klasy: CPojemnikD\n";
	/* Zadeklaruj obiekt pojD typu CPojemnikD, który pomieści 3 obiekty. */	
	// ....    /* deklaracja pojD */
	//pojD.dodaj(0);
	//pojD.dodaj(10000.1);
	//pojD.dodaj(2000.1);
	//pojD.dodaj(300.1);
	//pojD.dodaj(40.1);
	//pojD.dodaj(5.1);
	//pojD.wyswietl();
	//cout << "Suma: " << pojD.zwrocsuma() << "\tpoprawna odp: 12345.5" << endl;



	cout << "\n\t======== ZAD 5 ======== \n";
	/*b) Zadeklaruj obiekt pojDopis typu CPojemnikDopis, który pomieści 3 obiekty, opis jest typu string (np. "jestem lista" )*/
	// ....    /* deklaracja pojDopis */
	//pojDopis.dodaj(123.123);
	//cout << "pojDopis" << endl;
	//pojDopis.wyswietl();

		
	/*c) Zadeklaruj obiekt pojDopis2 typu CPojemnikDopis, który pomieści 3 obiekty, opis jest typu osoba  (np. o1)*/
	// ....    /* deklaracja pojDopis2 */
	//pojDopis2.dodaj(-222);
	//cout << "\npojDopis2" << endl;
	//pojDopis2.wyswietl();





	cout << "\n\t======== ZAD SPR ======== \n";
	/*  W celu sprawdzenia, czy dobrze są zdefiniowane klasy (powtórka z PK2) niech wskaźnik
	klasy bazowej wskazuje na obiekt klasy pochodnej.
	1) Proszę do odpowiednich kontruktorów i destruktorów dodać meldunki
		np.	cout << "Kostruktor CPojemnik\n";
			cout << "Kostruktor CPojemnikD\n";
			cout << "Destruktor CPojemnik\n";
			cout << "Destruktor CPojemnikD\n";

	2) A następnie proszę sprawdzić, czy dobrze są wywolywane konstruktory i destruktory dla instrukcji poniżej.
	Proszę pamiętać, że liczba kontruktorów musi być równa liczbie destruktorów.
		(Proszę na początek odkomentować tylko te 2 linijki poniżej) */

	//CPojemnik<double>* mojwsk = new CPojemnikD(2);
	//delete mojwsk;


	/* 3) A następnie prosze sprawdzić, czy dobrze jest wykonywana metoda dodaj() i zwrocsuma() dla
	tego obiektu klasy pochodnej.   */

	//cout << "\n\t=== SPR cd: ===\n";
	//mojwsk = new CPojemnikD(10);
	//mojwsk->dodaj(100);
	//mojwsk->dodaj(110);
	//mojwsk->dodaj(90);
	//cout << "\tzwrocsuma() wynosi: " << dynamic_cast <CPojemnikD*>(mojwsk)->zwrocsuma();
	//cout << "\tpoprawna odp: 300" << endl;
	//delete mojwsk;



	cout << "\n\t==== Koniec programu ==== \n";
}
