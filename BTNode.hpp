/*  Assignment 3 - Binary Tree Node Implementation File
    Jaydon cameron
    SENG1120 Data Structures
    C3329145
    Implementation of BTNode.h  */

#include "BTNode.h"
#include <cstdlib>
#include <iostream>


// Constructors
template<typename T>
BTNode<T>::BTNode() {
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
    this->data = NULL;
}

template<typename T>
BTNode<T>::BTNode(const T& data, BTNode<T>* parent, BTNode<T>* left, BTNode<T>* right) {
    this->data = data;
    this->parent = parent;
    this->left = left;
    this->right = right;
}


template<typename T>
BTNode<T>::BTNode(const T& data) {
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
    this->data = data;
}

// Destructors
template<typename T>
BTNode<T>::~BTNode() {
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
}

// Accessors
template<typename T>
T& BTNode<T>::getData() {
    return this->data;
}

template<typename T>
const T& BTNode<T>::getData() const {
    return this->data;
}

template<typename T>
BTNode<T>* BTNode<T>::getLeft() {
    return this->left;
}

template<typename T>
const BTNode<T>* BTNode<T>::getLeft() const {
    return this->left;
}

template<typename T>
BTNode<T>* BTNode<T>::getRight() {
    return this->right;
}

template<typename T>
const BTNode<T>* BTNode<T>::getRight() const {
    return this->right;
}

template<typename T>
BTNode<T>* BTNode<T>::getParent() {
    return this->parent;
}

template<typename T>
const BTNode<T>* BTNode<T>::getParent() const {
    return this->parent;
}

// Mutators
template<typename T>
void BTNode<T>::setData(const T& data) {
    this->data = data;
}

template<typename T>
void BTNode<T>::setData(T& data) {
    this->data = data;
}

template<typename T>
void BTNode<T>::setParent(BTNode<T>* new_parent) {
    this->parent = new_parent;
}

template<typename T>
void BTNode<T>::setLeft(BTNode<T>* new_left) {
    this->left = new_left;
}

template<typename T>
void BTNode<T>::setRight(BTNode<T>* new_right) {
    this->right = new_right;
}


