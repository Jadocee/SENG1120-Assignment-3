/*  Assignment 3 - Binary Search Tree Implementation File
    Jaydon cameron
    SENG1120 Data Structures
    C3329145
    Implementation of BSTree.h */

#include "BSTree.h"

// Constructors
template<typename T>
BSTree<T>::BSTree() {
    this->size = 0;
    this->root = NULL;
}

// Destructors
template<typename T>
BSTree<T>::~BSTree() {

}

// Accessors
template<typename T>
int BSTree<T>::getSize() const {
    return this->size;
}

// Mutators
template<typename T>
void BSTree<T>::add(const T& data) {
    if (this->root == NULL) {
        this->root = new BTNode<T>::BTNode(data);
        this->size++;
    } else {
        this->insert(data, root);
    }
}

template<typename T>
BTNode<T>* BSTree<T>::insert(const T& data, BTNode<T>* node) {
    if (data < node->getData()) { // Check if less than
        if (node->getLeft() != NULL) {
            node->setLeft(insert(data, node->getLeft()));
        } else {
            node->setLeft(new BTNode<T>::BTNode(data, node->getLeft()));
            this->size++;
        }
    } else if (data > node->getData()) {
        if (node->getRight() != NULL) {
            node->setRight(insert(data, node->getRight()));
        } else {
            node->setRight(new BTNode<T>::BTNode(data, node->getRight()));
            this->size++;
        }
    } else {
        node->setData(data);
    }

    // Print contents
    string BTNode<T>::infix(BTNode<T>* node) {
        BTNode<T>* temp = node;
        if (node->getData() != NULL) {

        }
    }
}

// Overloads
template<typename T>
std::ostream& operator<<(ostream& out, BSTree<T>& BSTree) {

}