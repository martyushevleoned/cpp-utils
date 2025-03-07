#ifndef _COLLECTIONS_DEQUE_H
#define _COLLECTIONS_DEQUE_H

#include "Queue.h"

template <typename E>
class Deque : public Queue<E>
{
public:
    virtual ~Deque() = default;

    virtual bool addFirst(E) = 0;

    virtual bool addLast(E) = 0;

    virtual bool removeFirst() = 0;

    virtual bool removeLast() = 0;

    virtual E getFirst() = 0;

    virtual E getLast() = 0;
};

#endif