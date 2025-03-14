#include <iostream>
#include "hash_table.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include "customer.h"

using namespace std;

int main() {
    // Create an array of hash tables for different movie genres
    HashTable<Movie> movieTables[3]; // F = 0, D = 1, C = 2

    // Create movie objects based on the input data
    Movie* classic1 = new Classics(10, "Michael Curtiz", "Casablanca", 8, 1942, "Ingrid", "Bergman");
    Movie* classic2 = new Classics(10, "Michael Curtiz", "Casablanca", 8, 1942, "Humphrey", "Bogart");
    Movie* classic3 = new Classics(10, "Victor Fleming", "The Wizard of Oz", 7, 1939, "Judy", "Garland");
    Movie* comedy1 = new Comedy(10, "Nora Ephron", "Sleepless in Seattle", 1993);
    Movie* drama1 = new Drama(10, "Barry Levinson", "Good Morning Vietnam", 1988);
    Movie* drama2 = new Drama(10, "Gus Van Sant", "Good Will Hunting", 2000);
    Movie* comedy2 = new Comedy(10, "Woody Allen", "Annie Hall", 1977);
    Movie* comedy3 = new Comedy(10, "Rob Reiner", "When Harry Met Sally", 1989);
    Movie* drama3 = new Drama(10, "Phillippe De Broca", "King of Hearts", 1967);
    Movie* drama4 = new Drama(10, "Steven Spielberg", "Schindler's List", 1993);
    Movie* comedy4 = new Comedy(10, "Gore Verbinski", "Pirates of the Caribbean", 2003);
    Movie* comedy5 = new Comedy(10, "Joel Coen", "Fargo", 1996);
    Movie* drama5 = new Drama(10, "Jonathan Demme", "Silence of the Lambs", 1991);
    Movie* drama6 = new Drama(10, "Clint Eastwood", "Unforgiven", 1992);
    Movie* classic4 = new Classics(10, "Hal Ashby", "Harold and Maude", 3, 1971, "Ruth", "Gordon");
    Movie* classic5 = new Classics(10, "Hal Ashby", "Harold and Maude", 3, 1971, "Bud", "Cort");
    Movie* classic6 = new Classics(10, "George Cukor", "Holiday", 9, 1938, "Katherine", "Hepburn");
    Movie* classic7 = new Classics(10, "George Cukor", "Holiday", 9, 1938, "Cary", "Grant");
    Movie* classic8 = new Classics(10, "Victor Fleming", "Gone With the Wind", 2, 1939, "Vivien", "Leigh");
    Movie* classic9 = new Classics(10, "Victor Fleming", "Gone With the Wind", 2, 1939, "Clark", "Gable");
    Movie* classic10 = new Classics(10, "George Cukor", "The Philadelphia Story", 5, 1940, "Katherine", "Hepburn");
    Movie* classic11 = new Classics(10, "George Cukor", "The Philadelphia Story", 5, 1940, "Cary", "Grant");
    Movie* classic12 = new Classics(10, "John Huston", "The Maltese Falcon", 10, 1941, "Humphrey", "Bogart");
    Movie* classic13 = new Classics(10, "Frank Capra", "It's a Wonderful Life", 11, 1946, "James", "Stewart");
    Movie* classic14 = new Classics(10, "Frank Capra", "It's a Wonderful Life", 11, 1946, "Donna", "Reed");
    Movie* classic15 = new Classics(10, "Stanley Kubrick", "A Clockwork Orange", 2, 1971, "Malcolm", "McDowell");
    Movie* comedy6 = new Comedy(10, "John Landis", "National Lampoon's Animal House", 1978);
    Movie* drama7 = new Drama(10, "Nancy Savoca", "Dogfight", 1991);
    Movie* comedy7 = new Comedy(10, "Nora Ephron", "You've Got Mail", 1998);

    // Insert movies into the appropriate hash table based on genre
    Movie* movies[] = {classic1, classic2, classic3, comedy1, drama1, drama2, comedy2, comedy3, drama3, drama4, comedy4, comedy5, drama5, drama6, classic4, classic5, classic6, classic7, classic8, classic9, classic10, classic11, classic12, classic13, classic14, classic15, comedy6, drama7, comedy7};

    for (Movie* movie : movies) {
        if (dynamic_cast<Comedy*>(movie)) {
            movieTables[0].insertString(movie->formatSortCriteria(), movie);
        } else if (dynamic_cast<Drama*>(movie)) {
            movieTables[1].insertString(movie->formatSortCriteria(), movie);
        } else if (dynamic_cast<Classics*>(movie)) {
            movieTables[2].insertString(movie->formatSortCriteria(), movie);
        }
    }

    // Display the contents of each hash table
    cout << "\n=== Comedy Hash Table ===" << endl;
    movieTables[0].display();

    cout << "\n=== Drama Hash Table ===" << endl;
    movieTables[1].display();

    cout << "\n=== Classics Hash Table ===" << endl;
    movieTables[2].display();
    
    // Customer Hash Table
    HashTable<Customer> customerTable;

    Customer* customer1 = new Customer(1234, "Mickey Mouse");
    Customer* customer2 = new Customer(5678, "Minnie Mouse");
    Customer* customer3 = new Customer(3333, "Witch Wicked");
    Customer* customer4 = new Customer(8888, "Pig Porky");
    Customer* customer5 = new Customer(4444, "Moose Bullwinkle");
    Customer* customer6 = new Customer(9999, "Duck Daffy");
    Customer* customer7 = new Customer(6666, "Donkey Darrell");
    Customer* customer8 = new Customer(7777, "Spider Sammy");
    Customer* customer9 = new Customer(1111, "Mouse Mickey");
    Customer* customer10 = new Customer(1000, "Mouse Minnie");
    Customer* customer11 = new Customer(9000, "Lizard Larry");
    Customer* customer12 = new Customer(8000, "Wacky Wally");
    Customer* customer13 = new Customer(5000, "Frog Freddie");
    Customer* customer14 = new Customer(2000, "Duck Donald");

    // Insert customers into the hash table
    Customer* customers[] = {customer1, customer2, customer3, customer4, customer5, customer6, customer7, customer8, customer9, customer10, customer11, customer12, customer13, customer14};

    for (Customer* customer : customers) {
        customerTable.insertInt(customer->getID(), customer);
    }

    cout << "\n=== Customer Hash Table ===" << endl;
    customerTable.display();
    
    return 0;

}