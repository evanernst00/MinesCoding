/* CSCI 200: Lab 2B: Pointers: Addresses and Values
 *
 * Author: Evan Ernst
 *
 * Description here
 */

#include <iostream>
using namespace std;

int main()
{
    int iNum(4);
    int iNum2(5);
    int* pINum1 = &iNum;
    int* pINum2 = &iNum2;

    cout << "The address of iNum is: " << pINum1 << endl;
    cout << "The address of iNum2 is: " << &iNum2 << endl;

    cout << "iNum == " << *pINum1 << endl;
    cout << "iNum2 == " << *pINum2 << endl;

    return 0;
}
