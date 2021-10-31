/* Assignment 3 - Linked List Header File
 * Jaydon Cameron
 * SENG1120 Data Structures
 * C3329145
 * This header file contains the functions used by the LinkedList.hpp file. */

#ifndef LINKED_LIST
#define LINKED_LIST

#include <cstdlib>
#include "Node.h"
#include <string>
#include <ostream>

template<typename T>
class LinkedList {
    public:
        // Constructors
        LinkedList();
        LinkedList(T&);

        // Destructors
        ~LinkedList();

        // Accessors
        int getSize() const;
        T& getHead() const;
        T& getTail() const;
        T& getCurr() const;
        bool isEmpty() const;
        bool isEnd() const;

        // Mutators
        void setCurr(Node<T>* node);
        void addToHead(const T&);
        void addToTail(const T&);
        void addToCurrent(const T&);
        void removeFromHead();
        void removeCurrent();
        void removeFromTail();
        void moveForward();
        void moveToStart();
        //void bubbleSort();
    
    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* curr;
        int size;
        
};

#include "LinkedList.hpp"

#endif