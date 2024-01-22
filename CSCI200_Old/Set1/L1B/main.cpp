/* CSCI 200: Lab 1B: Generate a random value based on user inputs
 *
 * Author: Evan Ernst
 *
 * Prompt user for  values to generate a random value between, generate it, and determine what quarter of the range the value lies in.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cstdlib>
#include <ctime>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
    srand(time(0));

    int min, max;
    float random;
    char cont = 'y';

    // Prompt user for min and max values
    cout << "Enter a minimum value: ";
    cin >> min;
    cout << endl;
    cout << "Enter a maximum value: ";
    cin >> max;
    cout << endl;

    float difference = (float) (max-min);
    
    while((char) tolower(cont) == 'y')
    {
        random = (rand() / (float) RAND_MAX) * difference + (float) min;
        cout << random << endl;

        cout << "Your number is in the ";
        if(random <= difference * 0.25)
        {
            cout << "first quartile." << endl;
        }
        else if (random <= difference * 0.5)
        {
            cout << "second quartile." << endl;
        }
        else if (random <= difference * 0.75)
        {
            cout << "third quartile." << endl;
        }
        else
        {
            cout << "fourth quartile." << endl;
        }

        cout << "Would you like another number? (Y/N) ";
        cin >> cont;
        cout << endl;
    }

    return 0; // signals the operating system that our program ended OK.
}
