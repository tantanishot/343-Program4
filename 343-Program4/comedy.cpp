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

bool Comedy::operator<(const Movie& movie) const {
    const Comedy& comedy = dynamic_cast<const Comedy&>(movie); // Reference cast

    if (title.compare(comedy.title) != 0)
        return title.compare(comedy.title) < 0;

    return releaseYear < comedy.releaseYear;
}

bool Comedy::operator>(const Movie& movie) const {
    const Comedy& comedy = dynamic_cast<const Comedy&>(movie); // Reference cast

    if (title.compare(comedy.title) != 0)
        return title.compare(comedy.title) > 0;

    return releaseYear > comedy.releaseYear;
}


bool Comedy::operator==(const Movie& movie) const {
    const Comedy& comedy = dynamic_cast<const Comedy&>(movie); // Reference cast

    return (title.compare(comedy.title) == 0 &&
            releaseYear == comedy.releaseYear);
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
    cout << setw(8) << left << itemType << setw(7) << left << code << setw(35) << left << title << setw(23) << left <<
            director << setw(18) << left << to_string(releaseYear) << to_string(stock) << endl;
}