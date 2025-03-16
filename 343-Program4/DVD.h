// ------------------------------------------------ DVD.h ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - One of the types of items, so this can utilize other different types of movie players

// -------------------------------------------------------------------------------------------------------------------- 

#ifndef DVD_H_
#define DVD_H_

#include "item.h"

class DVD : public Item
{
    public:
        //method requires to be implemented based on child classes
        virtual string getDVDType() const = 0;
    protected:
        string DVDType;
};

#endif