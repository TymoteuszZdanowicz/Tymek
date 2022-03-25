#include <iostream>
#include "Counter.h"

using namespace std;

int main() {
	Counter a(12);
	Counter b(18);
	a = b;
	cout << a.getcnt() << endl;
	cout << a + 5 << endl;
	a += 5;
	cout << a.getcnt() << endl;
	cout << a(4) << endl;
	cout << ~a << endl;
	cout << ++a << endl;
	//cout << a++ << endl;
}