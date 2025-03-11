#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream> 
#include <string>
#include "transactions.h"

class Inventory :  public Transactions
{
    public:
        bool processMovie();
};

#endif