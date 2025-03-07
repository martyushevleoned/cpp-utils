#ifndef _COLLECTIONS_LINKEDLIST_H
#define _COLLECTIONS_LINKEDLIST_H

#include "interface/List.h"
#include "interface/Deque.h"

template <typename E>
class LinkedList : public List<E>, public Deque<E>
{
private:
    // custom node
    struct Node
    {
        E data;
        Node *next;
        Node *prev;
        Node(E value) : data(value), next(nullptr), prev(nullptr) {}
    };

private:
    // custom iterator
    class ListIterator : public Iterator<E>
    {
    private:
        Node *_current;

    public:
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
    // fields
    int _size;
    Node *_begin;
    Node *_end;

    // funcs
    Node *getNode(const int index)
    {
        if (index < 0 || index > _size - 1)
            throw std::invalid_argument("index out of bounds");

        if (index < _size / 2)
        {
            Node *current = _begin;
            for (int i = 0; i < index; i++)
                current = current->next;
            return current;
        }

        Node *current = _end;
        for (int i = _size - 1; i > index; i--)
            current = current->prev;
        return current;
    }

public:
    LinkedList() : _size(0), _begin(nullptr), _end(nullptr) {}

    ~LinkedList()
    {
        Node *current = _begin;
        while (current != nullptr)
        {
            Node *tmp = current;
            current = current->next;
            delete tmp;
        }
    }

    // Collection
    int size() override { return _size; };

    bool contains(const E element) override
    {
        // возможно можно переписать на for each и лямбда функции
        Node *curent = _begin;
        while (curent != nullptr)
        {
            if (curent->data == element)
                return true;
            curent = curent->next;
        }

        return false;
    };

    // List
    bool insert(const int index, const E value) override
    {
        if (index < 0 || index > _size)
            throw std::invalid_argument("index out of bounds");

        Node *newNode = new Node(value);

        if (_size == 0) // единственный
        {
            _begin = newNode;
            _end = newNode;
        }
        else if (index == 0) // первый
        {
            newNode->next = _begin;
            _begin->prev = newNode;
            _begin = newNode;
        }
        else if (index == _size) // последний
        {
            newNode->prev = _end;
            _end->next = newNode;
            _end = newNode;
        }
        else // в середине
        {
            Node *prevNode = getNode(index - 1);
            Node *nextNode = prevNode->next;

            prevNode->next = newNode;
            newNode->prev = prevNode;

            nextNode->prev = newNode;
            newNode->next = nextNode;
        }

        _size++;
        return true;
    };

    bool remove(const int index) override
    {
        Node *node = getNode(index);

        if (_size == 1) // единственный
        {
            _begin = nullptr;
            _end = nullptr;
        }
        else if (index == 0) // первый
        {
            _begin = _begin->next;
            _begin->prev = nullptr;
        }
        else if (index == _size - 1) // последний
        {
            _end = _end->prev;
            _end->next = nullptr;
        }
        else // в середине
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        _size--;
        delete node;
        return true;
    };

    E get(const int index) override { return getNode(index)->data; };

    bool add(const E value) override { return insert(_size, value); };

    // Deque
    bool addFirst(const E value) override { return insert(0, value); };

    bool addLast(const E value) override { return insert(_size, value); };

    bool removeFirst() override { return remove(0); };

    bool removeLast() override { return remove(_size - 1); };

    E getFirst() override { return getNode(0)->data; };

    E getLast() override { return getNode(_size - 1)->data; };

    // Iterator
    Iterator<E> *iterator() override { return new ListIterator(_begin); };

    void forEach(void f(E)) override
    {
        Node *current = _begin;
        while (current != nullptr)
        {
            f(current->data);
            current = current->next;
        }
    }
};

#endif