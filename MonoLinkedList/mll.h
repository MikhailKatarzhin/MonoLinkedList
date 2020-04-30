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
    bool insertAtPos( B const &b, int const pos );
};
