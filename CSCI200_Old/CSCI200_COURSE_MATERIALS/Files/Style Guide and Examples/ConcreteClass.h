// place header guards around all your header files
// make the name of the file the name of the value to test for
// use UPPER_SNAKE_CASE for your definition value
#ifndef CONCRETE_CLASSNAME_H                 // ask compiler if CONCRETE_CLASSNAME_H has been defined
#define CONCRETE_CLASSNAME_H                 // if not, define CONCRETE_CLASSNAME_H

// place a single Class declaration into its own file

#include "AbstractClass.h"

class ArrayInt final : public AListInt {      // class names follow UpperCamelCase
                                             // use public inheritance to follow the exposed interface of the parent class
                                             // mark concrete classes as final to close them
public:
  /**
   * @brief Construct a new ArrayInt object
   * @desc initializes a new ArrayInt
   */
  ArrayInt();

  /**
   * @brief Destroy the ArrayInt object
   * @desc deletes the internal array
   */
  ~ArrayInt();

  /**
   * @brief returns the value at a given position
   * 
   * @param POS position to retrieve
   * @return int value at POS
   * @throws std::out_of_range if POS is not within [0, size)
   */
  int get(const int POS) const override final;

  /**
   * @brief add an integer value to the list
   * @desc inserts the corresponding value immediately before the specified position.
   *   list size is increased by one
   * @param POS position to insert before
   * @param VAL value to insert
   */
   void insert(const int POS, const int VAL) override final;    // mark concrete functions as overridden and final

  /**
   * @brief removes the value at the corresponding position
   * @desc if the position is within range, removes the corresponding element.  list size
   *   is decreased by one
   * @param POS position to remove at
   */
  void remove(const int POS) override final;  // mark concrete functions as overridden and final
private:
  int* _pArray;                              // derived classes can add their own additional members
};

#endif // CONCRETE_CLASSNAME_H               // ends the corresponding #ifndef