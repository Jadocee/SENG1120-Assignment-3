/* Assignment 3 - Linked List Implementation File
 * Jaydon Cameron
 * SENG1120 Data Structures
 * C3329145
 * Implementation of the functions in LinkedList.h */

#include "LinkedList.h"

// Constructors
template<typename T>
LinkedList<T>::LinkedList() { // Create Linked List with no data.
    head = NULL;    // Update head.
    tail = NULL;    // Update tail.
    curr = NULL;    // Update curr.
    size = 0;       // Update size.
}

template<typename T>
LinkedList<T>::LinkedList(T& data) {  // Create linked list with data.
    this->head = new Node<T>(data);    // Update head.
    this->tail = this->head;        // Update tail.
    this->curr = this->head;        // Update curr.
    size = 1;                       // Update size.
}

// Destructors
template<typename T>
LinkedList<T>::~LinkedList() {
    while (this->head != NULL) {    // Check if head points to node.
        this->LinkedList<T>::removeFromHead();     // Remove head. Repeat check until empty.
    }
    this->tail = NULL;  // Update tail pointer to NULL.
}

// Mutators
template<typename T>
void LinkedList<T>::removeCurrent() {
    /*  Precondition:   List is not empty, and curr points to a node.
        Postcondition:  The current node is removed, and the list is 
                        updated.    */
    if (this->curr == this->head) {
        this->removeFromHead(); // Remove from head of list.
    } else if (this->curr == this->tail) {
        this->removeFromTail(); // Remove from tail of list.
    } else {
        Node<T>* temp = this->curr;    // Create temporary node pointer, pointing to curr.
        this->curr->getPrev()->setNext(this->curr->getNext());
        this->curr->getNext()->setPrev(this->curr->getPrev()); 
        this->curr = this->head;    // Update curr to point to head.
        delete temp;    // Delete temporary node.
        this->size--;   // Update size.
    }                                    
    this->curr = this->head;    // Update curr to point to head.                                
}

template<typename T>
void LinkedList<T>::moveForward() {
    if (this->curr->getNext() != NULL) {
        this->curr = this->curr->getNext();
    }
}

template<typename T>
bool LinkedList<T>::isEnd() const {
    if (this->curr->getNext() == NULL) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
void LinkedList<T>::addToHead(const T& data) {
    /*  Precondition:   No preconditions.
        Postconditon:   A new node is created and added to the beginning
                        of the list, as the new head.   */
    this->curr = new Node<T>(data);    // Create a new node, and have curr point to it.
    if (this->size == 0) {          // Check if there is no nodes in list.
        this->tail = this->curr;    // Make curr node the tail of the list.
    } else if(this->size > 0 && this->head != NULL) {  // Check if node(s) exist.
        this->curr->setNext(this->head);               // Update currs next to point to head.
        this->head->setPrev(this->curr);               // Update heads prev to point to curr.
    }
    this->head = this->curr;    // Update head to point to curr.
    this->size++;               // Update size.
}

template<typename T>
void LinkedList<T>::addToCurrent(const T& data) {
    Node<T>* new_node = new Node<T>(data);
    Node<T>* temp = this->curr->getNext();
    this->curr->setNext(new_node);
    temp->setPrev(new_node);
    temp = NULL;
    delete temp;
}

template<typename T>
void LinkedList<T>::addToTail(const T& data) {
    /*  Precondition:   The list isnt empty.
        Postcondition:  A new node is created and added to the end of the list
                        as the new tail.    */
    this->curr = new Node<T>(data);
    if (this->size > 0 && this->tail != NULL) {
        curr->setPrev(tail);    // Update currs prev to point to tail.
        tail->setNext(curr);    // Update tails next to point to curr.
    } else if (size == 0) {  // Check size 
        this->head = this->curr;    // Update head to point to curr.
    }
    this->tail = this->curr;    // Update tail to point to curr.
    this->size++;   // Update size.
}

template<typename T>
void LinkedList<T>::removeFromHead() {
    // Precondition: list isnt empty.
    // Postcondition: The head of the node is removed.
    Node<T>* n = this->head;   // Create temporary node.
    this->head = this->head->getNext(); // Update head to point to the next node in the linked list.
    if (this->head != NULL) {
        // If head points to a node, update previous to point to NULL.
        this->head->setPrev(NULL);
    } else {
        // If list is empty, make tail point to NULL.
        this->tail = NULL;
    }
    delete n;       // Remove temporary node.
    this->size--;   // Update size.
}

template<typename T>
void LinkedList<T>::removeFromTail() {
    /*  Precondtions:   List isnt empty. Tail points to a node.
        Postconditions: The current tail is removed and a new tail is 
                        assigned.   */
    Node<T>* n = this->tail;   // Create temporary node. Point to tail.
    this->tail = this->tail->getPrev(); // Update tail to previous node.
    if (this->tail != NULL) {   // Check if tail points to a node.
        this->tail->setNext(NULL);  // Update tails next to NULL.
    } else {    // If tail points to NULL.
        this->head = NULL;  // Update head to be NULL.
    }
    delete n; // Delete temporary node.
    this->size--; // Update size.
}

// Accessors
template<typename T>
T& LinkedList<T>::getTail() const {
    /*  Precondition:   List isnt empty.
        Postcondition:  The data from tail is returned to the function caller.    */
    return this->tail->getData();
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    /*  Precondition:   None.
        Postcondition:  Returns a boolean indicating whether the head of the linked list is NULL or not. */
    if(this->head == NULL) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
T& LinkedList<T>::getCurr() const {
    /*  Precondition:   List isnt empty.
        Postcondition:  The data from curr is returned to the function caller.    */
    return this->curr->getData();
}

template<typename T>
T& LinkedList<T>::getHead() const {
    /*  Precondition:   List isnt empty.
        Postcondition:  The data from head is returned to the function caller.    */
    return this->head->getData();
}


template<typename T>
int LinkedList<T>::getSize() const {
    /*  Precondition:   None.
        Postcondition:  List size is returned to the function caller.    */
    return this->size;
}

template<typename T>
void LinkedList<T>::setCurr(Node<T>* node) {
    /*  Precondition:   The list isn't empty.
        Postcondition:  The curr now points to the parsed node. */
    this->curr = node; // Update curr to point to desired node.
}

template<typename T>
void LinkedList<T>::moveToStart() {
    if (!this->isEmpty()) {
        this->curr = this->head;
    }
}