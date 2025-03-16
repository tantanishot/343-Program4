// ------------------------------------------------ classics.h ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - child class of movie, very specific criteria for this class

// -------------------------------------------------------------------------------------------------------------------- 


#ifndef CLASSICS_H_
#define CLASSICS_H_

#include "movie.h"

class Classics : public Movie
{
    public:
        //constructor that requires the important attributes
        Classics(int movStock, string movDirector, string movTitle, int movReleaseMon, int movReleaseYr, string firstName, string lastName);
        
        string getItemType() const override;
        string getDVDType() const override;

        string getCode() const override;
        int getStock() const override;
        string getTitle() const override;
        string getDirector() const override;

        bool adjustStock(const bool increment) override;

        //checks if the there are any movies that are the same 
        //however finds a different actor
        bool isSimilar(const Classics* classicsPtr) const;
        //the sorting criteria following, release date - then major actor
        string formatSortCriteria() const override;

        bool operator<(const Movie& movie) const override;
        bool operator>(const Movie& movie) const override;
        bool operator==(const Movie& movie) const override;

        void print() const override;

    private:
        int releaseMonth;
        //MA = major actor
        string MAFirstName;
        string MALastName;
    };

#endif