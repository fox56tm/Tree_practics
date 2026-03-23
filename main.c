#include <stdio.h>
#include <stdlib.h>
#include "ListLogic.h"


int main()
{
    BST testTree = {NULL, 0};

    bstInsert(&testTree, 10);
    bstInsert(&testTree, 20);
    bstInsert(&testTree, 30);
    bstInsert(&testTree, 40);
    bstInsert(&testTree, 50);
    bstInsert(&testTree, 60);

    

    printf("%d\n" , bstContains(&testTree, 100));


}
