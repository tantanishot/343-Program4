#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream> 
#include <string> 
#include <vector>
#include "transactions.h"

using namespace std;

class Customer
{
    public:
        Customer();

        int getID() const;
        string getName() const;
        void displayHistory() const;
        bool recordTransaction(); // figuring this out still

        bool operator<(const Customer* customerPtr) const;
        bool operator>(const Customer* customerPtr) const;
        bool operator==(const Customer* customerPtr) const;

    private: 
        string ID;
        string name;
        vector<pastTransactions> history;
};

#endif