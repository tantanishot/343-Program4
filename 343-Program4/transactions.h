#ifndef TRANSACTIONS_H_
#define TRANSACTIONS_H_

#include <iostream> 
#include <string>
#include "movie.h"
#include "customer.h"

struct pastTransactions
{
    string status;
    Movie* moviePtr;
    pastTransactions() : status(""), moviePtr(nullptr) {}
};

class Transactions
{
    public:
        virtual bool processMovie(Movie* moviePtr) = 0; // true if movie was successfully added, false if not
};

#endif