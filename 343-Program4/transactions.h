#ifndef TRANSACTIONS_H_
#define TRANSACTIONS_H_

#include <iostream> 
#include <string>
//temporary since process_data is not used in transactions
//#include "process_data.h"
#include "hash_table.h"
#include "bintree.h"
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
        virtual bool processMovie() = 0; // true if movie was successfully added, false if not
};

#endif