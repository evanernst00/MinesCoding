#include <iostream>
#include <vector>
using namespace std;

// Box objects have a size
class Box
{
public:
    Box(const int SIZE)
    {
        _size = SIZE;
    }
    int getBoxSize()
    {
        return _size;
    }
private:
    // Box size
    int _size;
};

// Warehouse object stores a list of boxes on the free store using pointers
class Warehouse
{
public:
    Warehouse()
    {
        _pBoxen = new vector<Box*>;
    }
    // Adds a Box object to "the warehouse" or vector
    void storeInBox(const int SIZE)
    {
        // (_pBoxen*).push_back(new Box(SIZE+1));
        _pBoxen->push_back(new Box(SIZE+1));
    }
    // Gets a box in the warehouse/vector
    Box* getBox(const int POS)
    {
        return _pBoxen->at(POS);
    }
    int getNumberBoxes() const
    {
        return _pBoxen->size();
    }
private:
    /* This is a pointer called _pBoxen, pointing to a vector
    The vector is stored on the free store and contains pointers to Box objects */
    vector<Box*>* _pBoxen;

    // // Allows printing out the object itself
    // ostream& operator<< (const Warehouse& WH)
    // {
    //     ostream& os;
    //     os << "Warehouse has " << WH.getNumberBoxes() << " boxes";
    //     return os;
    // }
};

int main()
{
    Warehouse* pWarehouseH = new Warehouse();
    pWarehouseH->storeInBox(4);
    
    cout << pWarehouseH->getBox(0)->getBoxSize() << endl;

    return 0;
}


