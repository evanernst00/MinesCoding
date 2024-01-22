/* CLI and Makefiles
 *   cin
 *   Random Numbers
 *   Makefiles
 */

#include <iostream>
#include <cstdlib> // c standard library
#include <ctime> // c time library
using namespace std;

double randomP();
double uniform(double min, double max);
int randInt(int min, int max);

int main() {
    cout << "Random numbers with cstdlib" << endl;

    cout 
        << "Random float between 0 and 1: "
        << randomP()
        << endl;

    double minD = 3.141592653;
    double maxD = minD * 2;

    cout 
        << "Random float between " << minD << " and " << maxD << ": "
        << uniform(minD, maxD) 
        << endl;

    int minI = 69;
    int maxI = 420;

    cout 
        << "Random integer between " << minI << " and " << maxI << ": " 
        << randInt(minI, maxI) 
        << endl;

    return 0;
}

double randomP()
{
    srand(time(0));

    // rand() returns a number between 0 and RAND_MAX
    // To get a number between 0 and 1, divide the random number by RAND_MAX
    return rand() / static_cast<double>(RAND_MAX);
}

double uniform(double min, double max)
{
    srand(time(0));

    // min inclusive, max exclusive
    double rangeSize = max - min;

    return randomP() * rangeSize + min;
}

int randInt(int min, int max)
{
    srand(time(0));

    // min inclusive, max exclusive
    int rangeSize = max - min;

    /*
     * The modulo operator divides the left by the right, then returns the remainder.
     * 
     * left % right = a number less than the right
     * 
     * So as a principle, if you don't know what the left is, you can guarantee it will be less than the right.
     * So make the left random, then choose how large the range to limit it to.
     * Finally, add the minimum to put the final number in the correct range.
     */
    return rand() % rangeSize + min;
}