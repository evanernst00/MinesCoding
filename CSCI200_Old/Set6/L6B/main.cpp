/* CSCI 200: Lab 6B: Implement a sort() member function in the Array and LinkedList classes
 *
 * Author: Evan Ernst
 *
 * Declare a virtual sort() function in the IList class, 
 * and implement it using merge sort in the Array and LinkedList classes
 */

#include <iostream>
#include <array>
#include <algorithm>
#include <cstdlib>

#include "test_suite.h"

#include "Array.hpp"
#include "LinkedList.hpp"

using namespace std;

int main() 
{
    int listType, n, min, max;
    cout << "Which list type would you like to use? \n1: Array \n2: Linked List\n";
    cin >> listType;
    cout << "How many integers would you like to use? ";
    cin >> n;
    cout << "Enter minimum value: ";
    cin >> min;
    cout << "Enter maximum value: ";
    cin >> max;
    cout << endl;

    // create list to test
    listType = std::min(std::max(listType, 0), 2); // clamp
    IList<int>* pList = nullptr;
    if(listType == 1) pList = new Array<int>();
    else if(listType == 2) pList = new LinkedList<int>();

    // populate list
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        pList->insert(0, (rand()%(max-min) + min));
    }

    pList->sort();
    cout << endl;

    int numSearches, searchVal;
    cout << "How many values would you like to search the list for? ";
    cin >> numSearches;
    cout << endl;

    for(int i=0; i<numSearches; i++)
    {
        cout << "Enter a value to search for: ";
        cin >> searchVal;
        cout << "Your value is at: " << pList->search(searchVal) << "\n" << endl;
    }

    return 0;
}