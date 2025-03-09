#ifndef MOVIE_H_
#define MOVIE_H_

#include "DVD.h"

class Movie : public DVD
{
    public:
        virtual string formatSortCriteria() const = 0;
        virtual bool operator<(const Movie* moviePtr) const = 0;
        virtual bool operator==(const Movie* moviePtr) const = 0;
    protected:
        string code;
        int stock;
        string director;
        string title;
        string releaseYear;
};

#endif