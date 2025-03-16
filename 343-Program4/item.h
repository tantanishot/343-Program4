// ------------------------------------------------ item.h ------------------------------------------------------- 

// Tristan Santor, Ethan Phonsouk  CSS 343

// 3/14/25

// 3/14/25

// --------------------------------------------------------------------------------------------------------------------

// Purpose - The most generic type which is an item, allows to be easily extensible

// -------------------------------------------------------------------------------------------------------------------- 


#ifndef ITEM_H_
#define ITEM_H_

#include <iostream> 
#include <string>

using namespace std;

class Item
{
    public:
        //virtual methods that are required to be implemented from each child class
        virtual string getItemType() const = 0;
        virtual void print() const = 0;
    protected:
        string itemType;
};

#endif