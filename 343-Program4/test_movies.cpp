#include <iostream>
#include "comedy.h"
#include "drama.h"
#include "classics.h"

using namespace std;

int main() {
    // Use Movie pointers instead of objects
    Movie* comedy1 = new Comedy(10, "Nora Ephron", "You've Got Mail", 1998);
    Movie* comedy2 = new Comedy(10, "Rob Reiner", "When Harry Met Sally", 1989);
    
    Movie* drama1 = new Drama(10, "Steven Spielberg", "Schindler's List", 1993);
    Movie* drama2 = new Drama(10, "Gus Van Sant", "Good Will Hunting", 2000);

    Movie* classic1 = new Classics(10, "Michael Curtiz", "Casablanca", 8, 1942, "Ingrid", "Bergman");
    Movie* classic2 = new Classics(10, "Victor Fleming", "Gone With the Wind", 2, 1939, "Clark", "Gable");

    //Test formatSortCriteria()
    cout << "Comedy Sorting Key: " << comedy1->formatSortCriteria() << endl;
    cout << "Drama Sorting Key: " << drama1->formatSortCriteria() << endl;
    cout << "Classics Sorting Key: " << classic1->formatSortCriteria() << endl;

    // Test operator<
    cout << "Comparing Comedies (Should be 0): " << (*comedy1 < comedy2) << endl;
    cout << "Comparing Dramas (Should be 1): " << (*drama2 < drama1) << endl;
    cout << "Comparing Classics (Should be 1): " << (*classic2 < classic1) << endl;

    //  Test operator==
    cout << "Are these Dramas equal? (Should be 0): " << (*drama1 == drama2) << endl;
    cout << "Are these Classics equal? (Should be 0): " << (*classic1 == classic2) << endl;

    // Cleanup
    delete comedy1;
    delete comedy2;
    delete drama1;
    delete drama2;
    delete classic1;
    delete classic2;

    return 0;
}
