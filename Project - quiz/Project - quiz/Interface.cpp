#include "Interface.h"

Interface::Interface(vector<Question> pytania, double sumaPunktow, int iloscPytan) {
	this->pytania = pytania;
	this->sumaPunktow = sumaPunktow;
	this->iloscPytan = iloscPytan;
}

void Interface::wybor() {
	char wybor;
	cout << "Zaczynamy Quiz." << endl << "Wybierz tryb nauczania: " << endl << "a) nauka" << endl << "b) test" << endl;

	while (true) {
		cin >> wybor;
		if (wybor == 'a') {
			Interface::nauka();
			break;
		}
		if (wybor == 'b') {
			Interface::test();
			break;
		}
		else {
			cout << "Jeszcze raz..." << endl;
		}
	}
	cout << endl << "-------------" << endl << endl;
	for (int i = 0; i < pytania.size(); i++) {
		pytania[i].wyswietlOdpowiedzi(i+1);
	}
}

void Interface::nauka() {
	string start, odp;
	int n = 0, sprawdzOdp;
	cout << "Liczba punktow do uzyskania: " << sumaPunktow << endl 
		<< "Ilosc pytan: " << iloscPytan << endl 
		<< "W trybie nauki mozna zmieniac pytania za pomoca przelacznika >'x' lub przejsc do nastepnego pytania za pomoca >." << endl 
		<< "Aby zaczac test w trybie nauki wpisz 'start'" << endl;
	Interface::Start(n);
	beginTime = time(NULL);
	while (true) {
		cin >> odp;
		if (odp[0] == '>' && odp.size() == 1) {
			if (n == pytania.size() - 1) { 
				cout << "Ostatnie pytanie" << endl; 
			}
			else {
				n++;
				pytania[n].wyswietlPytanie(n + 1);
			}
		}
		if (odp[0] == '>' && odp.size() != 1) {
			for (char const& c : odp.substr(1, odp.size() - 1)) {
				if (isdigit(c)) {
					n = stoi(odp.substr(1, odp.size())) - 1;
				}
			}
			if (n > pytania.size() - 1) { 
				cout << "Nie ma takiego numeru pytania" << endl; 
			}
			else { 
				pytania[n].wyswietlPytanie(n + 1); 
			}
		}
		if (odp.size() == 1 && pytania[n].odpowiedzi.count(odp[0]) == 1) {
			sprawdzOdp = pytania[n].sprawdzOdp(odp[0]);
			if (sprawdzOdp == 0) { 
				otrzymanePunkty += pytania[n].punkty; 
			}
			else if (sprawdzOdp == 2) { 
				otrzymanePunkty = otrzymanePunkty - pytania[n].punkty; 
			}
			if (n < pytania.size()-1) {
				n++;
				pytania[n].wyswietlPytanie(n + 1);
			}
		}
		if (odp.size() == 1 && pytania[n].odpowiedzi.count(odp[0]) == 0) {
			cout << "Nie ma takiej odpowiedzi." << endl;
		}
		if (odp == "koniec") { 
			endTime = time(NULL);
			break; 
		}
	}
}

void Interface::test() {
	string start, odp;
	int n = 0, sprawdzOdp;
	cout << "Liczba punktow do uzyskania: " << sumaPunktow << endl
		<< "Ilosc pytan: " << iloscPytan << endl
		<< "Podczas testu nie mozna wracac do pytan i na kazde pytanie mozna odpowiedziec jedynie raz" << endl
		<< "Aby zaczac test wpisz 'start'" << endl;
	Interface::Start(n);
	beginTime = time(NULL);
	while (true) {
		cin >> odp;
		if (odp.size() == 1 && pytania[n].odpowiedzi.count(odp[0]) == 1) {
			sprawdzOdp = pytania[n].sprawdzOdp(odp[0]);
			if (sprawdzOdp == 0) {
				otrzymanePunkty += pytania[n].punkty;
				n++;
				if (n == pytania.size()) { break; }
				pytania[n].wyswietlPytanie(n + 1);
			}
			else {
				n++;
				if (n == pytania.size()) { break; }
				pytania[n].wyswietlPytanie(n + 1);
			}
		}
		if (odp.size() == 1 && pytania[n].odpowiedzi.count(odp[0]) == 0) {
			cout << "Nie ma takiej odpowiedzi." << endl;
		}
	}
	endTime = time(NULL);
}

void Interface::Start(int n) {
	while (true) {
		cin >> start;
		if (start == "start") {
			cout << "Aby zakonczyc quiz, wpisz 'koniec'." << endl;
			pytania[n].wyswietlPytanie(n + 1);
			break;
		}
		else {
			cout << "try again..." << endl;
		}
	}
}

