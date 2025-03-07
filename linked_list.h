#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream> 
#include <string>
#include "movie.h"
#include "customer.h"

using namespace std;

template <typename T>
struct Node
{
    T* objPtr;
    Node* next;
};

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        bool addMovie(Movie* moviePtr);
        bool addCustomer(Customer* customerPtr);
    
    private:
        Node<T>* head;
};

#endif