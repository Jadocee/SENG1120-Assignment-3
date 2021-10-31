/* Assignment 3 - Binary Search Tree Implementation File
 * Jaydon Cameron
 * SENG1120 Data Structures
 * C3329145
 * Implementation of BSTree.h */

#include <cstdlib>
#include <string>
#include "BSTree.h"

// Constructors
template<typename T>
BSTree<T>::BSTree() {
    this->size = 0;
    this->root = NULL;
}

// Destructor
template<typename T>
BSTree<T>::~BSTree() {
    deleteR(this->root);    // Delete all nodes.
}

// Accessors
template<typename T>
int BSTree<T>::getSize() const {
    return this->size;          // Return size;
}

template<typename T>
std::string BSTree<T>::printTree() {
    return infix(this->root, 0);    // Use inorder navigation to recursively print the data of each node.
}

template<typename T>
std::string BSTree<T>::toString(int n) {
    std::ostringstream oss;                 // Initialize ostringstream type variable.
    oss << n;                               // Pass the integer into it; converting the int to ostringstream.
    return oss.str();                       // Return the ostringstream as a string.
}

template<typename T>
int BSTree<T>::calculateParts() {
    try {
        if (root == NULL) {                                 // If tree is empty.
            throw "Tree is empty.";                             // Throw exception.
        } else {                                            // Else
            return (calculatePartsR(this->root));        // Recursively navigate through the tree and return the number of parts.
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;        // Print exception message.
        exit(1);                                              // Exit program with error indicated as the cause.
    }
}

template<typename T>
int BSTree<T>::calculateInventory() {
    return calculateInventoryR(this->root);         // Recursively navigate through the tree and return the sum of the inventory of all nodes.
}

template<typename T>
int BSTree<T>::calculateLessThan(int value) {
    return countLessThan(this->root, value);        // Recursively navigate through the tree and return the number of nodes with a quantity less than value.
}

// Mutators
template<typename T>
void BSTree<T>::add(const T& data) {
    if (root == NULL) {                 // If tree is empty.
        root = new BTNode<T>(data);         // Create a new node containing the data, and make it the root of the tree.
        this->size++;                       // Update size.
    } else {                            // Else
        this->insert(data, root);           // Recursively navigate the tree to insert the data.
    }
}

template<typename T>
BTNode<T>* BSTree<T>::insert(const T& data, BTNode<T>* node) {
    if (data < node->getData()) {                                   // If data is less than this nodes data.
        if (node->getLeft() != NULL) {                                  // If this node has a left child.
            node->setLeft(insert(data, node->getLeft()));                   // Move to left child; continue recursive function.
        } else {                                                        // Else
            node->setLeft(new BTNode<T>(data, node, NULL, NULL));           // Insert data into a new node for the left child.
            this->size++;                                                   // Update size.
        }
    } else if (data > node->getData()) {                            // If data is greater than this nodes data.
        if (node->getRight() != NULL) {                                 // If this node has a right child
            node->setRight(insert(data, node->getRight()));                 // Move to right child; continue recursive function.
        } else {                                                        // Else
            node->setRight(new BTNode<T>(data, node, NULL, NULL));          // Insert data into a new node for the right child.
            this->size++;                                                   // Update size.
        }
    } else {                                                        // Else (node/data already exists)
        node->setData(data);                                            // Replace this nodes data with the new data.
    }
    return node;                                                    // Return a pointer this node.
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
        size--;
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
    }
}

template<typename T>
void BSTree<T>::deleteR(BTNode<T>* node) {
    if (node != NULL) {
        deleteR(node->getRight());
        deleteR(node->getLeft());
        delete node;
        size--;
    }
}

// Overload ostream operator
template<typename T>
std::ostream& operator<<(std::ostream& out, BSTree<T>& tree) {
    out << tree.printTree();
    return out;
}