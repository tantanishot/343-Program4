#ifndef DRAMA_H_
#define DRAMA_H_

#include "movie.h"

class Drama : public Movie
{
    public:
        Drama(int movStock, string movDirector, string movTitle, string movRelease);
        string formatSortCriteria() const;
        bool operator<(const Drama* dramaPtr) const;
        bool operator==(const Drama* dramaPtr) const;
};

#endif