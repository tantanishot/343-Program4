// ------------------------------------------------ comedy.cpp ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Child class that inherits from movie, stores all teh types of child classes

// -------------------------------------------------------------------------------------------------------------------- 

#include "comedy.h"
// ---------------------------------------- Comedy Constructor ----------------------------------------
// Description: Initializes a Comedy movie object and sets item type identifiers.
// preconditions: Valid stock, director, title, and release year inputs.
// postconditions: Comedy object is initialized with identifiers and Movie base data.
// --------------------------------------------------------------------------------------------
Comedy::Comedy(int movStock, string movDirector, string movTitle, int movRelease) 
 :  Movie(movStock, movDirector, movTitle, movRelease) //Call base class(mandatory)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "F";     // F for funny
}
// ---------------------------------------- formatSortCriteria ----------------------------------------
// Description: Returns a formatted string used for sorting Comedy movies.
// preconditions: Comedy movie must have valid title and releaseYear.
// postconditions: Returns "title, releaseYear" as a string.
// --------------------------------------------------------------------------------------------
string Comedy::formatSortCriteria() const
{
    return title + ", " + to_string(releaseYear);
}

// ---------------------------------------- operator< ----------------------------------------
// Description: Less-than comparison operator for Comedy movies by title then releaseYear.
// preconditions: The passed Movie object must be a Comedy type.
// postconditions: Returns true if this Comedy is less than the other Comedy.
// --------------------------------------------------------------------------------------------
bool Comedy::operator<(const Movie& movie) const {
    const Comedy& comedy = dynamic_cast<const Comedy&>(movie); // Reference cast

    if (title.compare(comedy.title) != 0)
        return title.compare(comedy.title) < 0;

    return releaseYear < comedy.releaseYear;
}

// ---------------------------------------- operator> ----------------------------------------
// Description: Greater-than comparison operator for Comedy movies by title then releaseYear.
// preconditions: The passed Movie object must be a Comedy type.
// postconditions: Returns true if this Comedy is greater than the other Comedy.
// --------------------------------------------------------------------------------------------
bool Comedy::operator>(const Movie& movie) const {
    const Comedy& comedy = dynamic_cast<const Comedy&>(movie); // Reference cast

    if (title.compare(comedy.title) != 0)
        return title.compare(comedy.title) > 0;

    return releaseYear > comedy.releaseYear;
}


// ---------------------------------------- operator== ----------------------------------------
// Description: Equality comparison operator for Comedy movies by title and releaseYear.
// preconditions: The passed Movie object must be a Comedy type.
// postconditions: Returns true if both Comedy movies are equal.
// --------------------------------------------------------------------------------------------

bool Comedy::operator==(const Movie& movie) const {
    const Comedy& comedy = dynamic_cast<const Comedy&>(movie); // Reference cast

    return (title.compare(comedy.title) == 0 &&
            releaseYear == comedy.releaseYear);
}
// ---------------------------------------- getItemType ----------------------------------------
// Description: Returns the itemType identifier ("D").
// preconditions: None.
// postconditions: Returns "D" for DVD.
// --------------------------------------------------------------------------------------------
string Comedy::getItemType() const
{
    return itemType;
}
// ---------------------------------------- getDVDType ----------------------------------------
// Description: Returns the DVDType identifier ("M").
// preconditions: None.
// postconditions: Returns "M" for Movie.
// --------------------------------------------------------------------------------------------
string Comedy::getDVDType() const
{
    return DVDType;
}
// ---------------------------------------- getCode ----------------------------------------
// Description: Returns the code for Comedy movies ("F").
// preconditions: None.
// postconditions: Returns "F" for Comedy genre.
// --------------------------------------------------------------------------------------------
string Comedy::getCode() const
{
    return code;
}
// ---------------------------------------- getTitle ----------------------------------------
// Description: Returns the title of the Comedy movie.
// preconditions: Title must be initialized.
// postconditions: Returns the movie title.
// --------------------------------------------------------------------------------------------
string Comedy::getTitle() const {
    return title;
}
// ---------------------------------------- getDirector ----------------------------------------
// Description: Returns the director of the Comedy movie.
// preconditions: Director must be initialized.
// postconditions: Returns the movie director.
// --------------------------------------------------------------------------------------------
string Comedy::getDirector() const {
    return director;
}

// ---------------------------------------- getStock ----------------------------------------
// Description: Returns the current stock of the Comedy movie.
// preconditions: Stock must be initialized.
// postconditions: Returns stock as an integer.
// --------------------------------------------------------------------------------------------
int Comedy::getStock() const {
    return stock;
}
// ---------------------------------------- adjustStock ----------------------------------------
// Description: Adjusts stock up or down based on increment flag, bounded by limits.
// preconditions: Stock >= 0; increment is true (increase) or false (decrease).
// postconditions: Returns true if stock adjusted; false if at bounds.
// --------------------------------------------------------------------------------------------
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


// ---------------------------------------- print ----------------------------------------
// Description: Outputs the Comedy movie's details in a formatted line.
// preconditions: All fields must be initialized.
// postconditions: Displays the movie's information.
// --------------------------------------------------------------------------------------------
void Comedy::print() const
{
    cout << itemType << ", " << code << ", " << to_string(stock) << ", " << director << ", " << title << ", " <<
            releaseYear << endl;
}