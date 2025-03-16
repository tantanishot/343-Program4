#ifndef HISTORY_H_
#define HISTORY_H_

#include <iostream> 
#include <string>
#include "transactions.h"

template <typename T>
class History :  public Transactions<T>
{
    public:
        bool processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree);
};

template <typename T>
bool History<T>::processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree)
{
    if (customerPtr != nullptr)
    {
        customerPtr->displayHistory();
        return true;
    }
    return false;
}

#endif