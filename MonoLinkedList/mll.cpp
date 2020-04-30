#include "mll.h"

template <typename B>
MonoLinkedList<B>::MonoLinkedList()
{
    top = nullptr;
}
template <typename B>
MonoLinkedList<B>::MonoLinkedList( MonoLinkedList const &monoLinkedList )
{
    if( nullptr == monoLinkedList->top )
    {
        top = nullptr;
        return;
    }
    ListElement *tmpElement     = monoLinkedList->top;
    ListElement *tmpElement2    = new ListElement();
    top                         = tmpElement2;
    while( nullptr != tmpElement->nextElement )
    {
        tmpElement2->unit           = tmpElement->unit;
        ListElement *tmpElement3    = new ListElement();
        tmpElement2->nextElement    = tmpElement3;
        tmpElement2 = tmpElement2->nextElement;
        tmpElement  = tmpElement->nextElement;
    }
    tmpElement2->unit           = tmpElement->unit;
    tmpElement2->nextElement    = nullptr;
}

template <typename B>
MonoLinkedList<B>::~MonoLinkedList()
{
    while( nullptr != top )
    {
        ListElement *tmpElement = top;
        top                     = top->nextElement;
        delete tmpElement;
        tmpElement              = nullptr;
    }
}

template <typename B>
void MonoLinkedList<B>::insertLast( B const &b )
{
    if( nullptr == top )
    {
        ListElement *tmpElement = new ListElement();
        tmpElement->unit        = b;
        top                     = tmpElement;
        return;
    }
    ListElement *tmpElement = top;
    while( tmpElement->nextElement != nullptr )
        tmpElement = tmpElement->nextElement;
    ListElement *tmpElement2    = new ListElement();
    tmpElement2->unit           = b;
    tmpElement->nextElement     = tmpElement2;
}

template <typename B>
void MonoLinkedList<B>::insertFirst( B const &b )
{
    ListElement *tmpElement = new ListElement();
    tmpElement->unit        = b.unit;
    if( nullptr == top )
    {
        top = tmpElement;
        return;
    }
    ListElement *tmpElement2    = top;
    top                         = tmpElement;
    tmpElement->nextElement     = tmpElement2;
}

template <typename B>
const bool MonoLinkedList<B>::insertAtPos( B const &b, int const pos )
{
    if( 1 > pos )
        return false;
    if( ( nullptr == top )&&( pos > 1) )
    {
        return false;
    }
    if( ( 1 == pos ) )
    {
        insertFirst( b );
        return;
    }
    ListElement *tmpElement = top;
    for( int i = pos ; i > 2 ; --i )
    {
        if( nullptr == tmpElement->nextElement )
            return false;
        tmpElement = tmpElement->nextElement;
    }
    ListElement *tmpElement2    = new ListElement();
    tmpElement2->unit           = b;
    if( nullptr == tmpElement->nextElement )
    {
        tmpElement->nextElement = tmpElement2;
        return;
    }
    tmpElement2->nextElement    = tmpElement->nextElement;
    tmpElement->nextElement     = tmpElement2;
    return true;
}

template <typename B>
void MonoLinkedList<B>::deleteAtPtr( ListElement &ptrElement )
{
    if( nullptr == ptrElement )
        return;
    if( nullptr == ptrElement->nextElement )
        ptrElement = nullptr;
        return;

    ptrElement->unit = ptrElement->nextElement->unit;
    ListElement *tmpElement = ptrElement->nextElement->nextElement;
    delete ptrElement->nextElement;
    ptrElement->nextElement = tmpElement;
}

template <typename B>
void MonoLinkedList<B>::deleteLast()
{
    if( nullptr == top )
    {
        return;
    }
    ListElement *tmpElement = top;
    while( tmpElement->nextElement->nextElement != nullptr )
        tmpElement = tmpElement->nextElement;
    delete tmpElement->nextElement;
    tmpElement->nextElement = nullptr;
}

template <typename B>
void MonoLinkedList<B>::deleteFirst()
{
    if( nullptr == top )
    {
        return;
    }
    if( nullptr == top->nextElement )
    {
        delete top;
        top = nullptr;
        return;
    }
    ListElement *tmpElement = top;
    top = top->nextElement;
    delete tmpElement;
    tmpElement = nullptr;
}

template <typename B>
const bool MonoLinkedList<B>::deleteAtPos( int const pos )
{
    if( 1 > pos )
        return false;
    if( nullptr == top )
    {
        return false;
    }
    if( ( 1 == pos ) )
    {
        deleteFirst();
        return;
    }
    ListElement *tmpElement = top;
    for( int i = pos ; i > 2 ; --i )
    {
        if( nullptr == tmpElement->nextElement )
            return false;
        tmpElement = tmpElement->nextElement;
    }
    if( nullptr == tmpElement->nextElement )
    {
        delete tmpElement;
        tmpElement = nullptr;
        return;
    }
    ListElement *tmpElement2    = tmpElement->nextElement;
    delete tmpElement;
    tmpElement->nextElement     = tmpElement2;
    return true;
}

template <typename B>
void MonoLinkedList<B>::clear()
{
    while( nullptr != top )
    {
        ListElement *tmpElement = top;
        top                     = top->nextElement;
        delete tmpElement;
        tmpElement              = nullptr;
    }
}

template <typename B>
const typename MonoLinkedList<B>::ListElement& MonoLinkedList<B>::getLast() const
{
        ListElement *tmpElement = top;
        while( nullptr != tmpElement->nextElement )
            tmpElement = tmpElement->nextElement;
}

template <typename B>
const typename MonoLinkedList<B>::ListElement& MonoLinkedList<B>::getFirst() const
{
        return top;
}

template <typename B>
const bool MonoLinkedList<B>::isContains( B const &b ) const
{
    if( nullptr == top )
        return false;
    ListElement *tmpElement = top;
    while( nullptr != tmpElement->nextElement )
    {
        if( tmpElement->unit == b )
            return true;
        tmpElement = tmpElement->nextElement;
    }
    return ( tmpElement->unit == b );
}

template <typename B>
const bool MonoLinkedList<B>::isEmpty() const
{
    return ( nullptr == top );
}

template <typename B>
const unsigned int MonoLinkedList<B>::size() const
{
    unsigned int c = 0;
    ListElement *tmpElement = top;
    while( nullptr != tmpElement )
    {
        ++c;
        tmpElement = tmpElement->nextElement;
    }
    return c;
}
