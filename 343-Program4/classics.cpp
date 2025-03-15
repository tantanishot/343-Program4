#include "classics.h"

Classics::Classics(int movStock, string movDirector, string movTitle, int movReleaseMon, int movReleaseYr, string firstName, string lastName) 
        :  Movie(movStock, movDirector, movTitle, movReleaseYr), releaseMonth(movReleaseMon), MAFirstName(firstName), MALastName(lastName)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "C";     // C for classics
}

string Classics::getItemType() const
{
    return itemType;
}

string Classics::getDVDType() const
{
    return DVDType;
}

string Classics::getCode() const
{
    return code;
}

string Classics::getTitle() const
{
    return title;
}

string Classics::getDirector() const
{
    return director;
}

int Classics::getStock() const {
    return stock; 
}

bool Classics::adjustStock(const bool increment)
{
    if (increment)
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

bool Classics::isSimilar(const Classics* classicsPtr) const
{

    //perform null check
    if (classicsPtr == nullptr)
    {
        return false;
    } 
    // everything is the same except for main actor name
    return (releaseMonth == classicsPtr->releaseMonth && releaseYear == classicsPtr->releaseYear &&
        director.compare(classicsPtr->director) == 0 && title.compare(classicsPtr->title) == 0 &&
        (MAFirstName.compare(classicsPtr->MAFirstName) != 0 || MALastName.compare(classicsPtr->MALastName) != 0));
}

string Classics::formatSortCriteria() const {
    return to_string(releaseMonth) + " " + to_string(releaseYear) + " " + MAFirstName + " " + MALastName;
}

bool Classics::operator<(const Movie* moviePtr) const {
    const Classics* classicsPtr = dynamic_cast<const Classics*>(moviePtr);
    if (classicsPtr == nullptr) return false;

    if (releaseYear != classicsPtr->releaseYear) 
        return releaseYear < classicsPtr->releaseYear;

    if (releaseMonth != classicsPtr->releaseMonth)
        return releaseMonth < classicsPtr->releaseMonth;

    if (MAFirstName.compare(classicsPtr->MAFirstName) != 0)
        return MAFirstName.compare(classicsPtr->MAFirstName) < 0;

    return MALastName.compare(classicsPtr->MALastName) < 0;
}

bool Classics::operator>(const Movie* moviePtr) const {
    const Classics* classicsPtr = dynamic_cast<const Classics*>(moviePtr);
    if (classicsPtr == nullptr) return false;

    if (releaseYear != classicsPtr->releaseYear) 
        return releaseYear > classicsPtr->releaseYear;

    if (releaseMonth != classicsPtr->releaseMonth)
        return releaseMonth > classicsPtr->releaseMonth;

    if (MAFirstName.compare(classicsPtr->MAFirstName) != 0)
        return MAFirstName.compare(classicsPtr->MAFirstName) > 0;

    return MALastName.compare(classicsPtr->MALastName) > 0;
}

bool Classics::operator==(const Movie* moviePtr) const {
    const Classics* classicsPtr = dynamic_cast<const Classics*>(moviePtr);
    if (classicsPtr == nullptr) return false;

    return (releaseMonth == classicsPtr->releaseMonth &&
            releaseYear == classicsPtr->releaseYear &&
            MAFirstName.compare(classicsPtr->MAFirstName) == 0 &&
            MALastName.compare(classicsPtr->MALastName) == 0);
}

void Classics::print() const
{
    cout << itemType << ", " << code << ", " << to_string(stock) << ", " << director << ", " << title << ", " <<
            MAFirstName << " " << MALastName << " " << releaseMonth << " " << releaseYear << endl;
}