#ifndef RETURN_H_
#define RETURN_H_

#include <iostream> 
#include <string>
#include "transactions.h"

class Return :  public Transactions
{
    public:
        bool processMovie();
};

#endif