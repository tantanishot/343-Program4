#ifndef TRANSACTIONS_H_
#define TRANSACTIONS_H_

#include <iostream> 
#include <string>
#include "hash_table.h"
#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include "customer.h"

struct pastTransactions
{
    string status;
    Movie* moviePtr;
    pastTransactions() : status(""), moviePtr(nullptr) {}
};

template <typename T>
class Transactions
{
    public:
        virtual bool processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable) = 0; // true if movie was successfully added, false if not
};

#endif