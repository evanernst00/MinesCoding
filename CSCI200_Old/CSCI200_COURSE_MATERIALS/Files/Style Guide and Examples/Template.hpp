// place header guards around all your header files
// make the name of the file the name of the value to test for
// use UPPER_SNAKE_CASE for your definition value
#ifndef TEMPLATE_HPP                 // ask compiler if TEMPLATE_HPP has been defined
#define TEMPLATE_HPP                 // if not, define TEMPLATE_HPP

// when a function or class is templated, its type cannot be known with the corresponding
// usage.  place the corresponding declaration and definition together in a single
// hpp file to denote
//   *.h*  - this is a header file containing declarations
//   *.*pp - this file contains definitions

// place the definitions at the top of the follow to maintain abstraction

/**
 * @brief resolves the binary plus operator for two values of the same type
 * @desc resolves the binary plus operator for two values of the same type as long
 * as the operator is defined for the correspond type
 * @param VAL_ONE left hand side of addition
 * @param VAL_TWO right hand side of addition
 * @return VAL_ONE + VAL_TWO
 */
template<typename T>
T apply_add_operator(const T VAL_ONE, const T VAL_TWO);

//----------------------------------------------------------------------------

// place the corresponding function declarations below to maintain abstraction

template<typename T>
T apply_add_operator(const T VAL_ONE, const T VAL_TWO) {
  return VAL_ONE + VAL_TWO;
}

#endif // TEMPLATE_HPP               // ends the corresponding #ifndef