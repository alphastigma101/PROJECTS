// Implement the linked based stack with peek and peek2 here
// Also create the StackPeek2.cpp file
#include "LinkedStack.h"
template<class ItemType>
class StackPeek2 : public LinkedStack<ItemType> {
    private:
        //
    public:
        // peek is already declared in LinkedStack.h because of inheritance 
        ItemType peek2() const;
        
    
};

#include "StackPeek2.cpp"

