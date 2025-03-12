#ifndef CLASSICS_H_
#define CLASSICS_H_

#include "movie.h"

class Classics : public Movie
{
    public:
        Classics(int movStock, string movDirector, string movTitle, int movReleaseMon, int movReleaseYr, string firstName, string lastName);
        
        string formatSortCriteria() const override;
        bool operator<(const Movie* moviePtr) const override;
        bool operator>(const Movie* moviePtr) const override;
        bool operator==(const Movie* moviePtr) const override;

        string getItemType() const override;
        string getDVDType() const override;
        void print() const override;
    
    private:
        int releaseMonth;
        int releaseYear;
        string MAFirstName;
        string MALastName;
    };

#endif