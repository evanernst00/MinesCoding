/* CSCI 200: Lab 3: Decipher the secret message
 *
 * Author: Evan Ernst
 *
 * Read an input file, apply a series of filters to transform the contained text, and output the deciphered text to another file.
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream secretMessage("secretMessage.txt");
    ofstream decipheredMessage("decipheredMessage.txt");

    if (secretMessage.fail() ) {
        cerr << "Error opening input file";
        return -1;
    }
    if (decipheredMessage.fail() ) {
        cerr << "Error opening input file";
        return -1;
    }

    char c;
    while(!secretMessage.eof()) {
        secretMessage.get(c);
        switch(c)
        {
            case '~':
                decipheredMessage << " ";
                break;
            case '\n':
                decipheredMessage << "\n";
                break;
            default:
                decipheredMessage << (char)(c+1);
                break;
        }
    }

    secretMessage.close();
    decipheredMessage.close();

    return 0;
}
