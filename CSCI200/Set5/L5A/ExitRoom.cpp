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
    cout << "You've escaped!" << endl;
    return true;
}
