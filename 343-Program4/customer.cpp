#include <iostream> 
#include "customer.h"

using namespace std;


//Need to add default constructor?

Customer::Customer(int id, string name) {
    ID = id;
    this->name = name;
}

int Customer::getID() const {
    return ID;
}


string Customer::getName() const{
    return name;
}


//print the transactions 


/*

Customer();

int getID() const;
string getName() const;
void displayHistory() const;
bool recordTransaction(); // figuring this out still

bool operator<(const Customer* customerPtr) const;
bool operator>(const Customer* customerPtr) const;
bool operator==(const Customer* customerPtr) const;

*/