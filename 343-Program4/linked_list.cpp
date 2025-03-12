/////////////////////////////////////////////////////////////////////////////////////////////////////
                                    // MAY DELETE IMPLEMENTATION
/////////////////////////////////////////////////////////////////////////////////////////////////////


#include "linked_list.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    // empty list
    head->objectPtr = nullptr;
    head->next = nullptr;
}

// will only return false when the object already exists in the list
template <typename T>
bool LinkedList<T>::sortedAdd(T* newObjectPtr)
{
    // when the list is empty just add to the front
    if (head->objectPtr == nullptr)
    {
        head->objectPtr = newObjectPtr;
        return true;
    }

    // use polymorphism to compare the objects
    if (head->objectPtr == newObjectPtr) // check first item in list
    {
        return false;
    }

    if (head->objectPtr > newObjectPtr) // object comes before head so insert to front
    {
        Node<T>* newNode = new Node<T>();
        newNode->objectPtr = newObjectPtr;
        newNode->next = head;
        head = newNode;

        newNode = nullptr;

        return true;
    }

    // for objects that come after head
    Node<T>* prevPtr;
    Node<T>* currPtr = head;
    while (currPtr->next != nullptr) // iterates until spot is found
    {
        prevPtr = currPtr;
        currPtr = currPtr->next;
        if (currPtr->objectPtr == newObjectPtr) // dont add if already exists
        {
            prevPtr = nullptr;
            currPtr = nullptr;

            return false;
        }
        else if (currPtr->objectPtr < newObjectPtr)
        {
            Node<T>* newNode = new Node<T>();
            newNode->objectPtr = newObjectPtr;
            newNode->next = currPtr;
            prevPtr->next = newNode;

            newNode = nullptr;
            prevPtr = nullptr;
            currPtr = nullptr;

            return true;
        }
    }

    // insert at end of list
    Node<T>* newNode = new Node<T>();
    newNode->objectPtr = newObjectPtr;
    newNode->next = nullptr;
    currPtr->next = newNode;

    newNode = nullptr;
    currPtr = nullptr;
    prevPtr = nullptr;

    return true;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return head->objectPtr == nullptr;
}

template <typename T>
void LinkedList<T>::display() const {
    Node<T>* currPtr = head;

    if (currPtr->objectPtr == nullptr)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        while (currPtr != nullptr)
        {
            cout << currPtr->objectPtr->print() << endl;
            currPtr = currPtr->next;
        }
    }

    currPtr = nullptr;
}