#ifndef COMEDY_H_
#define COMEDY_H_

#include "movie.h"

class Comedy : public Movie
{
    public:
        Comedy(int movStock, string movDirector, string movTitle, int movRelease);
        
        string formatSortCriteria() const;
        bool operator<(const Movie* moviePtr) const;
        bool operator>(const Movie* moviePtr) const;
        bool operator==(const Movie* moviePtr) const;

        string getItemType() const;
        string getDVDType() const;
        void print() const;
};

#endif