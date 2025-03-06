#ifndef _COLLECTIONS_COLLECTION_
#define _COLLECTIONS_COLLECTION_

#include "Iterator.h"

template <typename E>
class Collection : public Iterable<E>
{
public:
    virtual ~Collection() = default;

    virtual int size() = 0;
    
    virtual bool add(E) = 0;

    // virtual bool contains(E);
};

#endif