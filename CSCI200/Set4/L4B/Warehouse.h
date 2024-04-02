#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Box.h"

#include <ostream>
#include <vector>

/**
 * @brief takes in things and puts them into a list.  stores all the items internally
 */
class Warehouse {
public:
    /**
     * @brief Construct a new Warehouse object with no items by default
     */
    Warehouse();
    /**
     * @brief Don't allow a Warehouse to be copied
     */
    Warehouse(const Warehouse&) = delete;
    /**
     * @brief Don't allow a Warehouse to be copied
     */
    Warehouse& operator=(const Warehouse&) = delete;
    /**
     * @brief Destroy the Warehouse object
     */
    ~Warehouse();

    /**
     * @brief puts the item into the warhouse
     * @param ITEM item to store
     */
    void store(const int ITEM);

    /**
     * @brief Get the item at given position with the warehouse
     * @param ITEM_POS position to retrieve
     * @return Box& corresponding item
     */
    Box& retrieve(const size_t ITEM_POS) const;

    /**
     * @brief Get the Number Of items
     * @return int 
     */
    size_t getNumberOfItems() const;
private:
    /**
     * @brief holds a list of pointers to Boxes
     * 
     */
    std::vector<Box*>* _pItems;
};

std::ostream& operator<<(std::ostream&, const Warehouse&);

#endif//WAREHOUSE_H