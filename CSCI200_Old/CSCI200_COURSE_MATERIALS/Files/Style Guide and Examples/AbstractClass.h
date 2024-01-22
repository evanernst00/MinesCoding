// place header guards around all your header files
// make the name of the file the name of the value to test for
// use UPPER_SNAKE_CASE for your definition value
#ifndef ABSTRACT_CLASSNAME_H                 // ask compiler if ABSTRACT_CLASSNAME_H has been defined
#define ABSTRACT_CLASSNAME_H                 // if not, define ABSTRACT_CLASSNAME_H

#include "Comparable.h"

// place a single Class declaration into its own file

// abstract classes begin with an A
class AListInt : public IComparable {                              // class names follow UpperCamelCase
public:
  /**
   * @brief initialize list size to zero
   * @desc initializes list size to zero
   */
  AListInt();

  /**
   * @brief Destroy the AListInt object
   * @desc Abstract classes must have a virtual destructor
   */
  virtual ~AListInt();

  /**
   * @brief returns the size of the list
   * @desc returns the size of the list
   * @return list size
   */
  int getSize() const;

  /**
   * @brief returns the value at a given position
   * 
   * @param POS position to retrieve
   * @return int value at POS
   * @throws std::out_of_range if POS is not within [0, size)
   */
  virtual int get(const int POS) const = 0;

  /**
   * @brief add an integer value to the list
   * @desc inserts the corresponding value immediately before the specified position.
   *   list size is increased by one
   * @param POS position to insert before
   * @param VAL value to insert
   */
  virtual void insert(const int POS, const int VAL) = 0;    // create an abstract function with no definition

  /**
   * @brief removes the value at the corresponding position
   * @desc if the position is within range, removes the corresponding element.  list size
   *   is decreased by one
   * @param POS position to remove at
   */
  virtual void remove(const int POS) = 0;    // create a pure virtual function with no definition

  /**
   * @brief prints the contents of the list deliminated by spaces
   * 
   * @return std::string string representation of list
   */
  std::string toString() const override final;

  /**
   * @brief compares if contents of lists are equivalent by checking their string representation
   * 
   * @return true if strings are equal
   * @return false otherwise
   */
  bool equals(const IComparable&) const override final;

protected:
  int mSize;                                 // protected data members begin with m
};

#endif // ABSTRACT_CLASSNAME_H               // ends the corresponding #ifndef