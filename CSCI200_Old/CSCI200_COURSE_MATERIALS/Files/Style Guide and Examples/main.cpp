// this is a single line comment

/*
 *  this is a block comment that
 *  can span several lines
 */

// place all header files you've written together, in alphabetical order
// include only the header files you need
#include "AbstractClass.h"
#include "Class.h"
#include "ConcreteClass.h"
#include "Functions.h"
#include "Template.hpp"

// place all C++ standard libraries together, in alphabetical order
// include only the libraries you need
#include <fstream>          // for file streams (ifstream, ofstream)
#include <iomanip>          // for I/O Manipulators (precision, aligning, etc.)
#include <iostream>         // for standard input/output
#include <string>           // for string library
#include <vector>           // for vector library
using namespace std;        // we are using the standard namespace

// place all C standard libraries together, in alphabetical order
// include only the libraries you need
#include <cctype>           // for tolower(), isalpha(), etc.
#include <cmath>            // for sqrt(), pow(), sin(), etc.
#include <cstdlib>          // for srand(), rand()
#include <ctime>            // for time()

/*
 * any variables defined above main() are in global scope and can be
 *  accessed anywhere.  This is generally BAD.
 * Only declare & define constants in global scope.
 * Constants are named using UPPER_SNAKE_CASE to denote it as an
 * immutable value
 */
const double PI_VALUE = 3.1415926535;

// structs are named using UpperCamelCase to denote it is a datatype
struct ClassRoom {
  string buildingName;
  int roomNumber;
};

