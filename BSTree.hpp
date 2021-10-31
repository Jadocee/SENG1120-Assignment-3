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
    deleteTree(this->root);
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
        if (root == NULL) {
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

/*template<typename T>
BTNode<T>* BSTree<T>::search(const T& target) const {
    return find(this->root, target);
}*/

// Mutators
template<typename T>
void BSTree<T>::deleteTree(BTNode<T>* node) {
    if (node != NULL) {
        deleteTree(node->getRight());
        deleteTree(node->getLeft());
        delete node;
        size--;
    }
}

template<typename T>
void BSTree<T>::add(const T& data) {
    if (root == NULL) {
        root = new BTNode<T>(data);
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
            node->setLeft(new BTNode<T>(data, node, NULL, NULL));
            this->size++;
        }
    } else if (data > node->getData()) {
        if (node->getRight() != NULL) {
            node->setRight(insert(data, node->getRight()));
        } else {
            node->setRight(new BTNode<T>(data, node, NULL, NULL));
            this->size++;
        }
    } else {
        node->setData(data);
    }
    return node;
}
template<typename T>
void BSTree<T>::remove(const T& data) {
    BTNode<T>* temp = find(this->root, data);
    if (temp != NULL) {
        removeSort(temp);         // Find node.
    }
    temp = NULL;
    delete temp;
}


// Recursive Functions
template<typename T>
void BSTree<T>::removeSort(BTNode<T>* node) {
    BTNode<T>* minmaxNode;
    if (node->getLeft() != NULL && node->getRight() != NULL) {  // Check if internal node.
        if (node->getRight()->getLeft() != NULL) {                    // Check right child has a left.
            minmaxNode = findMin(node->getRight());           // Find minimum value to right.
        } else {                                                            // Else
            minmaxNode = findMax(node->getLeft());            // Find maximum value of the left child.
        }
        node->setData(minmaxNode->getData());
        this->removeSort(minmaxNode);
    } else if (node->getRight() != NULL) {            // If node has only a right child.
        minmaxNode = findMin(node->getRight());
        node->setData(minmaxNode->getData());
        this->removeSort(minmaxNode);
    } else if (node->getLeft() != NULL) {       // If node only has a left child.
        minmaxNode = findMax(node->getLeft());
        node->setData(minmaxNode->getData());
        this->removeSort(minmaxNode);
    } else {                                        // Else; no children.
        if (node->getParent()->getRight() == node) {
            node->getParent()->setRight(NULL);
        } else {
            node->getParent()->setLeft(NULL);
        }
        delete node;
    }
    minmaxNode = NULL;
    delete minmaxNode;
}

template<typename T>
BTNode<T>* BSTree<T>::findMin(BTNode<T>* root) const {
    if (root->getLeft() != NULL) {
        return findMin(root->getLeft());
    } else {
        return root;
    }
}

template<typename T>
BTNode<T>* BSTree<T>::findMax(BTNode<T>* root) const {
    if (root->getRight() != NULL) {
        return findMax(root->getRight());
    } else {
        return root;
    }
}

template<typename T>
BTNode<T>* BSTree<T>::find(BTNode<T>* node, const T& target) const {
    if (node == NULL) {                         // If node is empty/non-existent.
        return NULL;                                // Return NULL.
    } else if (target > node->getData()) {      // If data is greater than the nodes data.
        return find(node->getRight(), target);      // Move to right child.
    } else if (target < node->getData()) {      // If data is less than the nodes data.
        return find(node->getLeft(), target);       // Move to left child.
    } else {                                    // Else; node was found.
        return node;                                // Return pointer to node.
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
        str += infix(node->getLeft(), ++lvl);       // Recursively prints the left side of the BSTree. The final node of the left side will be printed first.
        str += "(" + node->getData().get_code() + ", " + toString(node->getData().get_quantity()) + ")  ";  // Print the current node. This will be the root of the BSTree once the first recursion is complete.
        str += infix(node->getRight(), ++lvl);      // Recursively print the right side of the BSTree. The final node of the right side will be printed first.
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