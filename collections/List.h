#ifndef _COLLECTIONS_LIST_
#define _COLLECTIONS_LIST_

#include "Collection.h"

template <typename E>
class List : public Collection<E>
{
public:
    virtual ~List() = default;

    virtual E get(int i) = 0;
    
    // virtual void sort(int comparator(E));
};

#endif