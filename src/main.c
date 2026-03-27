#include "ListLogic.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    BST testTree = { NULL };

    bstInsert(&testTree, 10);
    bstInsert(&testTree, 70);
    bstInsert(&testTree, 30);
    bstInsert(&testTree, 80);
    bstInsert(&testTree, 20);
    bstInsert(&testTree, 60);
    bstInsert(&testTree, 40);
    bstInsert(&testTree, 90);
    bstInsert(&testTree, 50);

    printf("\n");
    bstPreorder(&testTree);
    printf("\n");
    bstPostorder(&testTree);
}
