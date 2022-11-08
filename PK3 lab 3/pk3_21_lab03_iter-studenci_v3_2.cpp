// pk3_21_lab03_iter.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
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
	/* Wykorzystuj¹c iterator dla lista1 wyœwietl jego zawartoœæ od pocz¹tku do koñca
		Proszê w ca³ym progamie NIE U¯YWAÆ typu auto */
	list<int>::iterator i1 = lista1.begin();
	for (i1; i1 != lista1.end(); i1++) {
		cout << *i1 << ", ";
	}

	cout << "\n\tb) Odwrotny iterator \n";
	/* Wykorzystuj¹c ODWROTNY iterator dla lista1 wyœwietl jego zawartoœæ od koñca do pocz¹tku */

	list<int>::reverse_iterator i2 = lista1.rbegin();

	for (i2; i2 != lista1.rend(); i2++) {
		cout << *i2 << ", ";
	}


	cout << "\n\tc) Powtorka:\n";
	/* Jeszcze raz wyœwietl ostatni wy¿ej wyœwietlony element (TYLKO TEN JEDEN)
	Proszê NIE INICJOWAC NOWEGO iteratora tylko wykorzystaæ ten z pkt b */
	cout << *(--i2);


	cout << "\n\td) Bazowy:\n";
	/* Stwórz kolejny zwyk³y iteator i przypisz do niego iterator bazowy dla odwrotnego z pkt c) (TYLKO TEN JEDEN)
	A nastêpnie wyœwietl go  */

	list<int>::iterator i3 = i2.base();
	cout << *i3;

	cout << "\n\te) Iterator odwrotny inicjowany iteratorem z pkt d:\n";
	/* Stórz kolejny iterator odwrotny inicjowany iteratorem zwyk³ym z pkt d) (TYLKO TEN JEDEN)
	A nastêpnie wyœwietl go  */

	list<int>::reverse_iterator i4(i3);
	cout << *i4;



	/* ===========================================================================================================
	====================================== ZAD 2 =================================================================
	============================================================================================================*/
	cout << "\n\n\t\t================== ZAD 2 ==================\n";
	/*Proszê w kolejnych podpunktac do listy lista1 (z zad 1) dodawaæ (wstawiaæ)
nowe elementy  WYKORZYSTUJAC TYLKO ITERATORY WSTAWIAJACE
Wykorzystaj 3 RÓ¯NE rodzaje iteratorów wstawiaj¹cych 	*/


	cout << "a) Wstawianie na poczatek listy\n";
	/*a) Na pocz¹tek listy wstaw '-2' '-1' '0'.
	A nastêpnie wyœwietl zawartoœæ listy (mo¿na przekopiowaæ kod z zad 1 a) */
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
	/* b) Na koniec listy wstaw '7' '8' '9'. A nastêpnie wyœwietl zawartoœæ (mo¿na przekopiowaæ kod z zad 1 a) */
	back_insert_iterator <list<int>> iBack(lista1);
	iBack = 7;
	iBack = 8;
	iBack = 9;

	for (int it : lista1) {
		cout << it << ", ";
	}

	cout << "\nODP:\n-2 -1 0 1 2 3 4 5 6 7 8 9\n";


	cout << "\n\nc) Wstawianie w srodek listy\n";
	/* c) Po DRUGIEJ pozycji w liœcie lista 1 (po elemencie -1) wstaw '100' '200' '300'.
	A nastêpnie wyœwietl zawartoœæ (mo¿na przekopiowaæ kod z zad 1 a) */

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
	/* Stwórz wektor, który bêdzie zawiera³ elementy typu string.
	Wykorzystuj¹c ALGORYTM copy (NIE pêtle) oraz iteratory strumieniowe, sczytaj z klawiatury
	kilka wpisanych przez u¿ytkownika wyrazów.
	PodpowiedŸ: jako trzeci element w algorytmie wykorzystaj back_inserter (do wstawiania do wektora)
	Wczytywanie wyrazów z klawiatury mo¿na zatrzymaæ naciskaj¹c np. 'ctrl' + 'z'  i 'enter' */

	vector<string> wektor;
	cout << "Wpisz pare wyrazow: " << endl;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(wektor));

	/* Nastêpnie posortuj zawartoœæ wektora (algorytm sort)  */
	sort(wektor.begin(), wektor.end());


	/* Na koniec przekopiuj posortowany wektor na wyjœcie - WYKORZYSTAJ ITERATOR WYJŒCIA
	ROZDZIELAJ¥C wyœwietlane wyrazy symbolem '*'       */
	copy(wektor.begin(), wektor.end(), ostream_iterator<string>(cout, "*"));



	/* ===============================================================================================
====================================== ZAD 4 =====================================================
==================================================================================================*/
	cout << "\n\n\t\t================== ZAD 4 ==================\n";
	/* Wykorzystujac iteratory strumieniowe wczytawaj PO WIERSZU (linijce) plik "Pomidor.txt".
	Jako elementy wykorzystaj klasê "pojWIERSZ" - zdefiniowan¹ wy¿ej
	Wczytane elementy zapisz w nowym pliku w taki sposób, aby ka¿da wczytana linia w pliku wyjœciowym
	by³a ROZDZIELONA DODATKOW¥ PUST¥ LINI¥
	WYKORZYSTAJ ITERATOR WYJŒCIA
	W trakcie zajêæ mo¿na wykorzystaæ w dowolny sposób iterator wyjœcia.
	W razie dokañczania zadania po zajêciach NIE WYKORZYSTYWAC COPY (jak w zad 3),
	tylko dowoln¹ PETLE.
	Pomocne:
	ifstream - dla pliku wej
	ofstream - dla pliku wyj

	istream_iterator
	ostream_iterator	 	*/

	ifstream inFile("Pomidor.txt");
	ofstream outFile("Pomidor_ze_spacjami.txt");
	istream_iterator<pojWIERSZ> pocz¹tek(inFile);
	istream_iterator<pojWIERSZ> koniec;
	ostream_iterator<pojWIERSZ> doPliku(outFile, "\n\n");
	for (pocz¹tek; pocz¹tek != koniec; pocz¹tek++) {
		//outFile << *pocz¹tek << "\n\n";
		doPliku = *pocz¹tek;
	}
	//copy(pocz¹tek, koniec, doPliku);
	cout << "Przekopiowano zawartosc pliku Pomidor.txt do pliku Pomidor_ze_spacjami.txt ." << endl;
}