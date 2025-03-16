#ifndef ITEM_H_
#define ITEM_H_

#include <iostream> 
#include <string>
#include <iomanip>

using namespace std;
using std::left;

class Item
{
    public:
        virtual string getItemType() const = 0;
        virtual void print() const = 0;
    protected:
        string itemType;
};

#endif