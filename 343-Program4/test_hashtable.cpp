#include <iostream>
#include "hash_table.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include "customer.h"

using namespace std;

int main() {
    //  Testing Movie Hash Tables for Different Genres
    HashTable<Movie>* storedMovies[3]; // Comedy [0], Drama [1], Classics [2]

    //  Initialize hash tables
    for (int i = 0; i < 3; i++) {
        storedMovies[i] = new HashTable<Movie>();
    }

    //  Creating Movies
    Movie* comedy1 = new Comedy(10, "Nora Ephron", "You've Got Mail", 1998);
    Movie* comedy2 = new Comedy(10, "Rob Reiner", "When Harry Met Sally", 1989);

    Movie* drama1 = new Drama(10, "Steven Spielberg", "Schindler's List", 1993);
    Movie* drama2 = new Drama(10, "Gus Van Sant", "Good Will Hunting", 2000);

    Movie* classic1 = new Classics(10, "Michael Curtiz", "Casablanca", 8, 1942, "Ingrid", "Bergman");
    Movie* classic2 = new Classics(10, "Victor Fleming", "Gone With the Wind", 2, 1939, "Clark", "Gable");

    //  Insert into respective genre-based hash tables
    storedMovies[0]->insertString(comedy1->formatSortCriteria(), comedy1);
    storedMovies[0]->insertString(comedy2->formatSortCriteria(), comedy2);
    
    storedMovies[1]->insertString(drama1->formatSortCriteria(), drama1);
    storedMovies[1]->insertString(drama2->formatSortCriteria(), drama2);
    
    storedMovies[2]->insertString(classic1->formatSortCriteria(), classic1);
    storedMovies[2]->insertString(classic2->formatSortCriteria(), classic2);

    //  Display stored movies
    cout << "\n=== Movie Hash Tables ===\n";
    for (int i = 0; i < 3; i++) {
        cout << (i == 0 ? "[Comedy]" : (i == 1 ? "[Drama]" : "[Classics]")) << " Movies:\n";
        storedMovies[i]->display();
    }

    // Test retrieving movies (Each lookup is done in the correct genre-based hash table)
    string searchKeys[] = {
        "You've Got Mail, 1998",  // Comedy
        "Steven Spielberg, Schindler's List", // Drama
        "8 1942 Ingrid Bergman", // Classics
        "Titanic, 1997"  // Should not exist
    };


    cout << "Stored Key: " << comedy1->formatSortCriteria() << endl;
    cout << "Search Key: " << searchKeys[0] << endl;

    cout << "Stored Key: " << drama1->formatSortCriteria() << endl;
    cout << "Search Key: " << searchKeys[1] << endl;

    cout << "Stored Key: " << classic1->formatSortCriteria() << endl;
    cout << "Search Key: " << searchKeys[2] << endl;
    
 

    cout << "\n=== Testing Movie Retrieval ===\n";
    for (int i = 0; i < 3; i++) {
        Movie* foundMovie = storedMovies[i]->retrieveString(searchKeys[i]);
        cout << (foundMovie ? "[SUCCESS] Found: " : "[ERROR] Not Found: ") << searchKeys[i] << endl;
    }

    //  Titanic should NOT exist
    Movie* missingMovie = storedMovies[0]->retrieveString(searchKeys[3]);
    cout << (missingMovie ? "[ERROR] Titanic should not exist!\n" : "[SUCCESS] Titanic not found as expected.\n");

    //  Testing Customer Hash Table
    HashTable<Customer> customerTable;

    Customer* customer1 = new Customer(1234, "Mickey Mouse");
    Customer* customer2 = new Customer(5678, "Minnie Mouse");

    customerTable.insertInt(customer1->getID(), customer1);
    customerTable.insertInt(customer2->getID(), customer2);

    cout << "\n=== Customer Hash Table ===" << endl;
    customerTable.display();

    //  Test retrieving customers
    int searchIDs[] = {1234, 5678, 9999}; // 9999 should not exist
    for (int id : searchIDs) {
        Customer* foundCustomer = customerTable.retrieveInt(id);
        cout << (foundCustomer ? "[SUCCESS] Found customer: " : "[ERROR] Customer not found: ") << id << endl;
    }

    return 0;
}
