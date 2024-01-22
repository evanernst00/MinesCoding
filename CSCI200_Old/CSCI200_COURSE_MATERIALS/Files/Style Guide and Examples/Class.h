// place header guards around all your header files
// make the name of the file the name of the value to test for
// use UPPER_SNAKE_CASE for your definition value
#ifndef CLASSNAME_H                 // ask compiler if CLASSNAME_H has been defined
#define CLASSNAME_H                 // if not, define CLASSNAME_H

// place a single Class declaration into its own file

class Calculator {                  // class names follow UpperCamelCase
public:
  /**
   * @brief creates a default calculator
   * @desc Creates a default calculator with both operands set to 1
   */
  Calculator();                     // provide a default constructor
  /**
   * @brief creates a default calculator
   * @desc Creates a default calculator with both operands set to 1
   * @param LHS left hand side of calculation
   * @param RHS right hand side of calculation
   */
  Calculator(const double, const double);       // provide a parameterized constructor

  // create The Big Three if appropriate for memory management
  // Calculator(const Calculator&);             // copy constructor
  // ~Calculator();                             // destructor
  // Calculator& operator=(const Calculator&);  // copy assignment operator

  // create getters and setters (if appropriate) for your private data members
  /**
   * @brief return the left hand side operand
   * @return value of left hand side operand
   */
  double getLeftHandSide() const;   // getters are const functions
  /**
   * @brief set the left hand side operand
   * @param LHS value of left hand side operand
   */
  void setLeftHandSide(const double);

  /**
   * @brief return the right hand side operand
   * @return value of right hand side operand
   */
  double getRightHandSide() const;
  /**
   * @brief set the right hand side operand
   * @param RHS value of right hand side operand
   */
  void setRightHandSide(const double);

  // add any other related functions and mark as const if they do not change the callee
  /**
   * @brief return the sum of the operands
   * @return LHS + RHS
   */
  double add() const;
  /**
   * @brief return the difference of the operands
   * @return LHS - RHS
   */
  double subtract() const;
  /**
   * @brief return the product of the operands
   * @return LHS * RHS
   */
  double multiply() const;
  /**
   * @brief return the division of the operands
   * @return LHS / RHS
   */
  double divide() const;

private:
  double _leftHandSide;             // private members begin with m
  double _rightHandSide;
};

#endif // CLASSNAME_H               // ends the corresponding #ifndef