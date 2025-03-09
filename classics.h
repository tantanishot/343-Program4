#ifndef CLASSICS_H_
#define CLASSICS_H_

#include "movie.h"

class Classics: public Movie
{
    public:
        Classics(int movStock, string movDirector, string movTitle, string releaseAndMA);
        string formatSortCriteria() const;
        bool operator<(const Classics* classicsPtr) const;
        bool operator==(const Classics* classicsPtr) const;
    private:
        string MAFirstName;
        string MALastName;
};

#endif