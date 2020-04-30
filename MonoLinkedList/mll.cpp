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
bool MonoLinkedList<B>::insertAtPos( B const &b, int const pos )
{
    if( 1 > pos )
        return false;
    if( ( nullptr == top )&&( pos > 1) )
    {
        return false;
    }
    ListElement *tmpElement = top;
    for( int i = pos ; i > 1 ; --i )
    {
        if( nullptr == tmpElement->nextElement )
            return false;
        tmpElement = tmpElement->nextElement;
    }
    ListElement *tmpElement2    = new ListElement();
    tmpElement2->unit           = b;
    tmpElement2->nextElement    = tmpElement->nextElement;
    tmpElement->nextElement     = tmpElement2;
    return true;
}
