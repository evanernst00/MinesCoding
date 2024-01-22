#include "AbstractClass.h"

#include <iostream>
using namespace std;

AListInt::AListInt() {
  cout << "AListInt() called" << endl;
  mSize = 0;
}

AListInt::~AListInt() {
  cout << "~AListInt() called" << endl;
}

int AListInt::getSize() const {
  return mSize;
}

std::string AListInt::toString() const {
  string str = "";
  for(int i = 0; i < mSize; i++) {
    str += to_string( get(i) );
    if(i != mSize - 1) {
      str += " ";
    }
  }
  return str;
}

bool AListInt::equals(const IComparable& OTHER) const {
  return this->toString() == OTHER.toString();
}