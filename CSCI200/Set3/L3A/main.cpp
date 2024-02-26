#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream myCatsAgesIn("filename"); // declare ifstream object and open the file

    // check for an error
    if ( myCatsAgesIn.fail() ) {
        cerr << "Error opening input file";
        return -1;
    }

    // read the data and do something with it
    int age;
    while( !myCatsAgesIn.eof() ) {
        myCatsAgesIn >> age;
        cout << "One cat is " << age << " years old.\n";
    }

    myCatsAgesIn.close(); // close the file
    return 0;
}