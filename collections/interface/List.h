#ifndef _COLLECTIONS_LIST_H
#define _COLLECTIONS_LIST_H

#include "Collection.h"

template <typename E>
class List : public Collection<E>
{
public:
    virtual ~List() = default;

    virtual E get(int) = 0;

    virtual bool remove(int) = 0;

    virtual bool insert(int, E) = 0;

    virtual bool add(E) = 0;

    bool addAll(Collection<E> *collection)
    {
        Iterator<E> *it = collection->iterator();
        while (it->hasNext())
            add(it->next());
        delete it;
        return true;
    };
};

#endif