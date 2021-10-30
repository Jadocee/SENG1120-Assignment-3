/*  Assignment 3 - Hash Table Header File
    Jaydon cameron
    SENG1120 Data Structures
    C3329145
    Header file for HTable.hpp  */
#ifndef H_TABLE
#define H_TABLE

#define TABLE_SIZE 5000

#include <cstdlib>
#include <ostream>
#include <sstream>

template<typename T>
class HTable {
    public:
    // Constructors
    HTable();

    // Destructors
    ~HTable();

    // Accessors
    int hashfun(const T& value);
    bool isEmpty(const int index) const;
    T& getData(int index);
    int calculateInventory();
    int calculateParts();
    int calculateLessThan(const int value);

    // Mutators
    void add(const T& data);
    void remove(const T& data);

    private:
    T table[TABLE_SIZE];

};

// Operator Overload
template<typename T>
std::ostream& operator<<(std::ostream& out, HTable<T>& hTable);

#include "HTable.hpp"

#endif