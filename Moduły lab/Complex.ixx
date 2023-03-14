export module Complex;

import <iostream>;

using namespace std;

double power(double v) {
	return v * v;
}

export void addition(double Re1, double Im1, double Re2, double Im2) {
	cout << Re1 + Re2 << " + " << Im1 + Im2 << endl;
}

export void subtraction(double Re1, double Im1, double Re2, double Im2) {
	cout << Re1 - Re2 << " + " << Im1 - Im2 << endl;
}

export void multiplication(double Re1, double Im1, double Re2, double Im2) {
	double Re, Im;

	Re = Re1 * Re2 - Im1 * Im2;
	Im = Re1 * Im2 + Im1 * Re2;
	cout << Re << " + " << Im << endl;
}
