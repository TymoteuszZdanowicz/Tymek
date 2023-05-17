#include "Letter.h"

using namespace std;

class InterpretGuess
{
public:
	string current_guess;

	bool checkWordParams(const vector<string>& english_words, string guess);
	Letter* createGuess(string guess);
	void assignColors(Letter* Guess, const string& correctWord);
};
