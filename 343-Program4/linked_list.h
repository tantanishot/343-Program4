/////////////////////////////////////////////////////////////////////////////////////////////////////
                                    // MAY DELETE IMPLEMENTATION
/////////////////////////////////////////////////////////////////////////////////////////////////////

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
    T* objectPtr;
    Node* next;
    Node() : objectPtr(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList
{
    public:
        LinkedList();  // Constructor to initialize the linked list
        bool sortedAdd(T* objectPtr);  // Add an object to the linked list
        // access to first item (head) for comparisons?
        bool isEmpty() const;
        void display() const;  // Display the linked list (for debugging)
    
    private:
        Node<T>* head;
};

#endif