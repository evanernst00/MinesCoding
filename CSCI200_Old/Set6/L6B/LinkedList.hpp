#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class LinkedList final : public IList<T> {
public:
    LinkedList();
    ~LinkedList();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;
    void sort() override;
    int search(const T VALUE) const override;

private:
    struct Node {
        T value;
        Node* pNext;
        Node* pPrev;
    };

    Node* mergeSort(Node* head);
    Node* getMiddle(Node* head);
    Node* merge(Node* a, Node* b);

    Node* _pHead;
    Node* _pTail;
    int _size;

    bool _printSort = true;
};

//---------------------------------------------------------

template<typename T>
LinkedList<T>::LinkedList() {
    _size = 0;
    _pHead = nullptr;
    _pTail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    // remove each node in the list

}

template<typename T>
int LinkedList<T>::size() const {
    return _size;
}

template<typename T>
T LinkedList<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if(POS >= _size || POS < 0) {throw std::out_of_range("Position is out of range");}

    // Start with head node, and advance along the list to POS
    Node* current = _pHead;
    for(int i=0; i<POS; i++)
    {
        current = current->pNext;
    }
    
    // return value of current node
    return current->value;
}

template<typename T>
void LinkedList<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if(POS >= _size || POS < 0) {throw std::out_of_range("Position is out of range");}


    Node* current = _pHead;
    for(int i=0; i<POS; i++)
    {
        current = current->pNext;
    }

    // set value of current node
    current->value = VALUE;
}

template<typename T>
void LinkedList<T>::insert(const int POS, const T VALUE) {
    // Clamp POS to 0 or _size when out of bounds
    int insertPos = std::max(std::min(POS, _size), 0);
    
    // create pointer to new node
    Node* newNode = new Node{VALUE, nullptr, nullptr};

    if(_size == 0) // if empty, both head and tail point to this node because it's the first node
    {
        _pHead = _pTail = newNode; // executed right to left
    }
    else
    {
        if(insertPos == 0)
        {
            newNode->pNext = _pHead; // Makes the new node forward link to the first node (which _pHead points to)
            _pHead->pPrev = newNode; // Makes old first node point backward to the new first node
            _pHead = newNode; // Updates the head to point to the new node, making it the first one
        }
        else if(insertPos >= _size)
        {
            newNode->pPrev = _pTail;
            _pTail->pNext = newNode;
            _pTail = newNode;
        }
        else
        {
            // If POS is in the first half, start from the head. If it's in the second half of the list, start from the tail and work backwards.
            Node* current;
            int i;
            // Determine the direction of traversal and starting index
            if (insertPos < _size / 2)
            {
                current = _pHead;
                i = 0;
                while (i < insertPos)
                {
                    current = current->pNext;
                    i++;
                }
            }
            else
            {
                current = _pTail;
                i = _size - 1;
                while (i > insertPos)
                {
                    current = current->pPrev;
                    i--;
                }
            }

            // Put node into list
            newNode->pNext = current;
            newNode->pPrev = current->pPrev;
            current->pPrev->pNext = newNode;
            current->pPrev = newNode;
        }
    }

    _size++;
}

template<typename T>
void LinkedList<T>::remove(const int POS) {
    // if array is empty, throw std::out_of_range exception
    if(_size == 0) {throw std::out_of_range("No elements to remove");}
    // if POS is before zero, clamp to zero
    // if POS is after size, clamp to size
    int insertPos = std::max(std::min(_size, POS), 0);
    Node* target = nullptr;
    // if list has one element
    if(_size == 1)
    {
        // set node to delete to head
        target = _pHead;
        // set head and tail to be nullptr
        _pHead = _pTail = nullptr;
    }
    else
    {
        // if deleting head
        if(insertPos == 0)
        {
            // set node to delete to head
            target = _pHead;
            // advance head to next
            _pHead = _pHead->pNext;
            // set head previous to nullptr
            _pHead->pPrev = nullptr;
        }
        // else if deleting tail
        else if(insertPos >= _size - 1)
        {
            // set node to delete to tail
            target = _pTail;
            // step tail to previous
            _pTail = _pTail->pPrev;
            // set tail next to nullptr
            _pTail->pNext = nullptr;
        }
        else
        {
            // set current node to head
            Node* current = _pHead;
            // advance current node to space before position
            for(int i=0; i<insertPos-1; i++)
            {
                current = current->pNext;
            }
            // set node to delete to the current node's next node
            target = current->pNext;
            // unlink node to delete
            target->pNext->pPrev = target->pPrev;
            target->pPrev->pNext = target->pNext;
        }
    }

    delete target;
    _size--;
    
}

