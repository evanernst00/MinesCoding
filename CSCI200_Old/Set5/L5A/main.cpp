/* CSCI 200: Lab 5A: Escape room roleplayer
 *
 * Author: Evan Ernst
 *
 * You are in an escape room and as you navigate the rooms, you can either find the exit or find a room in which you have
 * to guess a number, and then you escape!
 */

#include "GuessTheNumberRoom.h"
#include "ExitRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

ARoom* go_to_next_room() {
    int randRoomChoice = rand() % 10; // a 10% chance to get directly out
    switch(randRoomChoice) {
    case 7:     return new GuessTheNumberRoom();
    default:    return new ARoom();
    }
}

int main() {
    srand( time(0) );
    rand();

    ARoom *currentRoom;

    do {    
        currentRoom = go_to_next_room();
        cout << "Welcome to the " << currentRoom->getRoomName() << endl;
    } while( !currentRoom->escapeTheRoom() );

    cout << "You made it out!" << endl;

    return 0;
}