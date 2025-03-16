// ------------------------------------------------ drama.cpp ------------------------------------------------------- 
// Tristan Santor, Ethan Phonsouk  CSS 343
// 3/14/25
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation of the drama type: child class of Movie
// -------------------------------------------------------------------------------------------------------------------- 

#include "drama.h"
// ---------------------------------------- Drama Constructor ----------------------------------------
// Description: Initializes a Drama movie object and sets item type identifiers.
// preconditions: Valid stock, director, title, and release year inputs.
// postconditions: Drama object is initialized with identifiers and Movie base data.
// --------------------------------------------------------------------------------------------
Drama::Drama(int movStock, string movDirector, string movTitle, int movRelease) 
        : Movie(movStock, movDirector, movTitle, movRelease) //call base class (mandatory)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "D";     // D for drama
}
// ---------------------------------------- formatSortCriteria ----------------------------------------
// Description: Returns a formatted string used for sorting Drama movies.
// preconditions: Drama movie must have valid director and title.
// postconditions: Returns "director, title" as a string.
// --------------------------------------------------------------------------------------------
string Drama::formatSortCriteria() const {
    return director + ", " + title;
}
// ---------------------------------------- operator< ----------------------------------------
// Description: Less-than comparison for Drama by director then title.
// preconditions: The passed Movie must be a Drama type.
// postconditions: Returns true if this Drama is less than the other.
// --------------------------------------------------------------------------------------------
bool Drama::operator<(const Movie& movie) const {
    const Drama& drama = dynamic_cast<const Drama&>(movie); // Reference cast

    if (director.compare(drama.director) != 0)
        return director.compare(drama.director) < 0;

    return title.compare(drama.title) < 0;
}

// ---------------------------------------- operator> ----------------------------------------
// Description: Greater-than comparison for Drama by director then title.
// preconditions: The passed Movie must be a Drama type.
// postconditions: Returns true if this Drama is greater than the other.
// --------------------------------------------------------------------------------------------
bool Drama::operator>(const Movie& movie) const {
    const Drama& drama = dynamic_cast<const Drama&>(movie); // Reference cast

    if (director.compare(drama.director) != 0)
        return director.compare(drama.director) > 0;

    return title.compare(drama.title) > 0;
}

// ---------------------------------------- operator== ----------------------------------------
// Description: Equality comparison for Drama based on director and title.
// preconditions: The passed Movie must be a Drama type.
// postconditions: Returns true if all fields match.
// --------------------------------------------------------------------------------------------
bool Drama::operator==(const Movie& movie) const {
    const Drama& drama = dynamic_cast<const Drama&>(movie); // Reference cast

    return (director.compare(drama.director) == 0 &&
            title.compare(drama.title) == 0);
}
// ---------------------------------------- getItemType ----------------------------------------
// Description: Returns the itemType identifier ("D").
// preconditions: None.
// postconditions: Returns "D" for DVD.
// --------------------------------------------------------------------------------------------
string Drama::getItemType() const
{
    return itemType;
}

// ---------------------------------------- getDVDType ----------------------------------------
// Description: Returns the DVDType identifier ("M").
// preconditions: None.
// postconditions: Returns "M" for Movie.
// --------------------------------------------------------------------------------------------
string Drama::getDVDType() const
{
    return DVDType;
}
// ---------------------------------------- getCode ----------------------------------------
// Description: Returns the code for Drama movies ("D").
// preconditions: None.
// postconditions: Returns "D" for Drama genre.
// --------------------------------------------------------------------------------------------
string Drama::getCode() const
{
    return code;
}
// ---------------------------------------- getTitle ----------------------------------------
// Description: Returns the title of the Drama movie.
// preconditions: Title must be initialized.
// postconditions: Returns the movie title.
// --------------------------------------------------------------------------------------------
string Drama::getTitle() const {
    return title;
}
// ---------------------------------------- getDirector ----------------------------------------
// Description: Returns the director of the Drama movie.
// preconditions: Director must be initialized.
// postconditions: Returns the movie director.
// --------------------------------------------------------------------------------------------
string Drama::getDirector() const {
    return director;
}
// ---------------------------------------- getStock ----------------------------------------
// Description: Returns the current stock of the Drama movie.
// preconditions: Stock must be initialized.
// postconditions: Returns stock as an integer.
// --------------------------------------------------------------------------------------------
int Drama::getStock() const {
    return stock;
}
// ---------------------------------------- adjustStock ----------------------------------------
// Description: Adjusts stock up or down based on increment flag, bounded by limits.
// preconditions: Stock >= 0; increment is true (increase) or false (decrease).
// postconditions: Returns true if stock adjusted; false if at bounds.
// --------------------------------------------------------------------------------------------
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

// ---------------------------------------- print ----------------------------------------
// Description: Outputs the Drama movie's details in a formatted line.
// preconditions: All fields must be initialized.
// postconditions: Displays the movie's information.
// --------------------------------------------------------------------------------------------
void Drama::print() const
{
    cout << itemType << ", " << code << ", " << to_string(stock) << ", " << director << ", " << title << ", " <<
            releaseYear << endl;
}