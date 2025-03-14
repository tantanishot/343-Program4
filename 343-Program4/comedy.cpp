#include "comedy.h"

Comedy::Comedy(int movStock, string movDirector, string movTitle, int movRelease) 
 :  Movie(movStock, movDirector, movTitle, movRelease) //Call base class(mandatory)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "F";     // F for funny
}

string Comedy::formatSortCriteria() const
{
    return title + ", " + to_string(releaseYear);
}

bool Comedy::operator<(const Movie* moviePtr) const {
    const Comedy* comedyPtr = dynamic_cast<const Comedy*>(moviePtr);
    if (comedyPtr == nullptr) return false;

    if (title.compare(comedyPtr->title) != 0)
        return title.compare(comedyPtr->title) < 0;

    return releaseYear < comedyPtr->releaseYear;
}

bool Comedy::operator>(const Movie* moviePtr) const {
    const Comedy* comedyPtr = dynamic_cast<const Comedy*>(moviePtr);
    if (comedyPtr == nullptr) return false;

    if (title.compare(comedyPtr->title) != 0)
        return title.compare(comedyPtr->title) > 0;

    return releaseYear > comedyPtr->releaseYear;
}

bool Comedy::operator==(const Movie* moviePtr) const {
    const Comedy* comedyPtr = dynamic_cast<const Comedy*>(moviePtr);
    if (comedyPtr == nullptr) return false;

    return (title.compare(comedyPtr->title) == 0 &&
            releaseYear == comedyPtr->releaseYear);
}

string Comedy::getItemType() const
{
    return itemType;
}

string Comedy::getDVDType() const
{
    return DVDType;
}

string Comedy::getCode() const
{
    return code;
}

string Comedy::getTitle() const {
    return title;
}

string Comedy::getDirector() const {
    return director;
}

int Comedy::getStock() const {
    return stock;
}

bool Comedy::adjustStock(const bool increment)
{
    if (increment && stock < stockCap)
    {
        stock++;
        return true;
    }
    if (stock > 0) // increment is false (decrement)
    {
        stock--;
        return true;
    }
    return false; // cannot decrease stock below 0
}

void Comedy::print() const
{
    cout << itemType << ", " << code << ", " << to_string(stock) << ", " << director << ", " << title << ", " <<
            releaseYear << endl;
}