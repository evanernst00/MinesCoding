/* CSCI 200: Lab 1A: Perform predetermined calculations
 *
 * Author: Evan Ernst
 *
 * Take input for variables for two pre-programmed equations, and print the result
 */

#include <iostream>
#include <cmath>
using namespace std;

const double k = 9.0 * pow(10, 9); // Coulomb's constant in air

int main()
{

    double q1, q2, r;
    cout << "Coulomb's Law \nInput a value for q1: ";
    cin >> q1;
    cout << "Input a value for q2: ";
    cin >> q2;
    cout << "Input a value for r: ";
    cin >> r;

    cout << "Here is the result: " << (k * q1 * q2)/(r*r) << endl;

    double x, y;
    cout << "Distance Calculation \nInput a value for x: ";
    cin >> x;
    cout << "Input a value for y: ";
    cin >> y;

    cout << "Here is the result: " << sqrt(x*x + y*y) << endl;

    return 0;
}
