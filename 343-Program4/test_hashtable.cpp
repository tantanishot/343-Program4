#include <iostream>
#include "hash_table.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include "customer.h"

using namespace std;

int main() {
    //testing movie hashtable
    HashTable<Movie> movieTable;

    Movie* comedy1 = new Comedy(10, "Nora Ephron", "You've Got Mail", 1998);
    Movie* comedy2 = new Comedy(10, "Rob Reiner", "When Harry Met Sally", 1989);

    Movie* drama1 = new Drama(10, "Steven Spielberg", "Schindler's List", 1993);
    Movie* drama2 = new Drama(10, "Gus Van Sant", "Good Will Hunting", 2000);

    Movie* classic1 = new Classics(10, "Michael Curtiz", "Casablanca", 8, 1942, "Ingrid", "Bergman");
    Movie* classic2 = new Classics(10, "Victor Fleming", "Gone With the Wind", 2, 1939, "Clark", "Gable");

    movieTable.insertString(comedy1->formatSortCriteria(), comedy1);
    movieTable.insertString(comedy2->formatSortCriteria(), comedy2);
    movieTable.insertString(drama1->formatSortCriteria(), drama1);
    movieTable.insertString(drama2->formatSortCriteria(), drama2);
    movieTable.insertString(classic1->formatSortCriteria(), classic1);
    movieTable.insertString(classic2->formatSortCriteria(), classic2);

    cout << "\n=== Movie Hash Table ===" << endl;
    movieTable.display();
    
    HashTable<Customer> customerTable;

   
    Customer* customer1 = new Customer(1234, "Mickey Mouse");
    Customer* customer2 = new Customer(5678, "Minnie Mouse");

    customerTable.insertInt(customer1->getID(), customer1);
    customerTable.insertInt(customer2->getID(), customer2);


    cout << "\n=== Customer Hash Table ===" << endl;
    customerTable.display();
    
    return 0;
}