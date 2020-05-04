#include <iostream>
#include "mll.h"

int main()
{
    MonoLinkedList<int> list1;
    list1.insertFirst( 5 );
    list1.insertFirst( 10 );
    list1.insertFirst( 3 );
    list1.insertFirst( 1231 );
    list1.insertFirst( 5 );
    list1.print();

    std::cout << "\nis Empty: " << list1.isEmpty();
    std::cout << "\nContains 4: " << list1.isContains( 4 );
    std::cout << "\nCount elements: " << list1.size();
    std::cout << "\nLast: " << list1.getLast();
    list1.deleteFirst();
    std::cout << std::endl << std::endl << std::endl;
    list1.print();
    if( list1.deleteAtPos( 4 ) )
    std::cout << std::endl << std::endl << std::endl;
    list1.print();
    return 0;
}
