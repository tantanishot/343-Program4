#include "classics.h"

Classics::Classics(int movStock, string movDirector, string movTitle, int releaseMonth, int releaseYear, string firstName, string lastName)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "C";     // C for classics
    stock = movStock;
    director = movDirector;
    title = movTitle;
    this->releaseMonth = releaseMonth;
    this->releaseYear = releaseYear;
    MAFirstName = firstName;
    MALastName = lastName;
    //Thought this was unecessary to using split and we can already just split them up in the given string
    /*
    // split release year and name with name having first and last split
    MAFirstName = releaseAndMA.substr(0, releaseAndMA.find(" "));
    MALastName = releaseAndMA.substr(MAFirstName.length() + 1, releaseAndMA.substr(MAFirstName.length() + 1).find(" "));
    releaseYear = releaseAndMA.substr(MAFirstName.length() + MALastName.length() + 3);
    */
}

string Classics::formatSortCriteria() const {
    return to_string(releaseMonth) + " " + to_string(releaseYear) + " " + MAFirstName + " " + MALastName;
}

bool Classics::operator<(const Movie* moviePtr) const {
    const Classics* classicsPtr = dynamic_cast<const Classics*>(moviePtr);
    if (!classicsPtr) return false;

    if (releaseYear != classicsPtr->releaseYear) 
        return releaseYear < classicsPtr->releaseYear;

    if (releaseMonth != classicsPtr->releaseMonth)
        return releaseMonth < classicsPtr->releaseMonth;


    if (MAFirstName != classicsPtr->MAFirstName)
        return MAFirstName < classicsPtr->MAFirstName;

    return MALastName < classicsPtr->MALastName;
}

// Equality operator
bool Classics::operator==(const Movie* moviePtr) const {
    const Classics* classicsPtr = dynamic_cast<const Classics*>(moviePtr);
    if (!classicsPtr) return false;

    return (title == classicsPtr->title &&
            releaseMonth == classicsPtr->releaseMonth &&
            releaseYear == classicsPtr->releaseYear &&
            MAFirstName == classicsPtr->MAFirstName &&
            MALastName == classicsPtr->MALastName);
}