#ifndef MOVIE_H_
#define MOVIE_H_

#include "DVD.h"

class Movie : public DVD
{
    public:
        //since this is an ADT i think its important to have a construcotr still
        Movie(int movStock, string movDirector, string movTitle, int movRelease) 
        : stock(movStock), director(movDirector), title(movTitle), releaseYear(movRelease) {}


        virtual string formatSortCriteria() const = 0;
        virtual bool operator<(const Movie* moviePtr) const = 0;
        virtual bool operator>(const Movie* moviePtr) const = 0;
        virtual bool operator==(const Movie* moviePtr) const = 0;

    protected:
        string code;
        int stock;
        string director;
        string title;
        int releaseYear;
};

#endif