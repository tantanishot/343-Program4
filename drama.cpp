#include "drama.h"

Drama::Drama(int movStock, string movDirector, string movTitle, string movRelease)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "D";     // D for drama
    stock = movStock;
    director = movDirector;
    title = movTitle;
    releaseYear = movRelease;
}

string Drama::formatSortCriteria() const
{
    return (title + ", " + releaseYear);
}

bool Drama::operator<(const Drama* dramaPtr) const
{
    return title.compare(dramaPtr->title) < 0; // this comes before compared object
}

bool Drama::operator==(const Drama* dramaPtr) const
{
    return title.compare(dramaPtr->title) == 0;    // will return true when TITLES match
}