#ifndef BORROW_H_
#define BORROW_H_

#include <iostream> 
#include <string>
#include "transactions.h"

template <typename T>
class Borrow :  public Transactions
{
    public:
        bool processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree) override;
};

template <typename T>
bool Borrow<T>::processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable, BinTree<T>* tree)
{
    // assumes movie and customer already exists in respective hashtable and tree
    if (moviePtr->getCode().compare("C") == 0)
    {
        const Classics* classicsPtr = dynamic_cast<const Classics*>(moviePtr);
        if (classicsPtr->getStock() == 0) // recommend other similar titles
        {
            int numSimilarTitles = tree->findNumSimilarTitles(classicsPtr);
            int steps = 1;
            int similarTitlesFound = 0;
            bool titleRecommended = false;
            while (!titleRecommended && similarTitlesFound < numSimilarTitles)
            {
                int index = hashtable->getStringIndex(classicsPtr->formatSortCriteria(), steps);
                if (hashtable->atIndex(index)->isSimilar(classicsPtr))
                {
                    if (hashtable->atIndex(index)->getStock() != 0)
                    {
                        // recommend title?

                        // decreaseStock
                        hashtable->atIndex(index)->adjustStock(false);

                        // add pastTransaction to customer history
                        pastTransactions newTransaction;
                        newTransaction.status = "Borrowed";
                        newTransaction.moviePtr = hashtable->atIndex(index);

                        customerPtr->addTransaction(newTransaction);

                        titleRecommended = true;
                    }
                    similarTitlesFound++;
                }
                steps++;
            }
            return titleRecommended;
        }
        else
        {
            // decreaseStock
            classicsPtr->adjustStock(true);

            // add pastTransaction to customer history
            pastTransactions newTransaction;
            newTransaction.status = "Borrowed";
            newTransaction.moviePtr = classicsPtr;

            customerPtr->addTransaction(newTransaction);

            return true;
        }
    }
    else if (moviePtr->getCode().compare("F") == 0)
    {
        const Comedy* comedyPtr = dynamic_cast<const Comedy*>(moviePtr);
        bool stockAdjusted = comedyPtr->adjustStock(false);
        if (stockAdjusted)
        {
            pastTransactions newTransaction;
            newTransaction.status = "Borrowed";
            newTransaction.moviePtr = comedyPtr;

            customerPtr->addTransaction(newTransaction);

            return true;
        }
    }
    else if (moviePtr->getCode().compare("D") == 0)
    {
        const Drama* dramaPtr = dynamic_cast<const Drama*>(moviePtr);
        bool stockAdjusted = dramaPtr->adjustStock(false);
        if (stockAdjusted)
        {
            pastTransactions newTransaction;
            newTransaction.status = "Borrowed";
            newTransaction.moviePtr = dramaPtr;

            customerPtr->addTransaction(newTransaction);

            return true;
        }
    }

    return false;
}

#endif