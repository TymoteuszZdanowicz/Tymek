export module InterpretGuess;

export import Letter;
import <iostream>;
import <ranges>;
import <vector>;

using namespace std;

export class InterpretGuess
{
public:
    string current_guess;

    InterpretGuess(string guess)
    {
        current_guess = guess;
    }

    bool checkWordParams(ranges::ref_view<vector<string>> words);
    Letter* createGuess();

    ~InterpretGuess()
    {
    }
};