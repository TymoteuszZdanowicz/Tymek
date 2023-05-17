#include "InterpretGuess.h"

bool InterpretGuess::checkWordParams(const vector<string>& english_words, string guess) {
	current_guess = guess;
	if (current_guess.size() == 5) {
		for (const string& word : english_words) {
			if (word.find(current_guess)) {
				return true;
			}
		}
	}
	cout << "Not a 5 letter word" << endl;
	return false;
}

Letter* InterpretGuess::createGuess(string guess) {
	current_guess = guess;
	Letter* temp = new Letter[5];
	for (int i = 0; i < 5; i++) {
		temp[i].letter = current_guess[i];
		temp[i].position = i;
	}
	return temp;
}

void InterpretGuess::assignColors(Letter* Guess, const string& correctWord)
{
	for (int i = 0; i < 5; i++)
	{
		if (Guess[i].letter == correctWord[i])
		{
			Guess[i].color = "Green";
		}
		else if (correctWord.find(Guess[i].letter) != string::npos)
		{
			Guess[i].color = "Yellow";
		}
		else
		{
			Guess[i].color = "Black";
		}
	}
}