// ------------------------------------------------ drama.h ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - one of the child classes for movie, represents a drama genre of a movie

// -------------------------------------------------------------------------------------------------------------------- 


#ifndef DRAMA_H_
#define DRAMA_H_

#include "movie.h"

class Drama : public Movie
{
    public: 
        //Required constructor for attributes (similar to Comedy)
        Drama(int movStock, string movDirector, string movTitle, int movRelease);

        string getItemType() const override;
        string getDVDType() const override;
        
        //getters for testing
        string getCode() const override;
        int getStock() const override;
        string getTitle() const override;
        string getDirector() const override;

        bool adjustStock(const bool increment) override;

        //sorting criteria based on director, then title
        string formatSortCriteria() const override;

        bool operator<(const Movie& moviePtr) const override;
        bool operator>(const Movie& moviePtr) const override;
        bool operator==(const Movie& moviePtr) const override;
        //print current object
        void print() const override;
};

#endif