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
#include <string>
#include <sstream>
#include "BTNode.h"
#include "MechPart.h"

template<typename T>
class BSTree {
    public:
        // Constructors
        BSTree();

        // Destructors
        ~BSTree();

        // Accessors
        int getSize() const;
        std::string toString();
        std::string toString(int n);
        int calculateParts();															//ok
        int calculateInventory();
        int calculateLessThan(int value);
        BTNode<T>* search(T& target);

        // Mutators
        void add(const T& data);
        void remove(const T& data);
        void removeChilds(BTNode<T>* node);

private:
        // Private members
        BTNode<T>* root;
        int size;

        // Recursive functions
        std::string infix(BTNode<T>* node, int lvl);
        BTNode<T>* insert(const T& data, BTNode<T>* node);
        int calculatePartsR(BTNode<T>* node);
        int calculateInventoryR(BTNode<T>* node);
        BTNode<T>* find(BTNode<T>* node, T& target);
        BTNode<T>* findSmallest(BTNode<T>* node);
        int countLessThan(BTNode<T>* node, int value);

};

// Overloads
template<typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree);

#include "BSTree.hpp"

#endif