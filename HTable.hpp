/*  Assignment 3 - Hash Table Implementation File
    Jaydon cameron
    SENG1120 Data Structures
    C3329145
    Implementation of the functions in HTable.h  */

#include <string>
#include "HTable.h"

// Constructors
template<typename T>
HTable<T>::HTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        this->table[i].set_code("");
        this->table[i].set_quantity(0);
        //delete this->table[i];
    }
}

// Destructors
template<typename T>
HTable<T>::~HTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        this->table[i].set_code("");
        this->table[i].set_quantity(0);
        //delete this->table[i];
    }
}

// Accessors
template<typename T>
int HTable<T>::hashfun(const T& value) {
    int position = 0;
    std::string temp = value.get_code();
    for (int i = 0; i < (int)temp.length(); i++) {
        position += (i + 1) * (i + 1) * temp.at(i);
    }
    return position % TABLE_SIZE;
}

template<typename T>
bool HTable<T>::isEmpty(const int index) const {
    if (this->table[index].get_code() == "" && this->table[index].get_quantity() == 0) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
T& HTable<T>::getData(int index) {
    return this->table[index];
}

template<typename T>
int HTable<T>::calculateParts() {
    return 0;
}

template<typename T>
int HTable<T>::calculateInventory() {
    return 0;
}

template<typename T>
int HTable<T>::calculateLessThan(const int value) {
    return 0;
}

// Mutators
template<typename T>
void HTable<T>::add(const T& data) {
    int index = hashfun(data);
    if (this->table[index].get_code().length() != 0 && this->table[index].get_quantity() != 0) {
        this->table[index] = data;
    }
}

template<typename T>
void HTable<T>::remove(const T& data) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (this->table[i].get_code() == data.get_code() && this->table[i].get_quantity() == data.get_quantity()) {
            this->table[i].set_code("");
            this->table[i].set_quantity(0);
        }
    }
}

// Operator Overloads
template<typename T>
std::ostream& operator<<(std::ostream& out, HTable<T>& hTable)  {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!hTable.isEmpty(i)) {
            out << "(" << hTable.getData(i).get_code() << ", " << hTable.getData(i).get_quantity() << ")  ";
        }
    }
    return out;
}

