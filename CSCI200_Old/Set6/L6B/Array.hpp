#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class Array final : public IList<T> {
public:
    Array();
    ~Array();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;
    void sort() override;
    int search(T VALUE) const override;

private:
    void mergeSort(int left, int right, T* temp);
    void merge(int left, int middle, int right, T* temp);
    int searchBetween(T, int start, int end) const;

    int _size;
    T* _pArray;
    bool _printSort = true; // If true, print values at each point in array
};

//---------------------------------------------------------

template<typename T>
Array<T>::Array() {
    // set size to zero
    _size = 0;
    // set array to be a nullptr
    _pArray = nullptr;
}

template<typename T>
Array<T>::~Array() {
    // deallocate current array
    delete[] _pArray;
}

template<typename T>
int Array<T>::size() const { 
    return _size;
}

template<typename T>
T Array<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if(POS >= _size || POS < 0) {throw std::out_of_range("Position is out of range");}
    // return value at POS within array
    return _pArray[POS];
}

template<typename T>
void Array<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if(POS >= _size || POS < 0) {throw std::out_of_range("Position is out of range");}
    // set VALUE at POS within array    
    _pArray[POS] = VALUE;
}

template<typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    
    // int newPos = std::max(0, std::min(POS, _size));
    int newPos;
    if(POS < 0) {newPos = 0;}
    else if(POS > _size) {newPos = _size;}
    else newPos = POS;

    // create new array of size + 1
    T* temp = new T[_size+1];
    // copy elements 0 to POS from old array to new array
    for(int i=0; i<newPos; i++)
    {
        temp[i] = _pArray[i];
    }
    // set element at POS in new array to VALUE
    temp[newPos] = VALUE;
    // copy elements POS to size from old array to new array
    for(int i=newPos; i<_size; i++)
    {
        temp[i+1] = _pArray[i];
    }
    // delete old array
    delete[] _pArray;
    // set old array to be new array
    _pArray = temp;
    // increment size
    _size++;
}

template<typename T>
void Array<T>::remove(const int POS) {
    
    // if array is empty, throw std::out_of_range exception
    if(_size == 0) {throw std::out_of_range("Array is empty");}

    // make sure position parameter is valid
    int newPos;
    if(POS < 0) {newPos = 0;}
    else if(POS >= _size) {newPos = _size-1;}
    else newPos = POS;

    // create new array of size - 1
    T* temp = new T[_size-1];

    // copy elements from old array to new array EXCEPT at index of POS
    for(int i=0; i < newPos; i++)
    {
        temp[i] = _pArray[i];
    }
    for(int i=newPos+1; i < _size; i++)
    {
        temp[i-1] = _pArray[i];
    }

    delete[] _pArray;

    _pArray = temp;

    _size--;
}

template<typename T>
T Array<T>::min() const {
    // if array is empty, throw std::out_of_range exception
    if(_size == 0) {throw std::out_of_range("Array is empty");}
    // find minimum value within array
    T minimum = _pArray[0];
    for(int i=0; i<_size; i++)
    {
        if(minimum > _pArray[i]) {minimum = _pArray[i];}
    }
    // return min value
    return minimum;
}

template<typename T>
T Array<T>::max() const {
    // if array is empty, throw std::out_of_range exception
    if(_size == 0) {throw std::out_of_range("Array is empty");}
    // find maximum value within array
    T maximum = _pArray[0];
    for(int i=0; i<_size; i++)
    {
        if(maximum < _pArray[i]) {maximum = _pArray[i];}
    }
    // return max value
    return maximum;
}

template<typename T>
int Array<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE and return
    for(int i=0; i<_size; i++)
    {
        if(_pArray[i] == VALUE) {
            return i;
        }
    }
    
    // otherwise return -1
    return -1;
}

template<typename T>
void Array<T>::sort() {

    if(_printSort) {
        std::cout << "Sorting an array: \n"
        << "Initial array: ";
        for(int i=0; i<_size; i++) {
            std::cout << _pArray[i] << " ";
        }
        std::cout << std::endl;
    }

    if(_size > 1) {
        T* temp = new T[_size];
        mergeSort(0, _size-1, temp);
        delete[] temp;
    }

    if(_printSort) {
        std::cout << "Sorted array: ";
        for(int i=0; i<_size; i++) {
            std::cout << _pArray[i] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Array<T>::mergeSort(int left, int right, T* temp) {

    // check that there is more than one element - if(left == right) then there is one element
    if(left < right) {
        int middle = (right-left)/2 + left; // find place to split

        // recursion
        mergeSort(left, middle, temp); // sort left array
        mergeSort(middle+1, right, temp); // sort right array

        merge(left, middle, right, temp); // effectively merges two separate sorted arrays and sorts the
    }
}

template<typename T>
void Array<T>::merge(int left, int middle, int right, T* temp) 
{
    int leftSelector = left;
    int rightSelector = middle + 1;
    int tempIndex = 0;

    while(leftSelector <= middle && rightSelector <= right) {

        if(_pArray[leftSelector] <= _pArray[rightSelector]) {
            temp[tempIndex++] = _pArray[leftSelector++];
        } else {
            temp[tempIndex++] = _pArray[rightSelector++];
        }
    }

    while(leftSelector <= middle) {
        temp[tempIndex++] = _pArray[leftSelector++];
    }

    while(rightSelector <= right) {
        temp[tempIndex++] = _pArray[rightSelector++];
    }

    for(int j = left; j <= right; j++) {
        _pArray[j] = temp[j - left];
    }
}

template<typename T>
int Array<T>::search(const T VALUE) const
{
    return searchBetween(VALUE, 0, _size-1);
}

template<typename T>
int Array<T>::searchBetween(const T VALUE, int start, int end) const
{
    // If start ends up being bigger than end, that means the value isn't in the array
    if(start > end) 
    {
        return -1;
    }

    int middle = start + (end-start)/2;

    // Check if the value is middle, if not keep searching
    if(VALUE == _pArray[middle]) 
    {
        return middle;
    }
    else if(VALUE < _pArray[middle]) 
    {
        return searchBetween(VALUE, start, middle-1);
    }
    else
    {
        return searchBetween(VALUE, middle+1, end);
    }
}

#endif//ARRAY_H