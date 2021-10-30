/*  Assignment 3 - Binary Search Tree Implementation File
    Jaydon cameron
    SENG1120 Data Structures
    C3329145
    Implementation of BSTree.h */

#include <cstdlib>
#include <string>
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
    removeChilds(this->root);
}

// Accessors
template<typename T>
int BSTree<T>::getSize() const {
    return this->size;
}

template<typename T>
std::string BSTree<T>::toString() {
    return infix(this->root, 0);
}

template<typename T>
std::string BSTree<T>::toString(int n) {
    std::ostringstream oss;
    oss << n;
    return oss.str();
}

template<typename T>
int BSTree<T>::calculateParts() {
    try {
        if (this->root == NULL) {
            throw "Tree is empty.";
        } else {
            return(calculatePartsR(this->root));
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return 0;
    }
}

template<typename T>
int BSTree<T>::calculateInventory() {
    return calculateInventoryR(this->root);
}

template<typename T>
int BSTree<T>::calculateLessThan(int value) {
    return countLessThan(this->root, value);
}

template<typename T>
BTNode<T>* BSTree<T>::search(T& target) {
    return find(this->root, target);
}

// Mutators
template<typename T>
void BSTree<T>::removeChilds(BTNode<T>* node) {
    if (node != NULL) {
        removeChilds(node->getRight());
        removeChilds(node->getLeft());
        delete node;
        size--;
    }
}

template<typename T>
void BSTree<T>::add(const T& data) {
    if (this->root == NULL) {
        this->root = new BTNode<T>(data);
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
            node->setLeft(new BTNode<T>(data, node->getLeft(), NULL, NULL));
            this->size++;
        }
    } else if (data > node->getData()) {
        if (node->getRight() != NULL) {
            node->setRight(insert(data, node->getRight()));
        } else {
            node->setRight(new BTNode<T>(data, node->getRight(), NULL, NULL));
            this->size++;
        }
    } else {
        node->setData(data);
    }
    return node;
}

template<typename T>
void BSTree<T>::remove(const T& data) {
    /*BTNode<T>* targetNode = search(data);
    if (targetNode->getLeft() != NULL && targetNode->getRight() != NULL) {    // Check if internal node.
        BTNode<T>* minNode = findSmallest(targetNode->getRight());         // Find smallest value to right.
        targetNode->setData(minNode->getData());
        targetNode->setRight(remove())
    } else if (targetNode->getRight() != NULL) {
        targetNode
    }*/
}

// Recursive Functions
template<typename T>
BTNode<T>* BSTree<T>::findSmallest(BTNode<T>* node){
    try {
        if (node == NULL) {
            throw "Node doesn't exist.";
        } else if (node->getLeft() != NULL) {
            return findSmallest(node->getLeft());
        } else {
            return node;
        }
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

template<typename T>
BTNode<T>* BSTree<T>::find(BTNode<T>* node, T& target) {
    if (node == NULL) {
        return NULL;
    } else {
        if (node == NULL) {
            return NULL;
        } else if (target > node->getData()) {
            return find(node->getRight(), target);
        } else if (target < node->getData()) {
            return find(node->getLeft(), target);
        } else {
            return node;
        }
    }
}

template<typename T>
int BSTree<T>::countLessThan(BTNode<T>* node, int value) {
    int count = 0;
    if (node != NULL) {
        if (node->getData().get_quantity() < value) {
            count++;
        }
        count += countLessThan(node->getLeft(), value);
        count += countLessThan(node->getRight(), value);
    }
    return count;
}

template<typename T>
int BSTree<T>::calculatePartsR(BTNode<T>* node) {
    int nParts = 0;
    if (node != NULL) {
        nParts += 1;
        if (node->getRight() != NULL) {
            nParts += calculatePartsR(node->getRight());
        }
        if (node->getLeft() != NULL) {
            nParts += calculatePartsR(node->getLeft());
        }
    }
    return nParts;
}

template<typename T>
int BSTree<T>::calculateInventoryR(BTNode<T>* node) {
    int total = 0;
    if (node != NULL) {
        total += calculateInventoryR(node->getLeft());
        total += node->getData().get_quantity();
        total += calculateInventoryR(node->getRight());
    }
    return total;
}

template<typename T>
std::string BSTree<T>::infix(BTNode<T>* node, int lvl) {
    std::string str;
    if (node == NULL) {
        return str;
    } else {
        str += infix(node->getLeft(), ++lvl);
        str += "(" + node->getData().get_code() + ", " + toString(node->getData().get_quantity()) + ")  ";
        str += infix(node->getRight(), ++lvl);
        return str;
        //return(infix(node->getLeft()) + node->getData() + infix(node->getRight()));
    }
}

// Overloads
template<typename T>
std::ostream& operator<<(std::ostream& out, BSTree<T>& tree) {
    out << tree.toString();
    return out;
}