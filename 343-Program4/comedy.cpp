#include "comedy.h"

Comedy::Comedy(int movStock, string movDirector, string movTitle, int movRelease)
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
    return (title + ", " + to_string(releaseYear));
}

bool Comedy::operator<(const Movie* moviePtr) const {
    const Comedy* comedyPtr = dynamic_cast<const Comedy*>(moviePtr);
    if (!comedyPtr) return false;
    
    if (title != comedyPtr->title)
        return title < comedyPtr->title;
    
    return releaseYear < comedyPtr->releaseYear;
}

// Equality operator
bool Comedy::operator==(const Movie* moviePtr) const {
    const Comedy* comedyPtr = dynamic_cast<const Comedy*>(moviePtr);
    if (!comedyPtr) return false;
    
    return (title == comedyPtr->title && releaseYear == comedyPtr->releaseYear);
}