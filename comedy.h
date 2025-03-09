#ifndef COMEDY_H_
#define COMEDY_H_

#include "movie.h"

class Comedy : public Movie
{
    public:
        Comedy(int movStock, string movDirector, string movTitle, string movRelease);
        string formatSortCriteria() const;
        bool operator<(const Comedy* comedyPtr) const;
        bool operator==(const Comedy* comedyPtr) const;
};

#endif