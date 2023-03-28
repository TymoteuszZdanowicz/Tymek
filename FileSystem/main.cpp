#include <iostream>;
#include <filesystem>;
#include <regex>;
#include <fstream>;
#include <string>;

using namespace std;
using namespace filesystem;

bool sprawdzNumer(string sciezka) {
	if (exists(sciezka)) {
		regex numer("\\+48[0-9]{9}");
		if (regex_match(sciezka, numer)) {
			cout << "Znaleziono numer" << endl;
			return 1;
		}
		ifstream plik(sciezka);
		string linia;
		while (getline(plik, linia)) {
			if (regex_match(linia, numer)) {
				cout << "Znaleziono numer" << endl;
				return 1;
			}
		}
		cout << "Nie znaleziono numeru" << endl;
		return 0;
	}
}

void kalendarz() {
	path dni = "dni/";
	path godziny;

	int godzina = 1;
	for (int i = 1; i < 32; i++) {
		dni += to_string(i);
		create_directory(dni);
		dni += "/";
		for (int j = 1; j <= 24; j++) {
			godziny = dni;
			godziny += to_string(j);
			create_directory(godziny);
			ofstream godz(godziny += ("/" + to_string(godzina) + ".txt"));
			godzina++;
		}
	}
}

void usun(string sciezka) {
	for (const auto& iterator : directory_iterator(sciezka)) {
		if (iterator.is_regular_file()) {
			if (sprawdzNumer(iterator.path().string())) {
				remove(iterator.path());
			}
		}
	}
}

int main() {
	usun("C:/Users/SuperStudent/Desktop/FileSystem");
	kalendarz();
}