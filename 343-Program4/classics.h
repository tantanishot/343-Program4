#ifndef CLASSICS_H_
#define CLASSICS_H_

#include "movie.h"

class Classics : public Movie {
    public:
        Classics(int movStock, string movDirector, string movTitle, int releaseMonth, int releaseYear, string firstName, string lastName);
        
        string formatSortCriteria() const override;
        bool operator<(const Movie* moviePtr) const override;
        bool operator==(const Movie* moviePtr) const override;
    
    private:
        //split release month and year for easier sorting
        int releaseMonth;
        int releaseYear;
        string MAFirstName;
        string MALastName;
    };

#endif