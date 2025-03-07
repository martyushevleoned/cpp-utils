#ifndef _COLLECTIONS_ITERATOR_H
#define _COLLECTIONS_ITERATOR_H

#include <stdexcept>

template <typename E>
class Iterator
{
public:
    virtual ~Iterator() = default;

    virtual bool hasNext() = 0;

    virtual E next() = 0;
};

template <typename E>
class Iterable
{
public:
    virtual ~Iterable() = default;

    virtual Iterator<E> *iterator() = 0;

    virtual void forEach(void f(E))
    {
        Iterator<E> *it = iterator();
        while (it->hasNext())
            f(it->next());
        delete it;
    }
};

#endif