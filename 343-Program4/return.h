#ifndef RETURN_H_
#define RETURN_H_

#include <iostream> 
#include <string>
#include "transactions.h"

template <typename T>
class Return :  public Transactions
{
    public:
        bool processMovie(Movie* moviePtr, Customer* customerPtr) override;
};

template <typename T>
bool Return<T>::processMovie(Movie* moviePtr, Customer* customerPtr)
{
    // assuming movie and customer exists in hashtables and trees
    if (moviePtr->getCode().compare("C") == 0)
    {
        const Classics* classicsPtr = dynamic_cast<const Classics*>(moviePtr);
        if (customerPtr->hasTransaction(classicsPtr))
        {
            classicsPtr->adjustStock(true);

            pastTransactions newTransaction;
            newTransaction.status = "Returned";
            newTransaction.moviePtr = classicsPtr;
    
            customerPtr->addTransaction(newTransaction);

            return true;
        }
    }
    else if (moviePtr->getCode().compare("F") == 0)
    {
        const Comedy* comedyPtr = dynamic_cast<const Comedy*>(moviePtr);
        if (customerPtr->hasTransaction(comedyPtr))
        {
            comedyPtr->adjustStock(true);

            pastTransactions newTransaction;
            newTransaction.status = "Returned";
            newTransaction.moviePtr = comedyPtr;

            customerPtr->addTransaction(newTransaction);

            return true;
        }
    }
    else if (moviePtr->getCode().compare("D") == 0)
    {
        const Drama* dramaPtr = dynamic_cast<const Drama*>(moviePtr);
        if (customerPtr->hasTransaction(dramaPtr))
        {
            dramaPtr->adjustStock(true);

            pastTransactions newTransaction;
            newTransaction.status = "Returned";
            newTransaction.moviePtr = dramaPtr;

            customerPtr->addTransaction(newTransaction);

            return true;
        }
    }
    return false;
}

#endif