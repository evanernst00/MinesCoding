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

    // Output addresses of iNum and iNum2
    cout << "The address of iNum is: " << &iNum << endl;
    cout << "The address of iNum2 is: " << &iNum2 << endl;

    // Output iNum and iNum2 using pointers
    cout << "iNum == *pINum1 == " << *pINum1 << endl;
    cout << "iNum2 == *pINum2 == " << *pINum2 << endl;

    iNum = 6;
    cout << "iNum == " << iNum << endl;
    cout << "*pINum1 == " << *pINum1 << endl;

    *pINum1 = 7;
    cout << "iNum == " << iNum << endl;

    pINum2 = pINum1;
    cout << "pINum2 == " << pINum2 << endl;
    cout << "*pINum2 == " << *pINum2 << endl;
    *pINum2 = 8;
    cout << "*pINum1 == " << *pINum1 << ", *pINum2 == " << *pINum2 << ", iNum == " << iNum << endl;
    cout << "iNum2 == " << iNum2 << endl;

    double* pDNum = nullptr;
    // error: incompatible pointer types assigning to 'double *' from 'int *'
    // pDNum = &iNum;
    // error: incompatible pointer types assigning to 'double *' from 'int *'
    // pDNum = pINum1;
    double dNum = 14.25;
    pDNum = &dNum;
    cout << "pDNum == " << pDNum << ", *pDNum == " << *pDNum << endl;
    *pDNum = *pINum1; // int value converted to double
    cout << "dNum == " << dNum << ", *pDNum == " << *pDNum << endl;

    return 0;
}
