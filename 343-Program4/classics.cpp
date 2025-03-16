// ------------------------------------------------ classics.cpp------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - implementation of the classics type: child class of movie

// -------------------------------------------------------------------------------------------------------------------- 
#include "classics.h"

// ---------------------------------------- Classics Constructor ----------------------------------------
// Description: Initializes a Classics movie object with month, year, and main actor details.
// preconditions: Valid stock, director, title, month, year, and actor names provided.
// postconditions: Classics object initialized with all provided values and identifiers.
// --------------------------------------------------------------------------------------------
Classics::Classics(int movStock, string movDirector, string movTitle, int movReleaseMon, int movReleaseYr, string firstName, string lastName) 
        :  Movie(movStock, movDirector, movTitle, movReleaseYr), releaseMonth(movReleaseMon), MAFirstName(firstName), MALastName(lastName)
{
    itemType = "D"; // D for dvd
    DVDType = "M";  // M for movie
    code = "C";     // C for classics
}

// ---------------------------------------- getItemType ----------------------------------------
// Description: Returns the itemType identifier ("D").
// preconditions: None.
// postconditions: Returns "D" for DVD.
// --------------------------------------------------------------------------------------------
string Classics::getItemType() const
{
    return itemType;
}

// ---------------------------------------- getDVDType ----------------------------------------
// Description: Returns the DVDType identifier ("M").
// preconditions: None.
// postconditions: Returns "M" for Movie.
// --------------------------------------------------------------------------------------------
string Classics::getDVDType() const
{
    return DVDType;
}

// ---------------------------------------- getCode ----------------------------------------
// Description: Returns the code for Classics movies ("C").
// preconditions: None.
// postconditions: Returns "C" for Classics genre.
// --------------------------------------------------------------------------------------------
string Classics::getCode() const
{
    return code;
}

// ---------------------------------------- getTitle ----------------------------------------
// Description: Returns the title of the Classics movie.
// preconditions: Title must be initialized.
// postconditions: Returns the movie title.
// --------------------------------------------------------------------------------------------
string Classics::getTitle() const
{
    return title;
}

// ---------------------------------------- getDirector ----------------------------------------
// Description: Returns the director of the Classics movie.
// preconditions: Director must be initialized.
// postconditions: Returns the movie director.
// --------------------------------------------------------------------------------------------
string Classics::getDirector() const
{
    return director;
}

// ---------------------------------------- getStock ----------------------------------------
// Description: Returns the current stock of the Classics movie.
// preconditions: Stock must be initialized.
// postconditions: Returns stock as an integer.
// --------------------------------------------------------------------------------------------
int Classics::getStock() const {
    return stock;   
}

string Classics::getMA() const
{
    return MAFirstName + " " + MALastName;
}

// ---------------------------------------- adjustStock ----------------------------------------
// Description: Adjusts stock up or down based on increment flag, bounded by limits.
// preconditions: Stock >= 0; increment is true (increase) or false (decrease).
// postconditions: Returns true if stock adjusted; false if at bounds.
// --------------------------------------------------------------------------------------------
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

// ---------------------------------------- isSimilar ----------------------------------------
// Description: Checks if two Classics movies are similar except for actor names.
// preconditions: classicsPtr must not be null.
// postconditions: Returns true if month, year, director, and title match but actor names differ.
// --------------------------------------------------------------------------------------------
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

// ---------------------------------------- formatSortCriteria ----------------------------------------
// Description: Returns a formatted string used for sorting Classics movies.
// preconditions: Valid releaseMonth, releaseYear, and actor names.
// postconditions: Returns "month year FirstName LastName" as a string.
// --------------------------------------------------------------------------------------------
string Classics::formatSortCriteria() const {
    return to_string(releaseMonth) + " " + to_string(releaseYear) + " " + MAFirstName + " " + MALastName;
}

// ---------------------------------------- operator< ----------------------------------------
// Description: Less-than comparison for Classics by year, month, first then last name.
// preconditions: The passed Movie must be a Classics type.
// postconditions: Returns true if this Classics is less than the other.
// --------------------------------------------------------------------------------------------
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

// ---------------------------------------- operator> ----------------------------------------
// Description: Greater-than comparison for Classics by year, month, first then last name.
// preconditions: The passed Movie must be a Classics type.
// postconditions: Returns true if this Classics is greater than the other.
// --------------------------------------------------------------------------------------------
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

// ---------------------------------------- operator== ----------------------------------------
// Description: Equality comparison for Classics based on month, year, and actor names.
// preconditions: The passed Movie must be a Classics type.
// postconditions: Returns true if all fields match.
// --------------------------------------------------------------------------------------------
bool Classics::operator==(const Movie& movie) const {
    const Classics& classics = dynamic_cast<const Classics&>(movie); // Now a reference

    return (releaseMonth == classics.releaseMonth &&
            releaseYear == classics.releaseYear &&
            MAFirstName.compare(classics.MAFirstName) == 0 &&
            MALastName.compare(classics.MALastName) == 0);
            
}

// ---------------------------------------- print ----------------------------------------
// Description: Outputs the Classics movie's details in a formatted line.
// preconditions: All fields must be initialized.
// postconditions: Displays the movie's information.
// --------------------------------------------------------------------------------------------
void Classics::print() const
{
    cout << setw(8) << left << itemType << setw(7) << left << code << setw(35) << left << title << setw(23) << left <<
            director << setw(10) << left << to_string(releaseMonth) << setw(8) << left << to_string(releaseYear) <<
            to_string(stock) << endl;
}