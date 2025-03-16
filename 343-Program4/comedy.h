// ------------------------------------------------ comedy.h ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - Child class of movie, stores the comedy type movies as an object

// -------------------------------------------------------------------------------------------------------------------- 



#ifndef COMEDY_H_
#define COMEDY_H_

#include "movie.h"

class Comedy : public Movie
{
    public:
        //comedy class constrcutor based on requirements here
        Comedy(int movStock, string movDirector, string movTitle, int movRelease);
        
        //return the item type or getDVD
        string getItemType() const override;
        string getDVDType() const override;

        //get following information for testing
        string getCode() const override;
        int getStock() const override;
        string getTitle() const override;
        string getDirector() const override;
        //adjust stock based on status
        bool adjustStock(const bool increment) override;

        //format sort criteria sorted by title then year released.
        string formatSortCriteria() const override;

        bool operator<(const Movie& moviePtr) const override;
        bool operator>(const Movie& moviePtr) const override;
        bool operator==(const Movie& moviePtr) const override;
        //test print the object
        void print() const override;
};

#endif