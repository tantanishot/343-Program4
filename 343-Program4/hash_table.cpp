#include "hash_table.h"

template <typename T>
HashTable<T>::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) // sets pointers to nullptr (empty array)
    {
        table[i] = nullptr;
    }
}

template <typename T>
bool HashTable<T>::insertString(const string value, const T* newObjectPtr)
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
bool HashTable<T>::insertInt(const int value, const T* newObjectPtr)
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
    if (value < 10) // single digit
    {
        x1 = value;
        x2 = value * value;
    }
    else // multi digit
    {
        string convertedValue = to_string(value);
        x1 = (int) value[0] + (int) value[1];
        x2 = (int) value[0] * (int) value[1];
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
            T* objectPtr = table[i];
            cout << "Index: " << i << ", Contents: ";
            objectPtr->print();
            objectPtr = nullptr;
        }
    }
}

template <typename T>
HashTable<T>::~HashTable()
{
    delete[] table;
}