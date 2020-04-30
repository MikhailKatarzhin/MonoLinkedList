#pragma once


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
    MonoLinkedList( MonoLinkedList const &monoLinkedList );

    void insertLast( B const &b );
    void insertFirst( B const &b );
    const bool insertAtPos( B const &b, int const pos );

    void deleteAtPtr( ListElement &ptrElement );
    void deleteLast();
    void deleteFirst();
    const bool deleteAtPos( int const pos );
};
