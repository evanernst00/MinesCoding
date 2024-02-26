#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Input file
    ifstream secretMessage("secretMessage.txt");
    if(secretMessage.fail())
    {
        cerr << "Error opening input file";
        return -1;
    }
    cout << "secretMessage.txt opened" << endl;

    // Output file
    ofstream decipheredMessage("decipheredMessage.txt");
    if(decipheredMessage.fail())
    {
        cerr << "Error opening output file";
        return -1;
    }
    cout << "decipheredMessage.txt created" << endl;

    // Decipher message
    char currentChar;
    while(secretMessage.eof())
    {
        secretMessage >> currentChar;
        cout << "Reading current character: " << currentChar << endl;

        // Process current character and output to decipheredMessage.txt
        switch(currentChar)
        {
            case('\n'):
                decipheredMessage << endl;
                cout << "Outputting new line" << endl;
                break;
            case('~'):
                decipheredMessage << " ";
                cout << "Outputting space" << endl;
                break;
            default:
                currentChar++;
                cout << "Outputting shifted character: " << currentChar << endl;
                decipheredMessage << currentChar;
        }
    }

    secretMessage.close();
    decipheredMessage.close();
    return 0;
}