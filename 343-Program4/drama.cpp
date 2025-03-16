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

bool Drama::operator<(const Movie& movie) const {
    const Drama& drama = dynamic_cast<const Drama&>(movie); // Reference cast

    if (director.compare(drama.director) != 0)
        return director.compare(drama.director) < 0;

    return title.compare(drama.title) < 0;
}


bool Drama::operator>(const Movie& movie) const {
    const Drama& drama = dynamic_cast<const Drama&>(movie); // Reference cast

    if (director.compare(drama.director) != 0)
        return director.compare(drama.director) > 0;

    return title.compare(drama.title) > 0;
}


bool Drama::operator==(const Movie& movie) const {
    const Drama& drama = dynamic_cast<const Drama&>(movie); // Reference cast

    return (director.compare(drama.director) == 0 &&
            title.compare(drama.title) == 0);
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

string Drama::getTitle() const {
    return title;
}

string Drama::getDirector() const {
    return director;
}

int Drama::getStock() const {
    return stock;
}

bool Drama::adjustStock(const bool increment)
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

void Drama::print() const
{
    cout << setw(8) << left << itemType << setw(7) << left << code << setw(35) << left << title << setw(23) << left <<
            director << setw(18) << left << to_string(releaseYear) << to_string(stock) << endl;
}