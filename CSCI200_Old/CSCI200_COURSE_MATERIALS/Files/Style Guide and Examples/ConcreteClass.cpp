#include "ConcreteClass.h"          // include the file with the corresponding prototypes

#include <exception>
#include <iostream>
#include <string>
using namespace std;

ArrayInt::ArrayInt() {
  cout << "ArrayInt() called" << endl;
  _pArray = nullptr;
}

ArrayInt::~ArrayInt() {
  cout << "~ArrayInt() called" << endl;
  delete _pArray;
}

int ArrayInt::get(const int POS) const {
  if(_pArray == nullptr) {
    string msg = "array is uninitialized";
    throw out_of_range(msg);
  }
  if(POS < 0 || POS >= mSize) {
    string msg = to_string(POS);
    msg += " is out of range for array of length ";
    msg += to_string(mSize);
    throw out_of_range(msg);
  }
  return _pArray[POS];
}

void ArrayInt::insert(const int POS, const int VAL) {
  // provide proper implementation
  mSize++;
  if(_pArray != nullptr) _pArray[POS] = VAL;
}

void ArrayInt::remove(const int POS) {
  // provide proper implementation
  mSize--;
  if(_pArray != nullptr) _pArray[POS] = _pArray[POS];
}