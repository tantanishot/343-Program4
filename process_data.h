#ifndef PROCESS_DATA_H_
#define PROCESS_DATA_H_

#include <iostream>
#include <fstream>
#include <string>
#include "hash_table.h"
#include "Transactions.h"

using namespace std;

class ProcessData
{
    public:
        ProcessData();
        void processCommands();

    private:
        HashTable storedMovies;
        HashTable storedCustomers;

        void initializeMovieData(ifstream &stream);
        void initializeCustomerData(ifstream &stream);
};

#endif