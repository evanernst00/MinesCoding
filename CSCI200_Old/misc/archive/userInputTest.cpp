#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // Output random value
    int x = rand();
    cout << "Here's a random number//: " << x << endl;

    // Take min and max and output random number in specified range
    int min;
    int max;
    cout << "Input a min value: ";
    cin >> min;
    cout << endl << "Input a max value: ";
    cin >> max;
    cout << endl << "Here's a random number between min and max: " << rand() % (max - min + 1) + min;
}