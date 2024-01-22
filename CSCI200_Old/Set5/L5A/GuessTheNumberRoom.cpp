#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;

    _secretNumber = rand() % 20 + 1;
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}

bool GuessTheNumberRoom::escapeTheRoom() {
    while(true)
    {
        int guesses = 5;
        int guess;
        cout << "Guess a number between 1 and 20: ";
        cin >> guess;
        cout << endl;

        if(guess == _secretNumber) {
            cout << "You guessed it!" << endl;
            return true;
        } else if(guess <= _secretNumber) {
            cout << "You guessed low" << endl;
            guesses--;
        } else if(guess >= _secretNumber) {
            cout << "You guessed high" << endl;
            guesses--;
        }

        if(guesses <= 0) {
            cout << "You ran out of guesses" << endl;
            return false;
        }

    }
}