#ifndef HISTORY_H_
#define HISTORY_H_

#include <iostream> 
#include <string>
#include "transactions.h"

template <typename T>
class History :  public Transactions
{
    public:
        bool processMovie(Customer* customerPtr) override;
};

template <typename T>
bool History<T>::processMovie(Customer* customerPtr)
{
    if (customerPtr != nullptr)
    {
        customerPtr->displayHistory();
        return true;
    }
    return false;
}

#endif