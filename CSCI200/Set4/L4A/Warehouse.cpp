#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse() {
    _pBoxen = new vector<Box*>;
}

Warehouse::~Warehouse() {
    for(size_t i = 0; i < _pBoxen->size(); i++) {
        delete _pBoxen->at(i);
    }
    _pBoxen->clear();
    delete _pBoxen;
}

Warehouse::Warehouse(const Warehouse& OTHER) {
    _pBoxen = new vector<Box*>;
    
    // Deep copy other Warehouse
    for(int i = 0; i < OTHER.getNumberOfBoxes(); i++) {
        _pBoxen->push_back(new Box(OTHER.getBox(i)->getBoxSize()));
    }
}

void Warehouse::storeInBox(const int SIZE) {
    _pBoxen->push_back( new Box(SIZE) );
}

Box* Warehouse::getBox(const int BOX_POS) const {
    return _pBoxen->at(BOX_POS);
}

int Warehouse::getNumberOfBoxes() const {
    return _pBoxen->size();
}

std::ostream& operator<<(ostream& os, const Warehouse& WH) {
    os << "Warehouse has " << WH.getNumberOfBoxes() << " boxes (";
    for(int i = 0; i < WH.getNumberOfBoxes(); i++) {
        os << WH.getBox(i)->getBoxSize();
        if(i < WH.getNumberOfBoxes() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

Warehouse& Warehouse::operator=(const Warehouse& OTHER) {
    // Deallocate this Warehouse
    for(size_t i = 0; i < _pBoxen->size(); i++) {
        delete _pBoxen->at(i);
    }
    _pBoxen->clear();

    // Deep copy other Warehouse
    for(int i = 0; i < OTHER.getNumberOfBoxes(); i++) {
        _pBoxen->push_back(new Box(OTHER.getBox(i)->getBoxSize()));
    }

    return *this;
}