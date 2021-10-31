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
        this->table[i] = new LinkedList<T>();
    }
}

// Destructors
template<typename T>
HTable<T>::~HTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete this->table[i];
        this->table[i] = NULL;
        /*this->table[i].set_code("");
        this->table[i].set_quantity(0);
        //delete this->table[i];*/
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
std::ostream& HTable<T>::printTable(std::ostream& out) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!this->table[i]->isEmpty()) {
            this->table[i]->moveToStart();
            while (true) {
                out << "(" << this->table[i]->getCurr().get_code() << ", " << this->table[i]->getCurr().get_quantity() << ")  ";
                if (this->table[i]->isEnd()) {
                    break;
                } else {
                    this->table[i]->moveForward();
                }
            }
        } else {
            out << "";
        }
    }
    return out;
}



template<typename T>
int HTable<T>::calculateParts() {
    int nParts = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!this->table[i]->isEmpty()) {
            this->table[i]->moveToStart();
            while (true) {
                if (this->table[i]->getCurr().get_code().length() != 0) {
                    nParts++;
                }
                if (this->table[i]->isEnd()) {
                    break;
                } else {
                    this->table[i]->moveForward();
                }
            }
        }
    }
    return nParts;
}

template<typename T>
int HTable<T>::calculateInventory() {
    int total = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!this->table[i]->isEmpty()) {
            this->table[i]->moveToStart();
            while (true) {
                if (this->table[i]->getCurr().get_code().length() != 0) {
                    total += this->table[i]->getCurr().get_quantity();
                }
                if (this->table[i]->isEnd()) {
                    break;
                } else {
                    this->table[i]->moveForward();
                }
            }
        }
    }
    return total;
}

template<typename T>
int HTable<T>::calculateLessThan(const int value) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!this->table[i]->isEmpty()) {
            this->table[i]->moveToStart();
            while (true) {
                if (this->table[i]->getCurr().get_code().length() != 0 && this->table[i]->getCurr().get_quantity() < value) {
                    count++;
                }
                if (this->table[i]->isEnd()) {
                    break;
                } else {
                    this->table[i]->moveForward();
                }
            }
        }
    }
    return count;
}

// Mutators
template<typename T>
void HTable<T>::add(const T& data) {
    int index = hashfun(data);
    if (!this->table[index]->isEmpty()) {
        if (data.get_code() > this->table[index]->getHead().get_code()) {
            this->table[index]->addToHead(data);
        } else if (data.get_code() < this->table[index]->getHead().get_code() && data.get_code() > this->table[index]->getTail().get_code()) {
            this->table[index]->moveToStart();
            this->table[index]->moveForward();
            while (data.get_code() < this->table[index]->getCurr().get_code()) {
                this->table[index]->moveForward();
            }
            this->table[index]->addToCurrent(data);
        } else {
            this->table[index]->addToTail(data);
        }
    } else {
        this->table[index]->addToHead(data);
    }

    /*if (this->table[index].get_code().length() != 0 && this->table[index].get_quantity() != 0) {
        this->table[index] = data;
    }*/
}

/*template<typename T>
void HTable<T>::bubbleSort() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!this->table[i]->isEmpty()) {
            this->table[i]->bubbleSort();
        }
    }
}*/

template<typename T>
void HTable<T>::remove(const T& data) {
    int index = hashfun(data);
    if (!this->table[index]->isEmpty()) {
        this->table[index]->moveToStart();
        for (int j = 0; j < this->table[index]->getSize(); j++) {
            if (this->table[index]->getCurr().get_quantity() == data.get_quantity() && this->table[index]->getCurr().get_code() == data.get_code()) {
                this->table[index]->removeCurrent();
                return;
            } else {
                this->table[index]->moveForward();
            }
        }
    }
    /*for (int i = 0; i < TABLE_SIZE; i++) {
        if (!this->table[i]->isEmpty()) {
            this->table[i]->moveToStart();
            for (int j = 0; j < this->table[i]->getSize(); j++) {
                if (this->table[i]->getCurr().get_quantity() == data.get_quantity() && this->table[i]->getCurr().get_code() == data.get_code()) {
                    this->table[i]->removeCurrent();
                    return;
                } else {
                    this->table[i]->moveForward();
                }
            }
        }
    }*/
        /*if (this->table[i].get_code() == data.get_code() && this->table[i].get_quantity() == data.get_quantity()) {
            this->table[i].set_code("");
            this->table[i].set_quantity(0);
        }*/
}

// Operator Overloads
template<typename T>
std::ostream& operator<<(std::ostream& out, HTable<T>& hTable)  {
    hTable.printTable(out);
    return out;
}

