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
};

class Transactions
{
    public:
        Transactions();
        virtual bool processMovie(Movie* mov) = 0; // true if movie was successfully added, false if not
        friend struct pastTransactions; // not sure if this is how it's done but customer class needs access too
};


#endif