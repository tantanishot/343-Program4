#include "classics.h"

Classics::Classics(int movStock, string movDirector, string movTitle, string releaseAndMA)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "C";     // C for classics
    stock = movStock;
    director = movDirector;
    title = movTitle;
    // split release year and name with name having first and last split
    MAFirstName = releaseAndMA.substr(0, releaseAndMA.find(" "));
    MALastName = releaseAndMA.substr(MAFirstName.length() + 1, releaseAndMA.substr(MAFirstName.length() + 1).find(" "));
    releaseYear = releaseAndMA.substr(MAFirstName.length() + MALastName.length() + 3);
}

string Classics::formatSortCriteria() const
{
    return (title + ", " + releaseYear);
}

bool Classics::operator<(const Classics* classicsPtr) const
{
    return title.compare(classicsPtr->title) < 0; // this comes before compared object
}

bool Classics::operator==(const Classics* classicsPtr) const
{
    return title.compare(classicsPtr->title) == 0;    // will return true when TITLES match
}