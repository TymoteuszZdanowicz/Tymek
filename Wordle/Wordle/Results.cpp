import Results;
#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <sstream>

using namespace std;
using namespace filesystem;

void Results::saveGameResults()
{
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);

    stringstream filenamess;
    filenamess << put_time(localtime(&time), "%Y-%m-%d %H-%M-%S");
    path filename = filenamess.str() + "_" + gameResult + ".txt";
    path filePath = results_folder / filename;

    ofstream outputFile(filePath);

    if (outputFile.is_open())
    {
        outputFile << "Correct Word: " << correct_word << endl;
        if (gameResult == "Loss") {
            outputFile << "Last guess: " << userInput << endl;
        }
        outputFile << "Number of Guesses: " << numOfGuesses << endl;
        outputFile << "Game Result: " << gameResult << endl;

        outputFile.close();
        cout << "Game results saved successfully." << endl;
    }
    else
    {
        cout << "Failed to save game results." << endl;
    }
}