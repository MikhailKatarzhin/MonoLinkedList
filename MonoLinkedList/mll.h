#pragma once
#include <iostream>

template <typename B> class MonoLinkedList
{
private:
    struct ListElement
        {
            B           unit;
            ListElement *nextElement;
        };
    ListElement *top;
public:
    MonoLinkedList();
    MonoLinkedList( B const b );
    MonoLinkedList( MonoLinkedList const &monoLinkedList );
    ~MonoLinkedList();

    void insertLast( B const b );
    void insertFirst( B const b );
    const bool insertAtPos( B const b, int const pos );

    void deleteAtPtr( ListElement ptrElement );
    void deleteLast();
    void deleteFirst();
    const bool deleteAtPos( int const pos );
    void clear();
    const ListElement& getLast() const;
    const ListElement& getFirst() const;
    const bool isContains( B const b ) const;
    const bool isEmpty() const;
    const unsigned int size() const;

    void print() const;
    ListElement& operator = ( ListElement const listElement );
};

