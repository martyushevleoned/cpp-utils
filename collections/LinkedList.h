#ifndef _COLLECTIONS_LINKEDLIST_
#define _COLLECTIONS_LINKEDLIST_

#include "List.h"

template <typename E>
class LinkedList : public List<E>
{
private:
    struct Node
    {
        E data;
        Node *next;
        Node *prev;
        Node(E value) : data(value), next(nullptr), prev(nullptr) {}
    };

public:
    class ListIterator : public Iterator<E>
    {
    public:
        Node *_current;
        ListIterator(Node *begin) : _current(begin) {};

        bool hasNext() override { return _current != nullptr; };

        E next() override
        {
            E &data = _current->data;
            _current = _current->next;
            return data;
        };
    };

private:
    int _size = 0;
    Node *_begin = nullptr;
    Node *_end = nullptr;

public:
    E get(int index) override
    {
        if (index < 0 || index > _size)
            throw std::invalid_argument("received negative value");

        Node *current = _begin;
        for (int i = 0; i < index; i++)
            current = current->next;

        return current->data;
    };

    int size() override { return _size; };

    bool add(E value) override
    {
        Node *newNode = new Node(value);

        if (_size == 0)
        {
            _begin = newNode;
            _end = newNode;
            _size++;
            return true;
        }

        newNode->prev = _end;
        _end->next = newNode;
        _end = newNode;
        _size++;
        return true;
    };

    Iterator<E>* iterator() override { return new ListIterator(_begin); };
};

#endif