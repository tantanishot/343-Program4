#include "hash_table.h"


//template class HashTable<Movie>;
//template class HashTable<Customer>;

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
    //fixed bug here where array subscripts of int type is an int not stiring
    //so we cant access its digits using array subscripts
    string convertedValue = to_string(value);
    if (convertedValue.length() == 1) // single digit
    {
        x1 = value;
        x2 = value * value;
    }
    else // multi digit
    {
        //Had this error with this line 
                /* hash_table.cpp: In member function ‘int HashTable<T>::getKeyFromInt(int, int) const’:
            hash_table.cpp:94:27: error: invalid types ‘const int[int]’ for array subscript
                    x1 = (int) value[0] + (int) value[1];
                                    ^
            hash_table.cpp:94:44: error: invalid types ‘const int[int]’ for array subscript
                    x1 = (int) value[0] + (int) value[1];
                                                        ^
            hash_table.cpp:95:27: error: invalid types ‘const int[int]’ for array subscript
                    x2 = (int) value[0] * (int) value[1];
                                    ^
            hash_table.cpp:95:44: error: invalid types ‘const int[int]’ for array subscript
                    x2 = (int) value[0] * (int) value[1];
                
                */
        //string convertedValue = to_string(value);
        //x1 = (int) value[0] + (int) value[1];
        //x2 = (int) value[0] * (int) value[1];

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
    //delete[] table;
    //You have to delete each individual pointer
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        delete table[i];
    }
}