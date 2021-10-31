/****************************************************/
/**  Assignment 2 - Node Source File               **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This source file contains the implementation  **/
/**  of the functions in Node.h which are used to  **/
/**  access the nodes and its data.                **/
/****************************************************/

#include "Node.h"
#include "string"
// Constructors
template<typename T>
Node<T>::Node(const T& data) {
    this->data = data;
    next = NULL;
    prev = NULL;
}

template<typename T>
Node<T>::Node() {
    next = NULL;
    prev = NULL;
}


// Destructors
template<typename T>
Node<T>::~Node() {
    next = NULL;
    prev = NULL;
}

// Getters (Accessors)
template<typename T>
T& Node<T>::getData() {
    /*  Precondition:   None.
        Postcondition:  The node's data is returned. */
    return this->data;
}

template<typename T>
const Node<T>* Node<T>::getNext() const {
    /*  Precondition:   None.
        Postcondition:  This nodes next node pointer is returned. */
    return this->next;
}

template<typename T>
Node<T>* Node<T>::getNext() {
    /*  Precondition:   None.
        Postcondition:  This nodes next node pointer is returned. */
    return this->next;
}

template<typename T>
const Node<T>* Node<T>::getPrev() const {
        /*  Precondition:   None.
            Postcondition:  This nodes previous node pointer is returned. */
    return this->prev;
}

template<typename T>
Node<T>* Node<T>::getPrev() {
        /*  Precondition:   None.
        Postcondition:  This nodes previous node pointer is returned. */
    return this->prev;
}

// Setters (Mutators)
template<typename T>
void Node<T>::setData(const T& data) {
        /*  Precondition:   None.
            Postcondition:  The nodes data is updated with the parsed data. */    
    Node<T>::data = data;
}

template<typename T>
void Node<T>::setNext(Node<T>* next) {
        /*  Precondition:   None.
        Postcondition:  This nodes next node pointer is updated to point to the parsed node pointer. */
    Node<T>::next = next;
}

template<typename T>
void Node<T>::setPrev(Node<T>* prev) {
    /*  Precondition:   None.
        Postcondition:  This nodes previous node pointer is updated to point to the parsed node pointer. */
    Node<T>::prev = prev;
}