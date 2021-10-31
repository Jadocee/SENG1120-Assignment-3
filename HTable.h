/*  Assignment 3 - Hash Table Header File
    Jaydon cameron
    SENG1120 Data Structures
    C3329145
    Header file for HTable.hpp  */
#ifndef H_TABLE
#define H_TABLE

#define TABLE_SIZE 300

#include <cstdlib>
#include <ostream>
#include <sstream>
#include "LinkedList.h"

template<typename T>
class HTable {
    public:
    // Constructors
    HTable();

    // Destructors
    ~HTable();

    // Accessors
    std::ostream& printTable(std::ostream& out);
    int calculateInventory();
    int calculateParts();
    int calculateLessThan(const int value);

    // Mutators
    void add(const T& data);
    void remove(const T& data);

    private:
    // Private Members
    LinkedList<T>* table[TABLE_SIZE];

    // Hash Function
    int hashfun(const T& value);
};

// Operator Overload
template<typename T>
std::ostream& operator<<(std::ostream& out, HTable<T>& hTable);

#include "HTable.hpp"

#endif