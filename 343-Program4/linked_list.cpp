#include "linked_list.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    //head->objPtr = nullptr;
    //head->next = nullptr;
}

template <typename T>
bool LinkedList<T>::addItem(T* itemPtr)
{
    if (!itemPtr) return false;  // Prevent nullptr errors

    // If the list is empty, insert as the first node
    if (!head) {
        head = new Node(itemPtr);
        return true;
    }

    // Sorting Logic: Calls correct function for sorting
    if (head->objPtr->getSortKey().compare(itemPtr->getSortKey()) > 0) {
        Node* newNode = new Node(itemPtr);
        newNode->next = head;
        head = newNode;
        return true;
    }

    // Insert in sorted order
    Node* prev = nullptr;
    Node* curr = head;

    while (curr && curr->objPtr->getSortKey().compare(itemPtr->getSortKey()) < 0) {
        prev = curr;
        curr = curr->next;
    }

    // Insert new node
    Node* newNode = new Node(itemPtr);
    prev->next = newNode;
    newNode->next = curr;

    return true;
}


template <typename T>
T* LinkedList<T>::searchItem(const std::string& key) const {
    Node<T>* curr = head;

    while (curr) {
        if (curr->objPtr->getSortKey() == key) {
            return curr->objPtr;  // Found the item
        }
        curr = curr->next;
    }

    return nullptr;  // Item not found
}


template <typename T>
void LinkedList<T>::display() const {
    Node<T>* curr = head;

    if (!curr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    while (curr) {
        std::cout << curr->objPtr->getSortKey() << std::endl;
        curr = curr->next;
    }
}

