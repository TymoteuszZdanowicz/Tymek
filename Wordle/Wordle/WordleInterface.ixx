export module WordleInterface;

import <iostream>;
import CreateWordleDatabase;
import EnglishWords;
import PolishWords;
import Letter;

using namespace std;

export enum Language {
    English,
    Polish
};

export class WordleInterface {
private:
    int gridSize;
    int cellSize;
    int offset;
    int guess_counter;
    Language language;

public:
    EnglishWords englishWords;
    PolishWords polishWords;
    vector<string> words;
    string correct_word;
    string userInput;
    Letter* Guess;
    Letter* Correct_word;
    Letter* Last_guess;
    vector<thread> threads;
    bool isLetterDisplayed = false;
    int winning_count;
    bool winning_condition = false;
    bool losing_condition = false;

    WordleInterface(Language lang) {
        gridSize = 5;
        cellSize = 70;
        offset = 10;
        guess_counter = 0;
        language = lang;

        if (language == English) {
            words = englishWords.loadWords();
            correct_word = englishWords.selectWinningWord(words);
        }
        else if (language == Polish) {
            words = polishWords.loadWords();
            correct_word = polishWords.selectWinningWord(words);
        }
    }

    ~WordleInterface() {

    }

    void wordleInterface();
    void setLettersAndColors();
    void checkInput(string guess);
};