#include "linked_list.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    head->objPtr = nullptr;
    head->next = nullptr;
}

template <typename T>
bool LinkedList<T>::addMovie(Movie *moviePtr)
{
    if (head->objPtr == nullptr) // empty list
    {
        head->objPtr = moviePtr;
        return true;
    }

    // not sure if this works yet bc it is calling method on movie obj not subclass?
    if (head->objPtr.formatSortCriteria().compare(moviePtr.formatSortCriteria()) > 0) // new movie is before head
    {
        Node* newNode = new Node();
        newNode->objPtr = moviePtr;
        newNode->next = head;
        head = newNode;
        newNode = nullptr;
        return true;
    }

    Movie* prevPtr;
    Movie* currPtr = head;
    while (currPtr->next != nullptr) // new movie placed after head
    {
        prevPtr = currPtr;
        currPtr = currPtr->next;
        if (currPtr->objPtr.formatSortCriteria().compare(moviePtr.formatSortCriteria) > 0)
        {
            Node* newNode = new Node();
            newNode->objPtr = moviePtr;
            newNode->next = currPtr;
            prevPtr->next = newNode;
            newNode = nullptr;
            return true;
        }
    }
}