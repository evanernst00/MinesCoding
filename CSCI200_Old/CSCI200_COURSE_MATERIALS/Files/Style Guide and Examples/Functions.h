// place header guards around all your header files
// make the name of the file the name of the value to test for
// use UPPER_SNAKE_CASE for your definition value
#ifndef FUNCTIONS_H         // ask compiler if FUNCTIONS_H has been defined
#define FUNCTIONS_H         // if not, define FUNCTIONS_H

// place ALL function prototypes into the header file
// use lower_snake_case for top level free functions

/**
 * @brief adds two integers together
 * @desc Returns the integer sum of two integer parameters
 * @param x first operand to add
 * @param y second operand to add
 * @return sum of x and y
 */
int calculator_add( int x, int y );

/**
 * @brief subtracts two integers
 * @desc Returns the integer difference of y from x (x - y)
 * @param value to start with
 * @param value to subtract
 * @return difference of x and y
 */
int calculator_sub( int x, int y );

#endif // FUNCTIONS_H       // ends the corresponding #ifndef