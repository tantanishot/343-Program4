#ifndef DRAMA_H_
#define DRAMA_H_

#include "movie.h"
class Drama : public Movie
{
    public:
        Drama(int movStock, string movDirector, string movTitle, int movRelease);
        string formatSortCriteria() const;
        bool operator<(const Movie* moviePtr) const override; // Compare against Movie*
        bool operator==(const Movie* moviePtr) const override;
};


#endif