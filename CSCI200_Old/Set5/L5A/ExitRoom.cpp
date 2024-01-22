#include "ExitRoom.h"

#include <iostream>
using namespace std;

ExitRoom::ExitRoom() {
    cout << "ExitRoom() called" << endl;
}

ExitRoom::~ExitRoom() {
    cout << "~ExitRoom() called" << endl;
}

bool ExitRoom::escapeTheRoom() {
    cout << "You escaped!" << endl;

    return true;
}