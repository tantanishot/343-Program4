// ------------------------------------------------ customer.h ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Customer class that creates a customer with an id and a name

// -------------------------------------------------------------------------------------------------------------------- 

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
        //initialize object
        Customer();
        Customer(int id, string name);

        //get information
        int getID() const;
        string getName() const;

        //update transaction histories 
        void addTransaction(pastTransactions newTransaction);
        bool hasTransaction(Movie* moviePtr) const;
        void displayHistory() const;
        //here is the format sorting criterias, based on ID number
        bool operator<(const Customer* customerPtr) const;
        bool operator>(const Customer* customerPtr) const;
        bool operator==(const Customer* customerPtr) const;
        //print for testing
        void print() const;

    private: 
        int ID;
        string name;
        //each customer will store their history    
        //where first index is their oldest transaction
        vector<pastTransactions> history;
};

#endif