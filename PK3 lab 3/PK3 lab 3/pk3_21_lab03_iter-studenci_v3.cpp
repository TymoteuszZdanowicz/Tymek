// pk3_21_lab03_iter.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
	/* Wykorzystując iterator dla lista1 wyświetl jego zawartość od początku do końca 
		Proszę w całym progamie NIE UŻYWAĆ typu auto */
	list<int>::iterator i1 = lista1.begin();
	for (i1; i1 != lista1.end(); i1++) {
		cout << *i1 << ", ";
	}

	cout << "\n\tb) Odwrotny iterator \n";
	/* Wykorzystując ODWROTNY iterator dla lista1 wyświetl jego zawartość od końca do początku */

	list<int>::reverse_iterator i2 = lista1.rbegin();

	for (i2; i2 != lista1.rend(); i2++) {
		cout << *i2 << ", ";
	}


	cout << "\n\tc) Powtorka:\n";
	/* Jeszcze raz wyświetl ostatni wyżej wyświetlony element (TYLKO TEN JEDEN)
	Proszę NIE INICJOWAC NOWEGO iteratora tylko wykorzystać ten z pkt b */
	cout << *(--i2);


	cout << "\n\td) Bazowy:\n";
	/* Stwórz kolejny zwykły iteator i przypisz do niego iterator bazowy dla odwrotnego z pkt c) (TYLKO TEN JEDEN)
	A następnie wyświetl go  */

	list<int>::iterator i3 = i2.base();
	cout << *i3;

	cout << "\n\te) Iterator odwrotny inicjowany iteratorem z pkt d:\n";
	/* Stórz kolejny iterator odwrotny inicjowany iteratorem zwykłym z pkt d) (TYLKO TEN JEDEN)
	A następnie wyświetl go  */
	
	list<int>::reverse_iterator i4(i3);
	cout << *i4;



	/* ===========================================================================================================
	====================================== ZAD 2 =================================================================
	============================================================================================================*/
	cout << "\n\n\t\t================== ZAD 2 ==================\n";
		/*Proszę w kolejnych podpunktac do listy lista1 (z zad 1) dodawać (wstawiać) 
	nowe elementy  WYKORZYSTUJAC TYLKO ITERATORY WSTAWIAJACE 
	Wykorzystaj 3 RÓŻNE rodzaje iteratorów wstawiających 	*/


	cout << "a) Wstawianie na poczatek listy\n";
	/*a) Na początek listy wstaw '-2' '-1' '0'. 
	A następnie wyświetl zawartość listy (można przekopiować kod z zad 1 a) */
	front_insert_iterator <list<int>> iFront(lista1);
	iFront = 0;
	iFront = -1;
	iFront = -2;

	for (int it : lista1) {
		cout << it << ", ";
	}
	
	cout << "\nODP:\n-2 -1 0 1 2 3 4 5 6\n";


	cout << "\n\nb) Wstawianie na koniec listy\n";
	/* b) Na koniec listy wstaw '7' '8' '9'. A następnie wyświetl zawartość (można przekopiować kod z zad 1 a) */
	back_insert_iterator <list<int>> iBack(lista1);
	iBack = 7;
	iBack = 8;
	iBack = 9;

	for (int it : lista1) {
		cout << it << ", ";
	}

	cout << "\nODP:\n-2 -1 0 1 2 3 4 5 6 7 8 9\n";


	cout << "\n\nb) Wstawianie w srodek listy\n";
	/* c) Po DRUGIEJ pozycji w liście lista 1 (po elemencie -1) wstaw '100' '200' '300'. 
	A następnie wyświetl zawartość (można przekopiować kod z zad 1 a) */

	list<int>::iterator pozycja = ++lista1.begin();
	pozycja++;
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
	/* Stwórz wektor, który będzie zawierał elementy typu string.
	Wykorzystując ALGORYTM copy (NIE pętle) oraz iteratory strumieniowe, sczytaj z klawiatury 
	kilka wpisanych przez użytkownika wyrazów.
	Podpowiedź: jako trzeci element w algorytmie wykorzystaj back_inserter (do wstawiania do wektora)
	Wczytywanie wyrazów z klawiatury można zatrzymać naciskając np. 'ctrl' + 'z'  i 'enter' */

	vector<string> wektor;
	cout << "Wpisz pare wyrazow: " << endl;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(wektor));

	 /* Następnie posortuj zawartość wektora (algorytm sort)  */
	sort(wektor.begin(), wektor.end());


	/* Na koniec przekopiuj posortowany wektor na wyjście - WYKORZYSTAJ ITERATOR WYJŚCIA
	ROZDZIELAJĄC wyświetlane wyrazy symbolem '*'       */
	copy(wektor.begin(), wektor.end(), ostream_iterator<string>(cout, "*"));
	


		/* ===============================================================================================
	====================================== ZAD 4 =====================================================
	==================================================================================================*/
	cout << "\n\n\t\t================== ZAD 4 ==================\n";
	/* Wykorzystujac iteratory strumieniowe wczytawaj PO WIERSZU (linijce) plik "Pomidor.txt".
	Jako elementy wykorzystaj klasę "pojWIERSZ" - zdefiniowaną wyżej
	Wczytane elementy zapisz w nowym pliku w taki sposób, aby każda wczytana linia w pliku wyjściowym
	była ROZDZIELONA DODATKOWĄ PUSTĄ LINIĄ
	WYKORZYSTAJ ITERATOR WYJŚCIA

	W trakcie zajęć można wykorzystać w dowolny sposób iterator wyjścia.
	W razie dokańczania zadania po zajęciach NIE WYKORZYSTYWAC COPY (jak w zad 3),
	tylko dowolną PETLE.


	Pomocne:
	ifstream - dla pliku wej
	ofstream - dla pliku wyj
	
	istream_iterator
	ostream_iterator	 	*/

	ifstream inFile("Pomidor.txt");
	ofstream outFile("Pomidor_ze_spacjami.txt");
	istream_iterator<pojWIERSZ> początek(inFile);
	istream_iterator<pojWIERSZ> koniec;
	ostream_iterator<pojWIERSZ> doPliku(outFile, "\n\n");
	copy(początek, koniec, doPliku);
	cout << "Przekopiowano zawartosc pliku Pomidor.txt do pliku Pomidor_ze_spacjami.txt ." << endl;
}
