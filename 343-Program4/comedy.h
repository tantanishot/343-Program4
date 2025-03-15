#ifndef COMEDY_H_
#define COMEDY_H_

#include "movie.h"

class Comedy : public Movie
{
    public:
        Comedy(int movStock, string movDirector, string movTitle, int movRelease);
        
        string getItemType() const override;
        string getDVDType() const override;

        string getCode() const override;
        int getStock() const override;
        string getTitle() const override;
        string getDirector() const override;

        bool adjustStock(const bool increment) override;

        string formatSortCriteria() const override;

        bool operator<(const Movie& moviePtr) const override;
        bool operator>(const Movie& moviePtr) const override;
        bool operator==(const Movie& moviePtr) const override;

        void print() const override;
};

#endif