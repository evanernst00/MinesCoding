#include <iostream>

using namespace std;

int main() {
  
  // demonstrate pointer function
  double a = 13.0;
  double* pA = &a;

  if(&a == pA)
  {
    cout << "&a == pA" << endl;
  }
  if(*&a == *pA)
  {
    cout << "*&a == *pA" << endl;
  }

  /*
  Demonstrate the purpose of pointers:
  
  Instead of using pointers to point to values in the stack, 
  which variables already do, we can allocate and reference 
  memory on the Free Store or Heap using pointers.

  */

  // Stores an int in the stack
  int pizzaSlices = 10;

  int* pPieSlices = new int;
  *pPieSlices = 10;

  delete pPieSlices; // delete the address we were using, give it back to the Free Store

  return 0;
}
