#ifndef _COLLECTIONS_COLLECTION_H
#define _COLLECTIONS_COLLECTION_H

#include "Iterator.h"

template <typename E>
class Collection : public Iterable<E>
{
public:
    virtual ~Collection() = default;

    virtual int size() = 0;

    virtual bool isEmpty() { return size() == 0; };

    virtual bool contains(E) = 0;

    // virtual E[] toArray() = 0;
};

#endif