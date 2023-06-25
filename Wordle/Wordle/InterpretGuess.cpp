import InterpretGuess;
#include <iostream>
#include <regex>
#include <ranges>

using namespace std;

bool InterpretGuess::checkWordParams(ranges::ref_view<vector<string>> words) {
	regex wordRegex("^\\w{5}$");

	auto filteredWords = words | ranges::views::filter([&](const string& word) {
		return regex_search(word, wordRegex) && word == current_guess;
		});

	if (!filteredWords.empty()) {
		return true;
	}
	else {
		return false;
	}
}

Letter* InterpretGuess::createGuess() {
	Letter* temp = new Letter[5];
	for (int i = 0; i < 5; i++) {
		temp[i].letter = current_guess[i];
	}
	return temp;
}