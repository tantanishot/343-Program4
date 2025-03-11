#ifndef HASH_TABLE_H
#define HASH_TABLE_H


#include <iostream> 
#include <string> 
#include "linked_list.h"
#include "movie.h" //parent class for all movie types

using namespace std;

const int TABLE_SIZE = 101;

template <typename T>
class HashTable{

    public:
        HashTable();
        ~HashTable();

        bool insert(const string& key, T* itemPtr); //insert movie
        T* search(const string& key); //search for movie
        bool remove(const string& key); // Remove movie from talbe
        void display() const; //Print all stored movies 

    private:
        struct Bucket{
            string key;
            LinkedList<T> value;
            bool occupied;

            Bucket(): key(""), occupied(false) {}
        };

        Bucket table[TABLE_SIZE]; //Fixed size array for hash table

        int hashFunction(const string& key) const; //Hash function to the index 

       
};


#endif