#ifndef MOVIE_H_
#define MOVIE_H_

#include "DVD.h"

class Movie : public DVD
{
    public:
        Movie(int movStock, string movDirector, string movTitle, int movRelease) 
        : stock(movStock), stockCap(movStock), director(movDirector), title(movTitle), releaseYear(movRelease) {}

        virtual string getCode() const = 0;
        virtual int getStock() const = 0;
        virtual string getTitle() const = 0;
        virtual string getDirector() const = 0;

        virtual bool adjustStock(const bool increment) = 0;

        virtual string formatSortCriteria() const = 0;
        
        virtual bool operator<(const Movie& movie) const = 0;
        virtual bool operator>(const Movie& movie) const = 0;
        virtual bool operator==(const Movie& movie) const = 0;

    protected:
        string code;
        int stock;
        int stockCap;
        string director;
        string title;
        int releaseYear;
};

#endif