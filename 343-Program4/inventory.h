#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream> 
#include <string>
#include "transactions.h"

template <typename T>
class Inventory :  public Transactions<T>
{
    public:
        bool processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree);
};

template <typename T>
bool Inventory<T>::processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree)
{
    tree->displayInorder();
    return true;
}

#endif