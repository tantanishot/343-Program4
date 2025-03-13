#ifndef BORROW_H_
#define BORROW_H_

#include <iostream> 
#include <string>
#include "transactions.h"

template <typename T>
class Borrow :  public Transactions
{
    public:
        bool processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable) override;
};

#include "borrow.cpp"
#endif