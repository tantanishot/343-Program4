#include "classics.h"

Classics::Classics(int movStock, string movDirector, string movTitle, int movReleaseMon, int movReleaseYr, string firstName, string lastName)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "C";     // C for classics
    stock = movStock;
    director = movDirector;
    title = movTitle;
    releaseMonth = movReleaseMon;
    releaseYear = movReleaseYr;
    MAFirstName = firstName;
    MALastName = lastName;
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

string Classics::getItemType() const
{
    return itemType;
}

string Classics::getDVDType() const
{
    return DVDType;
}

void Classics::print() const
{
    cout << itemType << ", " << code << ", " << to_string(stock) << ", " << director << ", " << title << ", " <<
            MAFirstName << " " << MALastName << " " << releaseMonth << " " << releaseYear << endl;
}