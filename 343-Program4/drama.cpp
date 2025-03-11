#include "drama.h"

Drama::Drama(int movStock, string movDirector, string movTitle, int movRelease) 
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "D";     // D for drama
    stock = movStock;
    director = movDirector;
    title = movTitle;
    releaseYear = movRelease;
}

string Drama::formatSortCriteria() const {
    return director + "," + title;
}

bool Drama::operator<(const Movie* moviePtr) const {
    const Drama* dramaPtr = dynamic_cast<const Drama*>(moviePtr);
    if (!dramaPtr) return false;
    
    if (director != dramaPtr->director)
        return director < dramaPtr->director;
    
    return title < dramaPtr->title;
}

// Equality operator
bool Drama::operator==(const Movie* moviePtr) const {
    const Drama* dramaPtr = dynamic_cast<const Drama*>(moviePtr);
    if (!dramaPtr) return false;
    
    return (director == dramaPtr->director && title == dramaPtr->title);
}