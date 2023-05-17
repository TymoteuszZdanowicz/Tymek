#pragma once
#include "CreateWordleDatabase.h"
class PolishWords : public CreateWordleDatabase
{
public:
	vector<string> loadWords() {
		vector<string> polish_words;
		string line;
		ifstream file("slowa.txt");

		if (file.is_open()) {
			file.imbue(locale(locale().empty(), new codecvt_utf8<wchar_t>));
			while (getline(file, line)) {
				if (line.size() == 5) {
					polish_words.push_back(line);
				}
			}
			file.close();
		}
		else {
			cerr << "Couldn't find file" << endl;
		}
		return polish_words;
	}

	string selectWinningWord() {
		vector<string> polish_words = loadWords();
		srand(time(nullptr));
		int random = rand() % polish_words.size();
		return polish_words[random];
	}
};

