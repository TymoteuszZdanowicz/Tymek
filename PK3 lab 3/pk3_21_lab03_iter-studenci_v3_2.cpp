// pk3_21_lab03_iter.cpp : Ten plik zawiera funkcj� �main�. W nim rozpoczyna si� i ko�czy wykonywanie programu.
// ver. 3

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class pojWIERSZ : public string {};
istream& operator>>(std::istream& is, pojWIERSZ& l)
{
	getline(is, l);
	return is;
}

int main()
{

	cout << "TYMOTEUSZ ZDANOWICZ " << endl;

	/* ===========================================================================================================
====================================== ZAD 1 =================================================================
============================================================================================================*/
	list<int> lista1 = { 1,2,3,4,5,6 };
	cout << "\t\t================== ZAD 1 ==================\n";
	cout << "\ta) Zwykly iterator \n";
	/* Wykorzystuj�c iterator dla lista1 wy�wietl jego zawarto�� od pocz�tku do ko�ca
		Prosz� w ca�ym progamie NIE U�YWA� typu auto */
	list<int>::iterator i1 = lista1.begin();
	for (i1; i1 != lista1.end(); i1++) {
		cout << *i1 << ", ";
	}

	cout << "\n\tb) Odwrotny iterator \n";
	/* Wykorzystuj�c ODWROTNY iterator dla lista1 wy�wietl jego zawarto�� od ko�ca do pocz�tku */

	list<int>::reverse_iterator i2 = lista1.rbegin();

	for (i2; i2 != lista1.rend(); i2++) {
		cout << *i2 << ", ";
	}


	cout << "\n\tc) Powtorka:\n";
	/* Jeszcze raz wy�wietl ostatni wy�ej wy�wietlony element (TYLKO TEN JEDEN)
	Prosz� NIE INICJOWAC NOWEGO iteratora tylko wykorzysta� ten z pkt b */
	cout << *(--i2);


	cout << "\n\td) Bazowy:\n";
	/* Stw�rz kolejny zwyk�y iteator i przypisz do niego iterator bazowy dla odwrotnego z pkt c) (TYLKO TEN JEDEN)
	A nast�pnie wy�wietl go  */

	list<int>::iterator i3 = i2.base();
	cout << *i3;

	cout << "\n\te) Iterator odwrotny inicjowany iteratorem z pkt d:\n";
	/* St�rz kolejny iterator odwrotny inicjowany iteratorem zwyk�ym z pkt d) (TYLKO TEN JEDEN)
	A nast�pnie wy�wietl go  */

	list<int>::reverse_iterator i4(i3);
	cout << *i4;



	/* ===========================================================================================================
	====================================== ZAD 2 =================================================================
	============================================================================================================*/
	cout << "\n\n\t\t================== ZAD 2 ==================\n";
	/*Prosz� w kolejnych podpunktac do listy lista1 (z zad 1) dodawa� (wstawia�)
nowe elementy  WYKORZYSTUJAC TYLKO ITERATORY WSTAWIAJACE
Wykorzystaj 3 RӯNE rodzaje iterator�w wstawiaj�cych 	*/


	cout << "a) Wstawianie na poczatek listy\n";
	/*a) Na pocz�tek listy wstaw '-2' '-1' '0'.
	A nast�pnie wy�wietl zawarto�� listy (mo�na przekopiowa� kod z zad 1 a) */
	front_insert_iterator <list<int>> iFront(lista1);
	iFront = 0;
	iFront = -1;
	iFront = -2;

	for (int it : lista1) {
		cout << it << ", ";
	}
	/*for (int i = 0; i < lista1.size(); i++) {
		iFront = i;
		*iFront = lista1[i];
	}*/

	cout << "\nODP:\n-2 -1 0 1 2 3 4 5 6\n";


	cout << "\n\nb) Wstawianie na koniec listy\n";
	/* b) Na koniec listy wstaw '7' '8' '9'. A nast�pnie wy�wietl zawarto�� (mo�na przekopiowa� kod z zad 1 a) */
	back_insert_iterator <list<int>> iBack(lista1);
	iBack = 7;
	iBack = 8;
	iBack = 9;

	for (int it : lista1) {
		cout << it << ", ";
	}

	cout << "\nODP:\n-2 -1 0 1 2 3 4 5 6 7 8 9\n";


	cout << "\n\nc) Wstawianie w srodek listy\n";
	/* c) Po DRUGIEJ pozycji w li�cie lista 1 (po elemencie -1) wstaw '100' '200' '300'.
	A nast�pnie wy�wietl zawarto�� (mo�na przekopiowa� kod z zad 1 a) */

	list<int>::iterator pozycja = ++++lista1.begin();
	insert_iterator <list<int>> iMiddle(lista1, pozycja);
	iMiddle = 100;
	iMiddle = 200;
	iMiddle = 300;

	for (int it : lista1) {
		cout << it << ", ";
	}

	cout << "\nODP:\n-2 -1 100 200 300 0 1 2 3 4 5 6 7 8 9\n";





	/* ===============================================================================================
	====================================== ZAD 3 =====================================================
	==================================================================================================*/
	cout << "\n\n\t\t================== ZAD 3 ==================\n";
	/* Stw�rz wektor, kt�ry b�dzie zawiera� elementy typu string.
	Wykorzystuj�c ALGORYTM copy (NIE p�tle) oraz iteratory strumieniowe, sczytaj z klawiatury
	kilka wpisanych przez u�ytkownika wyraz�w.
	Podpowied�: jako trzeci element w algorytmie wykorzystaj back_inserter (do wstawiania do wektora)
	Wczytywanie wyraz�w z klawiatury mo�na zatrzyma� naciskaj�c np. 'ctrl' + 'z'  i 'enter' */

	vector<string> wektor;
	cout << "Wpisz pare wyrazow: " << endl;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(wektor));

	/* Nast�pnie posortuj zawarto�� wektora (algorytm sort)  */
	sort(wektor.begin(), wektor.end());


	/* Na koniec przekopiuj posortowany wektor na wyj�cie - WYKORZYSTAJ ITERATOR WYJ�CIA
	ROZDZIELAJ�C wy�wietlane wyrazy symbolem '*'       */
	copy(wektor.begin(), wektor.end(), ostream_iterator<string>(cout, "*"));



	/* ===============================================================================================
====================================== ZAD 4 =====================================================
==================================================================================================*/
	cout << "\n\n\t\t================== ZAD 4 ==================\n";
	/* Wykorzystujac iteratory strumieniowe wczytawaj PO WIERSZU (linijce) plik "Pomidor.txt".
	Jako elementy wykorzystaj klas� "pojWIERSZ" - zdefiniowan� wy�ej
	Wczytane elementy zapisz w nowym pliku w taki spos�b, aby ka�da wczytana linia w pliku wyj�ciowym
	by�a ROZDZIELONA DODATKOW� PUST� LINI�
	WYKORZYSTAJ ITERATOR WYJ�CIA
	W trakcie zaj�� mo�na wykorzysta� w dowolny spos�b iterator wyj�cia.
	W razie doka�czania zadania po zaj�ciach NIE WYKORZYSTYWAC COPY (jak w zad 3),
	tylko dowoln� PETLE.
	Pomocne:
	ifstream - dla pliku wej
	ofstream - dla pliku wyj

	istream_iterator
	ostream_iterator	 	*/

	ifstream inFile("Pomidor.txt");
	ofstream outFile("Pomidor_ze_spacjami.txt");
	istream_iterator<pojWIERSZ> pocz�tek(inFile);
	istream_iterator<pojWIERSZ> koniec;
	ostream_iterator<pojWIERSZ> doPliku(outFile, "\n\n");
	for (pocz�tek; pocz�tek != koniec; pocz�tek++) {
		//outFile << *pocz�tek << "\n\n";
		doPliku = *pocz�tek;
	}
	//copy(pocz�tek, koniec, doPliku);
	cout << "Przekopiowano zawartosc pliku Pomidor.txt do pliku Pomidor_ze_spacjami.txt ." << endl;
}