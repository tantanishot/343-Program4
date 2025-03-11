#ifndef HISTORY_H_
#define HISTORY_H_

#include <iostream> 
#include <string>
#include "transactions.h"

class HISTORY :  public Transactions
{
    public:
        bool processMovie();
};

#endif