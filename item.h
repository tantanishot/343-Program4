#ifndef ITEM_H_
#define ITEM_H_

#include <iostream> 
#include <string>

using namespace std;

class Item
{
    public:
        virtual string getItemType() const = 0;
    protected:
        string itemType;
};

#endif