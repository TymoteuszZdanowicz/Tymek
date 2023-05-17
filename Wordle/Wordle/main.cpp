#include <iostream>
#include <vector>
#include <ranges>
#include <filesystem>
#include <fstream>
#include "PolishWords.h"
#include "EnglishWords.h"
#include "CreateWordleDatabase.h"
#include "WordleInterface.h"

using namespace std;

int main() {
	/*PolishWords slowa;
	vector<string> Slowa = slowa.loadWords();

	ofstream file("polskie_slowa.txt");
	for (string i : Slowa) {
		file << i << endl;
	}*/

	WordleInterface wordle_interface;
	wordle_interface.wordleInterface();

}