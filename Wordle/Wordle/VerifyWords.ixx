export module VerifyWords;

export import Letter;
import <iostream>;

using namespace std;

export class VerifyWords
{
public:
	Letter* current_guess;
	Letter* correct_word;
	Letter* last_guess;

	VerifyWords(Letter* _current_guess, Letter* _correct_word, Letter* _last_guess) {
		current_guess = _current_guess;
		correct_word = _correct_word;
		last_guess = _last_guess;
	}

	VerifyWords(Letter* _current_guess, Letter* _correct_word) {
		current_guess = _current_guess;
		correct_word = _correct_word;
		last_guess = nullptr;
	}

	Letter* assignColors(string correct);
	bool checkColor();

	~VerifyWords() {

	}
};
