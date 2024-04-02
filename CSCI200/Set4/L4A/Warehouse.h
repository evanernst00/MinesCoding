#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Box.h"

#include <ostream>
#include <vector>

/**
 * @brief takes in sized things and puts them into boxes.  stores
 * all the boxes internally
 * 
 */
class Warehouse {
public:
    /**
     * @brief Construct a new Warehouse object with
     * no boxes by default
     * 
     */
    Warehouse();
    /**
     * @brief Deconstruct the Warehouse object
     * 
     */
    ~Warehouse();
    /**
     * @brief Copy constructor
     * @param OTHER pass by reference a Warehouse to deep copy
     */
    Warehouse(const Warehouse& OTHER);
    /**
     * @brief puts the item into a Box of given size
     * @param SIZE size of the cube shaped box to store
     */
    void storeInBox(const int SIZE);
    /**
     * @brief Get the Box object at given position within the list
     * @param BOX_POS position within the list to retrieve
     * @return Box* pointer to the corresponding Box object
     */
    Box* getBox(const int BOX_POS) const;
    /**
     * @brief Get the Number Of Boxes object
     * 
     * @return int 
     */
    int getNumberOfBoxes() const;

    /**
     * @brief Copy assignment operator
     * 
     * @param OTHER 
     * @return Warehouse& Warehouse to copy
     */
    Warehouse& operator=(const Warehouse& OTHER);
private:
    /**
     * @brief holds a list of pointers to Boxes
     * 
     */
    std::vector<Box*>* _pBoxen;
};

std::ostream& operator<<(std::ostream&, const Warehouse&);

#endif//WAREHOUSE_H