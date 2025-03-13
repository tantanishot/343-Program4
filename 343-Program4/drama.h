#ifndef DRAMA_H_
#define DRAMA_H_

#include "movie.h"

class Drama : public Movie
{
    public:
        Drama(int movStock, string movDirector, string movTitle, int movRelease);

        string getItemType() const override;
        string getDVDType() const override;
        
        string getCode() const override;
        string getTitle() const override;
        string getDirector() const override;

        string formatSortCriteria() const override;

        bool operator<(const Movie* moviePtr) const override;
        bool operator>(const Movie* moviePtr) const override;
        bool operator==(const Movie* moviePtr) const override;

        void print() const override;
};

#endif