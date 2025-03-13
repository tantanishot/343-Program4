#ifndef PROCESS_DATA_H_
#define PROCESS_DATA_H_

#include <iostream>
#include <fstream>
#include <string>
#include "hash_table.h"
#include "transactions.h"

using namespace std;

const int NUM_GENRES = 3;

template <typename T>
class ProcessData
{
    public:
        ProcessData();
        void processCommands();

    private:
        HashTable<T>*[3] storedMovies;
        HashTable<T>*[3] storedCustomers;

        void initializeMovieData(ifstream &stream);
        void initializeCustomerData(ifstream &stream);
};

#include "process_data.cpp"
#endif