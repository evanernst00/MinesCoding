// place header guards around all your header files
// make the name of the file the name of the value to test for
// use UPPER_SNAKE_CASE for your definition value
#ifndef COMPARABLE_H                 // ask compiler if COMPARABLE_H has been defined
#define COMPARABLE_H                 // if not, define COMPARABLE_H

#include <string>

// interfaces begin with an I
class IComparable {                              // class names follow UpperCamelCase
public:
    virtual ~IComparable() {}                    // interfaces must have a virtual destructor implementation

    /**
     * @brief converts the object to a string representation
     * 
     * @return std::string holding the object information
     */
    virtual std::string toString() const = 0;

    /**
     * @brief determines if two objects are equivalent
     * 
     * @return true if objects are equivalent
     * @return false otherwise
     */
    virtual bool equals(const IComparable&) const = 0;
};

#endif//COMPARABLE_H