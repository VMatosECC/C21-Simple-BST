// C21-Simple-BST.cpp 

#include <iostream>
#include "BST.h"

int main()
{
    BST<int> t;
    t.add(15);
    t.add(7);
    t.add(10);
    t.add(2);
    t.add(20);
    t.add(41);
    t.add(35);
    t.add(42);
    t.add(8);
    t.preOrder();
}

