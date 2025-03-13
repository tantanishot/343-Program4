#include "borrow.h"

template <typename T>
bool Borrow<T>::processMovie(Movie* moviePtr, Customer* customerPtr, HashTable<T>* hashtable)
{
    // assuming movie and customer already exists in respective hashtable
    
    if (moviePtr->getCode().compare("C") == 0)
    {
        const Classics* classicsPtr = dynamic_cast<const Classics*>(moviePtr);
        hashtable->
    }
    else if (moviePtr->getCode().compare("F") == 0)
    {
        const Comedy* comedyPtr = dynamic_cast<const Comedy*>(moviePtr);
    }
    else if (moviePtr->getCode().compare("D") == 0)
    {
        const Drama* dramaPtr = dynamic_cast<const Drama*>(moviePtr);
    }
    // check if movie is in stock

    // else check list for related movies

    // deplete stock
    // add pastTransactions into customer vector
    // return true

    // else return false
}