#include "hash_table.h"
#include <functional>  // For hash

using namespace std;

// Constructor
template <typename T>
HashTable<T>::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].occupied = false;  // Initialize all buckets as empty
    }
}

// Hash Function
//https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus 
template <typename T>
int HashTable<T>::hashFunction(const string& key) const {
    unsigned int hash = 0;
    int prime = 37; //Prime number for good distribution

    for(char ch: key) {
        hash = (hash * prime + ch) % TABLE_SIZE;
    }

    //make sure it is under table size
    return static_cast<int>(hash);
}

template <typename T>
bool HashTable<T>::insert(const string& key, T* itemPtr) {
    int index = hashFunction(key);  // Compute hash index

    // Classical movie special handling
    Classics* classicMovie = dynamic_cast<Classics*>(itemPtr);
    if (classicMovie != nullptr) {  // Only true if T is actually a Classics object
        while (table[index].occupied) {
            // If the existing movie has the same title, store in the same linked list
            T* existingMovie = table[index].value.searchItem(key);
            if (existingMovie != nullptr && existingMovie->getTitle() == classicMovie->getTitle()) {
                table[index].value.addItem(itemPtr);
                return true;  // Successfully added to the linked list
            }
            
            // Otherwise, probe to find the next available index
            index = (index + 1) % TABLE_SIZE;
        }
    }

    // If the bucket is unoccupied, insert movie normally
    if (!table[index].occupied) {
        table[index].key = key;
        table[index].value.addItem(itemPtr);
        table[index].occupied = true;
        return true;
    }

    // Handle collisions for non-Classical movies using separate chaining
    table[index].value.addItem(itemPtr);
    return true;
}


template <typename T>
bool HashTable<T>::remove(const string& key) {
    int index = hashFunction(key);

    if (!table[index].occupied) {
        return false;  // Item not found
    }

    // Classical movie special handling (Hybrid Approach)
    Classics* classicMovie = dynamic_cast<Classics*>(table[index].value.searchItem(key));
    if (classicMovie != nullptr) {  
        // If found, remove from the linked list
        bool removed = table[index].value.removeItem(key);
        
        // If the linked list is now empty, mark bucket as unoccupied
        if (table[index].value.isEmpty()) {
            table[index].occupied = false;
        }
        return removed;
    }

    // For `F` and `D` movies, remove from the linked list normally
    bool removed = table[index].value.removeItem(key);

    // If the linked list is now empty, mark bucket as unoccupied
    if (table[index].value.isEmpty()) {
        table[index].occupied = false;
    }

    return removed;
}



template <typename T>
void HashTable<T>::display() const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].occupied) {
            cout << "Index " << i << " (" << table[i].key << "):" << endl;
            table[i].value.display();
            cout << "-----------------------------------" << endl;
        }
    }
}
