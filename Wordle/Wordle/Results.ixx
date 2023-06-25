export module Results;

import <filesystem>;
import <iostream>;

using namespace std;
using namespace filesystem;

export class Results
{
private:
    path results_folder = "Results";
    string correct_word;
    int numOfGuesses;
    string gameResult;
    string userInput;

public:
    Results(string _correct_word, int _numOfGuesses, string _gameResult) {
        correct_word = _correct_word;
        numOfGuesses = _numOfGuesses;
        gameResult = _gameResult;
    }

    Results(string _correct_word, int _numOfGuesses, string _gameResult, string _userInput) {
        correct_word = _correct_word;
        numOfGuesses = _numOfGuesses;
        gameResult = _gameResult;
        userInput = _userInput;
    }

    void saveGameResults();
};