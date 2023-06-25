#include <iostream>
#include <vector>
#include <ranges>
#include <filesystem>
#include <fstream>
#include <thread>
import CreateWordleDatabase;
import EnglishWords;
import PolishWords;
import WordleInterface;

using namespace std;

int main() {

	string choice;
	Language chosenLanguage;
	cout << "Choose a language:" << endl << "English" << endl << "Polish" << endl;
	cout << "Type the name of the language: ";
	
	while (true) {
		cin >> choice;
		if (choice == "English") {
			chosenLanguage = English;
			break;
		}
		else if (choice == "Polish") {
			chosenLanguage = Polish;
			break;
		}
	}

	WordleInterface wordle_interface(chosenLanguage);
	//wordle_interface.wordleInterface();

	thread interface_thread(&WordleInterface::wordleInterface, &wordle_interface);
	interface_thread.join();
}