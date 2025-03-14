#ifndef RETURN_H_
#define RETURN_H_

#include <iostream> 
#include <string>
#include "transactions.h"

template <typename T>
class Return :  public Transactions
{
    public:
        bool processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree) override;
};

template <typename T>
bool Return<T>::processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree)
{

}

#endif