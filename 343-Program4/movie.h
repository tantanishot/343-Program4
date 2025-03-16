// ------------------------------------------------ movie.h ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Movie parent object which is an ADT

// -------------------------------------------------------------------------------------------------------------------- 
#ifndef MOVIE_H_
#define MOVIE_H_

#include "DVD.h"

class Movie : public DVD
{
    public:
        //Constructors here, passes in the required elements
        Movie(int movStock, string movDirector, string movTitle, int movRelease) 
        : stock(movStock), stockCap(movStock), director(movDirector), title(movTitle), releaseYear(movRelease) {}

        //implementation required for children classes for the following
        virtual string getCode() const = 0;
        virtual int getStock() const = 0;
        virtual string getTitle() const = 0;
        virtual string getDirector() const = 0;

        //adjust stock based on the type
        virtual bool adjustStock(const bool increment) = 0;
        //the following methods utilize the format sort criteria based on the directions in canvas
        virtual string formatSortCriteria() const = 0;
        
        virtual bool operator<(const Movie& movie) const = 0;
        virtual bool operator>(const Movie& movie) const = 0;
        virtual bool operator==(const Movie& movie) const = 0;

    protected:
        string code; //aka genre
        int stock;   //current stock
        int stockCap; //most amount of stock allowed
        string director; //director name
        string title;   
        int releaseYear;
};

#endif