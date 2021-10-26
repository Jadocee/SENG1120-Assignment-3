/*  Assignment 3 - Binary Tree Node Header File
    Jaydon cameron
    SENG1120 Data Structures
    C3329145
    This header file contains the functions used  
    by the BTNode.hpp file. */

#ifndef BT_NODE
#define BT_NODE

#include <cstdlib>
#include <ostream>

template<typename T>
class BTNode {
    public:
        // Constructors
        BTNode(const T& data);
        BTNode(const T& data, BTNode<T>* parent);
        BTNode();

        // Destructors
        ~BTNode();

        // Accessors
        T& getData();
        const T& getData() const;
        const BTNode<T>* getLeft() const;
        const BTNode<T>* getRight() const;
        const BTNode<T>* getParent() const;
        BTNode<T>* getLeft();
        BTNode<T>* getRight();
        BTNode<T>* getParent();

        // Mutators
        void setData(const T& data);
        void setParent(BTNode<T>* new_parent);
        void setLeft(BTNode<T>* new_left);
        void setRight(BTNode<T>* new_right);

    private:
        Node<T>* parent;
        Node<T>* left;
        Node<T>* right;
        T data;
};

#include "BTNode.hpp"

#endif