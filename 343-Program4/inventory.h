#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream> 
#include <string>
#include "transactions.h"

template <typename T>
class Inventory :  public Transactions
{
    public:
        bool processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree[]);
};

template <typename T>
bool Inventory<T>::processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree[])
{
    for (int i = 0; i < tree.size(); i++)
    {
        BinTree<T>* btree = tree[i];
        btree->displayInorder();
        return true;
    }
    return false;
}

#endif