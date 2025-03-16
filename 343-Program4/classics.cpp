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

string Classics::getMA() const
{
    return MAFirstName + " " + MALastName;
}

bool Classics::adjustStock(const bool increment)
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

bool Classics::isSimilar(Classics* classicsPtr) const
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
bool Classics::operator<(const Movie& movie) const {
    const Classics& classics = dynamic_cast<const Classics&>(movie); // Now a reference

    if (releaseYear != classics.releaseYear) 
        return releaseYear < classics.releaseYear;

    if (releaseMonth != classics.releaseMonth)
        return releaseMonth < classics.releaseMonth;

    if (MAFirstName.compare(classics.MAFirstName) != 0)
        return MAFirstName.compare(classics.MAFirstName) < 0;

    return MALastName.compare(classics.MALastName) < 0;
}

bool Classics::operator>(const Movie& movie) const {
    const Classics& classics = dynamic_cast<const Classics&>(movie); // Now a reference

    if (releaseYear != classics.releaseYear) 
        return releaseYear > classics.releaseYear;

    if (releaseMonth != classics.releaseMonth)
        return releaseMonth > classics.releaseMonth;

    if (MAFirstName.compare(classics.MAFirstName) != 0)
        return MAFirstName.compare(classics.MAFirstName) > 0;

    return MALastName.compare(classics.MALastName) > 0;
}


bool Classics::operator==(const Movie& movie) const {
    const Classics& classics = dynamic_cast<const Classics&>(movie); // Now a reference

    return (releaseMonth == classics.releaseMonth &&
            releaseYear == classics.releaseYear &&
            MAFirstName.compare(classics.MAFirstName) == 0 &&
            MALastName.compare(classics.MALastName) == 0);
            
}
void Classics::print() const
{
    cout << setw(8) << left << itemType << setw(7) << left << code << setw(35) << left << title << setw(23) << left <<
            director << setw(10) << left << to_string(releaseMonth) << setw(8) << left << to_string(releaseYear) <<
            to_string(stock) << endl;
}