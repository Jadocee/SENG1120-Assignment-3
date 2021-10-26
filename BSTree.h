/*  Assignment 3 - Binary Search Tree Header File
    Jaydon cameron
    SENG1120 Data Structures
    C3329145
    This header file contains the functions used  
    by the BSTree.hpp file. */

#ifndef BS_TREE
#define BS_TREE

#include <cstdlib>
#include <ostream>
#include "BTNode.h"

template<typename T>
class BSTree {
    public:
        // Constructors
        BSTree();

        // Destructors
        ~BSTree();

        // Accessors
        int getSize() const;


        // Mutators
        void add(const T& data);
        void remove(const T& data);

    private:
        BTNode<T>* root;
        int size;

        // Print contents
        string infix(BTNode<T>* node);

        // Recursive functions
        BTNode<T>* insert(const T& data, BTNode<T>* node);

};

// Overloads
template<typename T>
std::ostream& operator<<(ostream& out, BSTree<T>& BSTree);

#include "BSTree.hpp"

#endif