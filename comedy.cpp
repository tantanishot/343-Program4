#include "comedy.h"

Comedy::Comedy(int movStock, string movDirector, string movTitle, string movRelease)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "F";     // F for funny
    stock = movStock;
    director = movDirector;
    title = movTitle;
    releaseYear = movRelease;
}

string Comedy::formatSortCriteria() const
{
    return (title + ", " + releaseYear);
}

bool Comedy::operator<(const Comedy* comedyPtr) const
{
    return title.compare(comedyPtr->title) < 0; // this comes before compared object
}

bool Comedy::operator==(const Comedy* comedyPtr) const
{
    return title.compare(comedyPtr->title) == 0;    // will return true when TITLES match (could vary by other parameters?)
}