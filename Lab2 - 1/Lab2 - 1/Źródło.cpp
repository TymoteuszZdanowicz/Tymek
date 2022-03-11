#include <iostream>
#include "Student.cpp"

using namespace std;

int main() {
	student a;
	student b("Kowalski", "Andrzej", 2,  0);
	b.dodaj_srednia(4);
	b.wyswietl1();
}