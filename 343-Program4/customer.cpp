// ------------------------------------------------ customer.cpp ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - customer class that stores the information of a customer

// -------------------------------------------------------------------------------------------------------------------- 
#include <iostream> 
#include "customer.h"

using namespace std;
// ---------------------------------------- Customer Constructor ----------------------------------------
// Description: Initializes a Customer object with an ID and name.
// preconditions: Valid integer ID and non-empty name string.
// postconditions: Customer object initialized with ID and name.
// --------------------------------------------------------------------------------------------

Customer::Customer(int id, string name) {
    ID = id;
    this->name = name;
}

// ---------------------------------------- getID ----------------------------------------
// Description: Returns the ID of the Customer.
// preconditions: ID must be initialized.
// postconditions: Returns ID as an integer.
// --------------------------------------------------------------------------------------------
int Customer::getID() const {
    return ID;
}

// ---------------------------------------- getName ----------------------------------------
// Description: Returns the name of the Customer.
// preconditions: Name must be initialized.
// postconditions: Returns name as a string.
// --------------------------------------------------------------------------------------------
string Customer::getName() const{
    return name;
}

// ---------------------------------------- addTransaction ----------------------------------------
// Description: Adds a new transaction to the customer's history.
// preconditions: newTransaction must be valid and initialized.
// postconditions: Transaction is added to the beginning of the history vector.
// --------------------------------------------------------------------------------------------
// assuming that same transaction doesnt exist and variables exist/are valid
void Customer::addTransaction(pastTransactions newTransaction)
{
    history.insert(history.begin(), newTransaction);
}

// ---------------------------------------- hasTransaction ----------------------------------------
// Description: Checks if the customer currently has a borrowed transaction for the given movie.
// preconditions: moviePtr must be valid.
// postconditions: Returns true if movie is found in history as borrowed, false otherwise.
// --------------------------------------------------------------------------------------------
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

// ---------------------------------------- displayHistory ----------------------------------------
// Description: Prints the customer's transaction history to standard output.
// preconditions: history vector must be initialized.
// postconditions: Outputs all transactions or a blank line if empty.
// --------------------------------------------------------------------------------------------
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

// ---------------------------------------- operator< ----------------------------------------
// Description: Compares two customers by ID, then by name if IDs are equal.
// preconditions: customerPtr must not be null.
// postconditions: Returns true if this customer is less than the other.
// --------------------------------------------------------------------------------------------
bool Customer::operator<(const Customer* customerPtr) const
{
    if (ID != customerPtr->ID)
    {
        return ID < customerPtr->ID;
    }

    return name.compare(customerPtr->name) < 0;
}

// ---------------------------------------- operator> ----------------------------------------
// Description: Compares two customers by ID, then by name if IDs are equal.
// preconditions: customerPtr must not be null.
// postconditions: Returns true if this customer is greater than the other.
// --------------------------------------------------------------------------------------------
bool Customer::operator>(const Customer* customerPtr) const
{
    if (ID != customerPtr->ID)
    {
        return ID > customerPtr->ID;
    }

    return name.compare(customerPtr->name) > 0;
}

// ---------------------------------------- operator== ----------------------------------------
// Description: Checks equality of two customers by ID and name.
// preconditions: customerPtr must not be null.
// postconditions: Returns true if both ID and name are equal.
// --------------------------------------------------------------------------------------------
bool Customer::operator==(const Customer* customerPtr) const
{
    return (ID == customerPtr->ID &&
            name.compare(customerPtr->name) == 0);
}
// ---------------------------------------- print ----------------------------------------
// Description: Outputs the Customer's ID and name.
// preconditions: ID and name must be initialized.
// postconditions: Displays the Customer's information.
// --------------------------------------------------------------------------------------------
void Customer::print() const
{
    cout << ID << " " << name << endl;
}