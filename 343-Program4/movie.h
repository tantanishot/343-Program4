#ifndef MOVIE_H_
#define MOVIE_H_

#include "DVD.h"

class Movie : public DVD
{
    public:
        //Constructors(optional since we have other constructors in child)
        Movie();
        Movie(int movStock, string movDirector, string movTitle, int movRelease);
        virtual string formatSortCriteria() const = 0;
        virtual bool operator<(const Movie* moviePtr) const = 0;
        virtual bool operator==(const Movie* moviePtr) const = 0;

        //implement other virtual functions
        string getDVDType() const override;
        string getItemType() const override;


        protected:
        string code;
        int stock;
        string director;
        string title;
        int releaseYear; // changed to int to directly compare dates
};

#endif