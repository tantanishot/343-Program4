#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream> 
#include <string> 
#include "movie.h"
#include "customer.h"

using namespace std;

const int TABLE_SIZE = 101; // change to be a prime number greater than or equal to expected # of items

template <class T>
class HashTable
{
    public:
        HashTable();
        ~HashTable();

        bool insertString(const string value, T* objectPtr);  // insert object using string to get key
        bool insertInt(const int value, T* objectPtr);     // insert object using int to get key

        int getStringIndex(const string value, const int steps) const;
        int getIntIndex(const int value, const int steps) const;

        T* atIndex(const int index) const;

        int size() const;

        void display() const; // Print all stored movies 

    private:
        T* table[TABLE_SIZE]; // Fixed size array for hash table

        // generate Key functions (h(x))
        int getKeyFromString(const string value, const int steps) const;
        int getKeyFromInt(const int value, const int steps) const;
};

template <typename T>
HashTable<T>::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) // sets pointers to nullptr (empty array)
    {
        table[i] = nullptr;
    }
}

template <typename T>
bool HashTable<T>::insertString(const string value,  T* newObjectPtr)
{
    if (newObjectPtr == nullptr)
    {
        return false;
    }

    int steps = 0;
    while (steps < TABLE_SIZE) // traverse until every spot has been visited
    {
        int index = getKeyFromString(value, steps);
        if (table[index] == nullptr) // empty index
        {
            table[index] = newObjectPtr;
            return true;
        }
        steps++;
    }
    return false;
}

template <typename T>
bool HashTable<T>::insertInt(const int value, T* newObjectPtr)
{
    if (newObjectPtr == nullptr)
    {
        return false;
    }

    int steps = 0;
    while (steps < TABLE_SIZE) // traverse until every spot has been visited
    {
        int index = getKeyFromInt(value, steps);
        if (table[index] == nullptr) // empty index
        {
            table[index] = newObjectPtr;
            return true;
        }
        steps++;
    }
    return false;
}

template <typename T>
int HashTable<T>::getStringIndex(const string value, const int steps) const
{
    return getKeyFromString(value, steps);
}

template <typename T>
int HashTable<T>::getIntIndex(const int value, const int steps) const
{
    return getKeyFromInt(value, steps);
}

template <typename T>
T* HashTable<T>::atIndex(const int index) const
{
    //bounds check
    if (index < 0 || index >= TABLE_SIZE)  // Bounds check
    {
        return nullptr;
    }
    return table[index];
}

template <typename T>
int HashTable<T>::size() const
{
    return TABLE_SIZE;
}

// h(x1) = (x1 % 53)
    // x1 = first + second
// h_2(x2) = (37 - (x2 % 37))
    // x2 = first * second

// D(i) = h_2(x2) * i, where i is initially = 0

// h(x1) + D(i) % TABLE_SIZE
// (((first + second) % 53) + [(37 - (first * second % 37)) * i]) % TABLE_SIZE
template <typename T>
int HashTable<T>::getKeyFromString(const string value, const int steps) const
{
    int x1, x2;
    if (value.length() == 1) // single character
    {
        x1 = (int) value[0];
        x2 = (int) value[0] + 1;
    }
    else // multi character
    {
        x1 = (int) value[0] + (int) value[1];
        x2 = (int) value[0] * (int) value[1];
    }

    return ((x1 % 53) + ((37 - (x2 % 37)) * steps)) % TABLE_SIZE;
}

template <typename T>
int HashTable<T>::getKeyFromInt(const int value, const int steps) const
{
    int x1, x2;
    string convertedValue = to_string(value);
    if (convertedValue.length() == 1) // single digit
    {
        x1 = value;
        x2 = value * value;
    }
    else // multi digit
    {
        x1 = (int) convertedValue[0] + (int) convertedValue[1];
        x2 = (int) convertedValue[0] * (int) convertedValue[1];
    }

    return ((x1 % 53) + ((37 - (x2 % 37)) * steps)) % TABLE_SIZE;
}

template <typename T>
void HashTable<T>::display() const
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != nullptr)
        {
            const T* objectPtr = table[i];
            cout << "Index: " << i << ", Contents: ";
            objectPtr->print();
            objectPtr = nullptr;
        }
    }
}

template <typename T>
HashTable<T>::~HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        delete table[i];
    }
}

#endif