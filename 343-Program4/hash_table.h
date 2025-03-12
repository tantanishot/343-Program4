#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream> 
#include <string> 
#include "linked_list.h"
#include "movie.h"
#include "customer.h"

using namespace std;

const int TABLE_SIZE = 101; // change to be a prime number greater than or equal to expected # of items

template <typename T>
class HashTable
{
    public:
        HashTable();
        ~HashTable();

        bool insertString(const string value, const T* objectPtr);  // insert object using string to get key
        bool insertInt(const int value, const T* objectPtr);     // insert object using int to get key
        void display() const; // Print all stored movies 

    private:
        T* table[TABLE_SIZE]; // Fixed size array for hash table

        // getKey functions (h(x))
        int getKeyFromString(const string value, const int steps) const;
        int getKeyFromInt(const int value, const int steps) const;
};

#endif