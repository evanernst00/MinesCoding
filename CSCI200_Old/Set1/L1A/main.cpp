/* CSCI 200: Lab 1A: Calculate the result of two mathematical equations based on user values
 *
 * Author: Evan Ernst
 *
 * User inputs values for various variables used in an equation, then the equation is calculated and the result is outputted. This should be repeated twice.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

#include <cmath>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;


// Define any constants below this comment.

const float PI = 3.141592653;

// Must have a function named "main", which is the starting point of a C++ program.
int main()
{
    // Ohm's law
    float resistance;
    float current;

    cout << "Input current: ";
    cin >> current;
    cout << endl;
    cout << "Input resistance: ";
    cin >> resistance;
    cout << endl;

    cout << "The Voltage is: " << resistance/current << endl;

    // Volume of a sphere
    float radius;

    cout << "Input radius: ";
    cin >> radius;
    cout << endl << (4.0/3.0)*PI*radius*radius*radius << endl;

    return 0; // signals the operating system that our program ended OK.
}