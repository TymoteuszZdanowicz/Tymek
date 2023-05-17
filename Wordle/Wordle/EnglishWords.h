#pragma once
#include "CreateWordleDatabase.h"
class EnglishWords : public CreateWordleDatabase
{
public:
	vector<string> loadWords() {
		vector<string> english_words;
		string line;
		ifstream file("sgb-words.txt");

		if (file.is_open()) {
			while (getline(file, line)) {
				english_words.push_back(line);
			}
			file.close();
		}
		else {
			cerr << "Couldn't find file" << endl;
		}
		return english_words;
	}

	string selectWinningWord() {
		vector<string> english_words = loadWords();
		srand(time(nullptr));
		int random = rand() % english_words.size();
		return english_words[random];
	}
};