template<typename T>
T LinkedList<T>::min() const {
    // if list is empty, throw std::out_of_range exception
    if(_size == 0) throw std::out_of_range("List is empty");
    // find minimum value within list
    T min = _pHead->value;
    Node* current = _pHead->pNext; // already checked head node

    while(current != nullptr)
    {
        if(current->value < min) min = current->value;
        current = current->pNext;
    }

    // return min value
    return min;
}

template<typename T>
T LinkedList<T>::max() const {
    // if list is empty, throw std::out_of_range exception
    if(_size == 0) throw std::out_of_range("List is empty");
    // find maximum value within list
    T max = _pHead->value;
    Node* current = _pHead->pNext; // already checked head node

    while(current != nullptr) // when current gets set to nullptr at the end of the list, stop loop
    {
        if(current->value > max) max = current->value;
        current = current->pNext;
    }

    // return max value
    return max;
}

template<typename T>
int LinkedList<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    Node* current = _pHead;
    int index = 0;
    while(current != nullptr)
    {
        if(current->value == VALUE)
        {
            return index;
        }
        current = current->pNext;
        index++;
    }
    // otherwise return -1
    return -1;
}

template<typename T>
int LinkedList<T>::search(const T VALUE) const
{
    return (find(VALUE));
}

template<typename T>
void LinkedList<T>::sort() {
    if(_printSort) {
        std::cout << "Sorting a linked list: \n" 
        << "Initial list: ";

        Node* current = _pHead;
        while(current != nullptr) {
            std::cout << current->value << " ";
            current = current->pNext;
        }

        std::cout << std::endl;
    }

    _pHead = mergeSort(_pHead);

    if(_printSort) {
        std::cout << "Sorted list: ";

        Node* current = _pHead;
        while(current != nullptr) {
            std::cout << current->value << " ";
            current = current->pNext;
        }

        std::cout << std::endl;
    }
}

template <typename T>
typename LinkedList<T>::Node* 
LinkedList<T>::mergeSort(Node* head) {
    if(!head || !head->pNext) {
        return head;
    }

    Node* middle = getMiddle(head);
    Node* headRight = middle->pNext;

    middle->pNext = nullptr;
    if(headRight) headRight->pPrev = nullptr; // If there is a Node after the middle Node, unlink it from the previous one

    Node* left = mergeSort(head);
    Node* right = mergeSort(headRight);

    return merge(left, right);
}

template <typename T>
typename LinkedList<T>::Node* 
LinkedList<T>::getMiddle(Node* head) {
    if(!head || !head->pNext) return nullptr;

    Node* hare = head;
    Node* tortoise = head;

    // When the "hare" pointer reaches the end and terminates the loop, the tortoise will be at the middle
    while(hare && hare->pNext && hare->pNext->pNext) {
        tortoise = tortoise->pNext;
        hare = (hare->pNext) ? hare->pNext->pNext : hare->pNext;
    }

    return tortoise;
}

template <typename T>
typename LinkedList<T>::Node* 
LinkedList<T>::merge(Node* headA, Node* headB) {
    if (!headA) return headB;
    if (!headB) return headA;

    Node* head = nullptr;
    Node* tail = nullptr;

    if (headA->value < headB->value) {
        head = tail = headA;
        headA = headA->pNext;
    } else {
        head = tail = headB;
        headB = headB->pNext;
    }
    tail->pPrev = nullptr;  // Initial tail's previous should be null

    while (headA && headB) {
        if (headA->value < headB->value) {
            tail->pNext = headA;
            headA->pPrev = tail;
            tail = headA;
            headA = headA->pNext;
        } else {
            tail->pNext = headB;
            headB->pPrev = tail;
            tail = headB;
            headB = headB->pNext;
        }
    }

    if (headA) {
        tail->pNext = headA;
        headA->pPrev = tail;
    } else if (headB) {
        tail->pNext = headB;
        headB->pPrev = tail;
    }

    return head;
}


#endif//LINKED_LIST_H