// every program must have a main() function
//  - it is the entry point to our program
int main(int argc, char* argv[]) {  // the curly brace begins a new code block
  srand( (unsigned int)time(0) );   // seed the RNG - do this once per program as first statement

  // indent the contents of a code block two spaces length

  // main() accepts parameters corresponding to the command line arguments
  // used to call and start the program
  // argc holds how many arguments there are
  cout << "Program run with " << argc << " arguments:" << endl;
  for(int i = 0; i < argc; i++) {
    // argv contains each argument in an array of C-strings
    cout << "\t" << i << ": " << argv[i] << endl;
  }

  // Template for variable declaration
  //        anything inside of [brackets] is optional
  // Version1: [modifiers] dataType identifierName [= initialValue];
  // Version2: [modifiers] dataType identifierName[(initialValue)];

  int ageOfColosseum;               // declare a variable
                                    // use lowerCamelCase to make a descriptive variable name
  ageOfColosseum = 1940;            // define a variable (assign a value)

  int numRomanEmperors = 71;        // declare and define a variable in one line

  const int VATICAN_BUILT = 1626;   // declare and define a constant
                                    // must define a constant when it is declared
                                    // use UPPER_SNAKE_CASE to make a descriptive constant name

  // declare (and define) multiple variables of the same type at once
  char firstInitial = 'I', secondInitial('C'), currentEmperorInitial;
  
  // characters can be added to advance
  currentEmperorInitial = firstInitial + 1;

  cout << "There have been " << numRomanEmperors << " emperors and the current is "
       << currentEmperorInitial << "." << secondInitial << "."
       << endl;

  cout << "The Colosseum was built in 70-80 A.D. and is "
       << ageOfColosseum << " years old." << endl;
  cout << endl;

  // when  prompting the user to enter a value via cin, preceed the input with a prompt
  //    using cout so the user knows what to enter
  int currentYear;
  cout << "Please enter the current 4 digit year (e.g. 1999): ";
  cin >> currentYear;
  cout << "St. Peter's Basilica was built in " << VATICAN_BUILT
       << " and is " << (currentYear - VATICAN_BUILT) << " years old." << endl;

  if( currentYear >= 2400 ) {
    // indent the contents of a new code block
    cout << "Duck Dodgers of the 24th and a Half Century!" << endl;
  } else if( currentYear >= 2000 ) {    // place else if and else on the same line the prior code block ends
    cout << "In the year 2000, robots will do 80% of the work. - Conan O'Brien." << endl;
  } else {
    // use curly braces to denote a code block for if/else if/else even if the code
    //     block only has one statement
    cout << "Let's party like it's 1999. - Prince" << endl;
  }

  for( int i = 0; i < 10; i++ ) {
    // indent the contents of a new code block
    // use a code block for a for loop even if it contains only a single statement
    cout << i << endl;
  }

  char userResponse;
  do {
    cout << "Enter a letter (q to quit): ";
    cin >> userResponse;
  } while( userResponse != 'q' );   // place the while on the same line as the end of the do

  // be aware of floating point precision and output
  cout << "PI was assigned:    3.1415926535" << endl;
  cout << "Our value of PI is: " << PI_VALUE << endl;
  cout << "Our value of PI is: " << setprecision(10) << PI_VALUE << endl;
  cout << "Our value of PI is: " << setprecision(20) << PI_VALUE << endl;

  // for function calls, add spaces within the () and after each argument
  cout << "5 + 3 = " << calculator_add( 5, 3 ) << endl;
  cout << "5 - 3 = " << calculator_sub( 5, 3 ) << endl;

  ClassRoom lectureLab;             // create a variable of our custom struct type
  lectureLab.buildingName = "Brown";// access components of a structure using dot operator
  lectureLab.roomNumber = 316;

  cout << "The length of the building name is: "
       << lectureLab.buildingName.length() // access string functions with dot operator
       << endl;

  // Template for vector declaration
  //        anything inside of [brackets] is optional
  // Version1: [const] vector< dataType > identifierName;
  // Version2: [const] vector< dataType > identifierName[(initialSize)];
  // Version3: [const] vector< dataType > identifierName[(initialSize, initialValue)];
  vector<int> numbers;              // create an empty vector of integers
  numbers.push_back( 5 );           // add the value 5 to the vector
  numbers.at( 0 ) = 6;              // access individual elements using the at() function

  Calculator fourFunctionCalc( 4.5, 3.5 );  // object names follow lowerCamelCase
  cout << fourFunctionCalc.getLeftHandSide() << " + " << fourFunctionCalc.getRightHandSide() << " = "
       << fourFunctionCalc.add() << endl;
  fourFunctionCalc.setLeftHandSide( 13.0 );
  fourFunctionCalc.setRightHandSide( 1.5 );
  cout << fourFunctionCalc.getLeftHandSide() << " / " << fourFunctionCalc.getRightHandSide() << " = "
       << fourFunctionCalc.divide() << endl;

  unsigned int arraySize;
  cout << "How many elements do you have? ";
  cin >> arraySize;

  // pointer variables begin with a p and follow lowerCamelCase style
  int* pArray = new int[arraySize];      // allocate an array of integers
  for( unsigned int i = 0; i < arraySize; i++ ) {
    cout << "Enter array value: ";
    cin >> pArray[i];
  }
  delete[] pArray;                       // deallocate the array of integers

  cout << "3 + 4 = "
       << apply_add_operator( 3, 4 ) << endl;

  cout << "\"Hello,\" + \"World\" = "
       << apply_add_operator( string("Hello,"), string("World") ) << endl;

  cout << "0.5 + 0.25 = "
       << apply_add_operator( 0.5f, 0.25f ) << endl;

  AListInt* const P_list = new ArrayInt();// declare pointer as abstract type and point at concrete instance
                                         // pointer is constant and will not point at anything different

  try {
    P_list->insert( 0, 5 );                // list contents: 5
    P_list->insert( 1, 7 );                // list contents: 5 7
    cout << "List size is " << P_list->getSize() << endl;  // prints 2
    cout << "List contents are " << P_list->toString() << endl;
    P_list->remove( 0 );                    // list contents: 7
    cout << "List contents are " << P_list->toString() << endl;
  } catch (out_of_range e) {
    cerr << "Array implementation is incomplete! " << e.what() << endl;
  }
  delete P_list;

  return 0;                              // alert the OS our program exited with result 0 (success)
}   // the curly brace ends the code block that it corresponds to
    // every open brace needs a matching end brace