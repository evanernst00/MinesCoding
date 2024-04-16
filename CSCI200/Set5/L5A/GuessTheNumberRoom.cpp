#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;

    string mRoomName = "Guess the Number Room";
    _secretNumber = rand() % 20 + 1;
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}

bool GuessTheNumberRoom::escapeTheRoom() {
    
    int guesses = 0;
    int guess;
    
    while(guesses < 5) {
        cout << "Guess a number between 1 and 20: ";
        cin >> guess;

        if( guess == _secretNumber ) {
            cout << "You've guessed the number!" << endl;
            return true;
        } else {
            cout << "Try again" << endl;
            guesses++;
        }
    }

    cout << "You've run out of guesses" << endl;
    return false;
}
