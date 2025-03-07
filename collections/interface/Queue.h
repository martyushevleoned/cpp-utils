#ifndef _COLLECTIONS_QUEUE_H
#define _COLLECTIONS_QUEUE_H

#include "Collection.h"

template <typename E>
class Queue : public Collection<E>
{
public:
    virtual ~Queue() = default;

    // virtual bool add(E) = 0;
};

#endif