#ifndef BORROW_H_
#define BORROW_H_

#include <iostream> 
#include <string>
#include "transactions.h"

class Borrow :  public Transactions
{
    public:
        bool processMovie(Movie* mov, Customer* cust);
};

#endif