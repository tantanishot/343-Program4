#ifndef DVD_H_
#define DVD_H_

#include "item.h"

class DVD : public Item
{
    public:
        virtual string getDVDType() const = 0;
    protected:
        string DVDType;
};

#endif