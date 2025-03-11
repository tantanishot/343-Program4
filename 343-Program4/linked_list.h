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
    Node() : objPtr(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList
{
    public:
    LinkedList();  // Constructor to initialize the linked list
    bool addItem(T* itemPtr);  // Add an item to the linked list
    T* searchItem(const std::string& key) const;  // Search for an item by its key
    void display() const;  // Display the linked list (for debugging)
    
    private:
        Node<T>* head;
};


#endif