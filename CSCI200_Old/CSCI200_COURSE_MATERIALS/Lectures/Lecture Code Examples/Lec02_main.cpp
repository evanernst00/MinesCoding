#include <iostream>
using namespace std;

int main() {
    // data type AND name/identifier
    // declaration
    int numWindows;     // lowerCamelCase
    // deferred initialization
    numWindows = 8;

    // declare & initialize at once
    int numDoors026 = 2, numDoors022 = 2;
    int numChairs = 63, numMonitors(121);

    int int1;

    cout << "Hello World!" << endl; 
    cout << "How are you?" << endl;
    cout << 3 + 1 << endl;
    cout << '3' + 1 << endl;
    cout << 3.1f << endl;
    cout << "There are " << numWindows << " windows in the room" << endl;

    cout << "How many chairs are there today? ";
    cin >> numChairs;
    cout << "Thanks, there are " << numChairs << " today" << endl;

    return 0;
}