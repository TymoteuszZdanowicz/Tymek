import WordleInterface;
import InterpretGuess;
import Letter;
import VerifyWords;
import Results;
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

vector<sf::Text> displayed_letters;
vector<sf::RectangleShape> displayed_colors;
sf::Font font;
mutex windowMutex;
mutex userInputMutex;

void WordleInterface::wordleInterface() {
    cout << correct_word << endl;
    sf::RenderWindow window(sf::VideoMode(800, 1000), "Wordle Game", sf::Style::Titlebar | sf::Style::Close);

    if (!font.loadFromFile("arialbd.ttf"))
    {
        cout << "failed to load font" << endl;
        return;
    }

    // User textbox
    sf::RectangleShape textBox(sf::Vector2f(360, 25));
    textBox.setPosition(200, 800);
    textBox.setFillColor(sf::Color::White);
    textBox.setOutlineThickness(3);
    textBox.setOutlineColor(sf::Color(100, 100, 100));

    // Text in the user textbox
    sf::Text inputDisplayText;
    inputDisplayText.setFont(font);
    inputDisplayText.setCharacterSize(25);
    inputDisplayText.setFillColor(sf::Color::Black);
    inputDisplayText.setStyle(sf::Text::Regular);
    inputDisplayText.setPosition(205, 795);

    while (window.isOpen()) {
        threads.clear();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == '\b' && !userInput.empty())
                {
                    userInput.pop_back();
                    inputDisplayText.setString(userInput);
                }
                else if (event.text.unicode == '\r')
                {
                    inputDisplayText.setString("");

                    if (winning_condition == true) {
                        window.close();
                        Results result_obj(correct_word, guess_counter, "Win");
                        result_obj.saveGameResults();
                        return;
                    }
                    else if (losing_condition == true) {
                        window.close();
                        Results result_obj(correct_word, guess_counter + 1, "Loss", userInput);
                        result_obj.saveGameResults();
                        return;
                    }

                    thread checkThread(&WordleInterface::checkInput, this, userInput);
                    threads.push_back(move(checkThread));
                }
                else if (event.text.unicode < 128 && isalpha(event.text.unicode))
                {
                    userInput += static_cast<char32_t>(event.text.unicode);
                    inputDisplayText.setString(userInput);
                }
            }
        }

        // If correct input entered -> draw letters and color them
        if (isLetterDisplayed == true) {
            thread setThread(&WordleInterface::setLettersAndColors, this);
            threads.push_back(move(setThread));
        }

        for (auto& thread : threads) {
            thread.join();
        }

        // Clear -> Draw -> Display
        window.clear(sf::Color::Black);

        if (winning_condition == true) {
            sf::Text winning_text;
            winning_text.setFont(font);
            winning_text.setCharacterSize(50);
            winning_text.setFillColor(sf::Color(240, 240, 50));
            winning_text.setStyle(sf::Text::Bold);
            winning_text.setPosition(190, 100);
            winning_text.setString("Congratulations!");

            window.draw(winning_text);
        }
        else if (losing_condition == true) {
            sf::Text loser_text;
            loser_text.setFont(font);
            loser_text.setCharacterSize(50);
            loser_text.setFillColor(sf::Color(150, 150, 150));
            loser_text.setStyle(sf::Text::Bold);
            loser_text.setPosition(150, 100);
            loser_text.setString("Better luck next time!");

            window.draw(loser_text);
        }

        window.draw(textBox);
        window.draw(inputDisplayText);

        // Grid
        for (int row = 0; row < 6; ++row)
        {
            for (int col = 0; col < gridSize; ++col)
            {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(360 - 2.5 * cellSize + col * cellSize + col * offset, 460 - 3 * cellSize + row * cellSize + row * offset);
                cell.setFillColor(sf::Color::Transparent);
                cell.setOutlineThickness(2);
                cell.setOutlineColor(sf::Color(50, 50, 50));

                window.draw(cell);
            }
        }

        for (int i = 0; i < displayed_letters.size(); i++) {
            lock_guard<mutex> lock(windowMutex);
            window.draw(displayed_colors[i]);
            window.draw(displayed_letters[i]);
        }

        window.display();
    }
}

void WordleInterface::setLettersAndColors()
{
    // Display each letter and color
    for (int i = 0; i < 5; ++i) {
        sf::Text cell_text;
        sf::RectangleShape cell_color(sf::Vector2f(cellSize, cellSize));
        char uppercase;

        cell_text.setFont(font);
        cell_text.setCharacterSize(50);
        cell_text.setFillColor(sf::Color::White);
        cell_text.setStyle(sf::Text::Bold);
        cell_text.setOrigin(25, 25);

        cell_color.setOutlineThickness(2);
        cell_color.setOutlineColor(sf::Color(50, 50, 50));

        cell_color.setPosition(360 - 2.5 * cellSize + i * cellSize + i * offset, 460 - 3 * cellSize + (guess_counter - 1) * cellSize + (guess_counter - 1) * offset);
        cell_text.setPosition(400 - 2.5 * cellSize + i * cellSize + i * offset, 485 - 3 * cellSize + (guess_counter - 1) * cellSize + (guess_counter - 1) * offset);

        uppercase = toupper(Guess[i].letter);
        cell_text.setString(uppercase);

        if (Guess[i].color == "Green") {
            cell_color.setFillColor(sf::Color(0, 200, 0));
        }
        else if (Guess[i].color == "Yellow") {
            cell_color.setFillColor(sf::Color(200, 200, 10));
        }
        else if (Guess[i].color == "Black") {
            cell_color.setFillColor(sf::Color(100, 100, 100));
        }

        // Push into vectors
        lock_guard<mutex> lock(windowMutex);
        displayed_letters.push_back(cell_text);
        displayed_colors.push_back(cell_color);
    }
}

void WordleInterface::checkInput(string guess) {
    InterpretGuess interpret_guess(guess);
    InterpretGuess correct(correct_word);

    if (interpret_guess.checkWordParams(words)) {
        Guess = interpret_guess.createGuess();
        Correct_word = correct.createGuess();

        if (guess_counter != 5) {
            isLetterDisplayed = true;
            winning_count = 0;

            VerifyWords verify_words(Guess, Correct_word, Last_guess);
            Guess = verify_words.assignColors(correct_word);

            for (int i = 0; i < 5; i++) {
                if (Guess[i].color == "Green") {
                    winning_count++;
                }
            }

            if (winning_count == 5) {
                cout << "Congratulations!" << endl;
                winning_condition = true;
            }

            if (guess_counter == 0) {
                Last_guess = Guess;
            }
            else {
                if (!verify_words.checkColor()) {
                    guess_counter--;
                    isLetterDisplayed = false;
                    cout << "Not all colors match." << endl;
                }
                else {
                    Last_guess = Guess;
                }
            }
            guess_counter++;
            lock_guard<mutex> lock(userInputMutex);
            userInput = "";
        }
        else if (guess_counter == 5) {
            cout << "loss" << endl;
            losing_condition = true;
        }
    }
    else {
        cout << "Incorrect word" << endl;
    }
}