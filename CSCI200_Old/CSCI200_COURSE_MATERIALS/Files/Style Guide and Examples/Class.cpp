#include "Class.h"          // include the file with the corresponding prototypes

Calculator::Calculator() {
  _leftHandSide = 1.0;
  _rightHandSide = 1.0;
}

Calculator::Calculator(const double LHS, const double RHS) {
  _leftHandSide = LHS;
  _rightHandSide = RHS;
}

double Calculator::getLeftHandSide() const {
  return _leftHandSide;
}
void Calculator::setLeftHandSide(const double LHS) {
  _leftHandSide = LHS;
}

double Calculator::getRightHandSide() const {
  return _rightHandSide;
}
void Calculator::setRightHandSide(const double RHS) {
  _rightHandSide = RHS;
}

double Calculator::add() const {
  return _leftHandSide + _rightHandSide;
}

double Calculator::subtract() const {
  return _leftHandSide - _rightHandSide;
}

double Calculator::multiply() const {
  return _leftHandSide * _rightHandSide;
}

double Calculator::divide() const {
  if( _rightHandSide != 0 ) {
    return _leftHandSide / _rightHandSide;
  } else {
    return 0.0;
  }
}