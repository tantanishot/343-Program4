#ifndef CLASSICS_H_
#define CLASSICS_H_

#include "movie.h"

class Classics : public Movie
{
    public:
        Classics(int movStock, string movDirector, string movTitle, int movReleaseMon, int movReleaseYr, string firstName, string lastName);
        
        string getItemType() const override;
        string getDVDType() const override;

        string getCode() const override;
        int getStock() const override;
        string getTitle() const override;
        string getDirector() const override;

        bool adjustStock(const bool increment) override;

        bool isSimilar(Classics* classicsPtr);

        string formatSortCriteria() const override;

        bool operator<(const Movie* moviePtr) const override;
        bool operator>(const Movie* moviePtr) const override;
        bool operator==(const Movie* moviePtr) const override;

        void print() const override;

    private:
        int releaseMonth;
        string MAFirstName;
        string MALastName;
    };

#endif