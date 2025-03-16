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

// assuming that same transaction doesnt exist and variables exist/are valid
void Customer::addTransaction(pastTransactions newTransaction)
{
    history.insert(history.begin(), newTransaction);
}

bool Customer::hasTransaction(Movie* moviePtr) const
{
    for (int i = 0; i < history.size(); i++)
    {
        if (history[i].status.compare("Borrowed") == 0 && history[i].moviePtr == moviePtr)
        {
            return true;
        }
    }
    return false;
}

//print the transactions 
void Customer::displayHistory() const
{
    cout << "History for " << name << ":" << endl;
    
    if (history.empty())
    {
        cout << endl;
        return;
    }

    for (int i = 0; i < history.size(); i++) // iterate through vector from beginning
    {
        // borrowed/returned title by director
        if (history[i].status.compare("Borrowed") == 0)
        {
            cout << "Borrowed " << history[i].moviePtr->getTitle() << " by " << history[i].moviePtr->getDirector() << endl;
        }
        else if (history[i].status.compare("Returned") == 0)
        {
            cout << "Returned " << history[i].moviePtr->getTitle() << " by " << history[i].moviePtr->getDirector() << endl;
        }
    }
}

bool Customer::operator<(const Customer* customerPtr) const
{
    if (ID != customerPtr->ID)
    {
        return ID < customerPtr->ID;
    }

    return name.compare(customerPtr->name) < 0;
}

bool Customer::operator>(const Customer* customerPtr) const
{
    if (ID != customerPtr->ID)
    {
        return ID > customerPtr->ID;
    }

    return name.compare(customerPtr->name) > 0;
}

bool Customer::operator==(const Customer* customerPtr) const
{
    return (ID == customerPtr->ID &&
            name.compare(customerPtr->name) == 0);
}

void Customer::print() const
{
    cout << ID << " " << name << endl;
}
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