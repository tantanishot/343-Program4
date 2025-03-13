#include "drama.h"

Drama::Drama(int movStock, string movDirector, string movTitle, int movRelease) 
        : Movie(movStock, movDirector, movTitle, movRelease) //call base class (mandatory)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "D";     // D for drama
}

string Drama::formatSortCriteria() const {
    return director + ", " + title;
}

bool Drama::operator<(const Movie* moviePtr) const {
    const Drama* dramaPtr = dynamic_cast<const Drama*>(moviePtr);
    if (dramaPtr == nullptr) return false;

    if (director.compare(dramaPtr->director) != 0)
        return director.compare(dramaPtr->director) < 0;

    return title.compare(dramaPtr->title) < 0;
}

bool Drama::operator>(const Movie* moviePtr) const {
    const Drama* dramaPtr = dynamic_cast<const Drama*>(moviePtr);
    if (dramaPtr == nullptr) return false;

    if (director.compare(dramaPtr->director) != 0)
        return director.compare(dramaPtr->director) > 0;

    return title.compare(dramaPtr->title) > 0;
}

bool Drama::operator==(const Movie* moviePtr) const {
    const Drama* dramaPtr = dynamic_cast<const Drama*>(moviePtr);
    if (dramaPtr == nullptr) return false;

    return (director.compare(dramaPtr->director) == 0 &&
            title.compare(dramaPtr->title) == 0);
}

string Drama::getItemType() const
{
    return itemType;
}

string Drama::getDVDType() const
{
    return DVDType;
}

string Drama::getCode() const
{
    return code;
}

void Drama::print() const
{
    cout << itemType << ", " << code << ", " << to_string(stock) << ", " << director << ", " << title << ", " <<
            releaseYear << endl;
}