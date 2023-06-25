import VerifyWords;
#include <iostream>

using namespace std;

Letter* VerifyWords::assignColors(string correct) {
    for (int i = 0; i < 5; i++) {
        if (current_guess[i].letter == correct_word[i].letter) {
            correct.replace(correct.find(current_guess[i].letter), 1, "");  
            current_guess[i].color = "Green";  
        }
        else {
            current_guess[i].color = "Black";
        }
    }

    for (int i = 0; i < 5; i++) {
        if (correct.find(current_guess[i].letter) != string::npos && current_guess[i].letter != correct_word[i].letter) {
            current_guess[i].color = "Yellow";  
        }
    }

    return current_guess;
}


bool VerifyWords::checkColor() {
    bool check = true;
    for (int i = 0; i < 5; i++) {
        if (last_guess[i].color == "Green" && current_guess[i].letter != last_guess[i].letter) {
            return false;
        }

        else if (last_guess[i].color == "Yellow") {
            for (int j = 0; j < 5; j++) {
                if (last_guess[i].letter != current_guess[j].letter) {
                    check = false;
                }
                else {
                    check = true;
                    break;
                }
            }
            if (check == false) {
                return false;
            }
        }
    }

    return true;
}

