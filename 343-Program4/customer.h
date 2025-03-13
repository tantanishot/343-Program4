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
        Customer(int id, string name);

        int getID() const;
        string getName() const;

        void displayHistory() const;

        bool operator<(const Customer* customerPtr) const;
        bool operator>(const Customer* customerPtr) const;
        bool operator==(const Customer* customerPtr) const;

        void print() const;

    private: 
        int ID;
        string name;
        //each customer will store their history    
        //where first index is their oldest transaction
        vector<pastTransactions> history;
};

#endif