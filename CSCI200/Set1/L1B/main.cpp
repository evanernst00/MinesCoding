/* CSCI 200: Lab 1B: L1B - Quartile analysis of random number
 *
 * Author: XXXX (INSERT_NAME)

 * Ask for max and min, generate a random number between those two, and tell which quartile the number falls between. Repeat until the user is done.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
Enter the minimum value: 1
Enter the maximum value: 10
A random value is: 2.1
This is in the first quartile
Do you want another random value? (Y/N) Y
A random value is: 5.83
This is in the third quartile
Do you want another random value? (Y/N) Y
A random value is: 1.33
This is in the first quartile
Do you want another random value? (Y/N) N
Have a nice day!
*/

int main()
{
    double min = 0, max = 0;
    double value = 0;
    string repeat = "";

    cout << "Enter the minimum value: ";
    cin >> min;
    cout << "Enter the maximum value: ";
    cin >> max;

    while(true)
    {
        srand(time(0));

        
        value = (rand() / static_cast<double>(RAND_MAX)) * (max-min) + min;
        cout << "A random value is: " << value << endl;


        value = (value-min)/(max-min);
        if(value <= 0.25)
        {
            cout << "This is in the first quartile" << endl;
        }
        else if (value <= 0.5)
        {
            cout << "This is in the second quartile" << endl;
        }
        else if (value <= 0.75)
        {
            cout << "This is in the third quartile" << endl;
        }
        else
        {
            cout << "This is in the fourth quartile" << endl;
        }


        cout << "Do you want another random value? (Y/N) ";
        cin >> repeat;
        if(repeat == "N" || repeat == "n")
        {
            break;
        }
    }

    cout << "Have a nice day!" << endl;

    return 0;
}
