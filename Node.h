/****************************************************/
/**  Assignment 2 - Node Header File               **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This header file contains the functions used  **/
/**  by the Node.hpp file.                         **/
/****************************************************/

#ifndef NODE
#define NODE

#include "cstdlib"
#include "string"
#include "iostream"
#include "MechPart.h"

template <typename T>
class Node  {
    public:
        // Constructors
        Node(const T& data);
        Node();

        //Destructors
        ~Node();

        // Accessors
        T& getData();
        const Node<T>* getNext() const;
        Node<T>* getNext();
        const Node<T>* getPrev() const;
        Node<T>* getPrev();
        
        // Mutatators
        void setData(const T& data);
        void setNext(Node<T>* next);
        void setPrev(Node<T>* prev);

    private:
        Node<T>* next;
        Node<T>* prev;
        T data;
};
#include "Node.hpp"

#endif