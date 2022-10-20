#ifndef ARRAYSTACKRS_H
#define ARRAYSTACKRS_H
#include "ArrayStack.h"
template<class ItemType>
class ArrayStackRS : public ArrayStack<ItemType> {
    private:
        //
    public:
        ItemType getSize();
    
};

#include "ArrayStackRS.cpp"

#endif