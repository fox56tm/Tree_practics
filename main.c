#include "ListLogic.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    BST testTree = { NULL };

    bstInsert(&testTree, 10);
    bstInsert(&testTree, 100);
    bstInsert(&testTree, 30);
    bstInsert(&testTree, 5);
    bstInsert(&testTree, 50);
    bstInsert(&testTree, 60);

    printf("%d\n", bstHeight(&testTree));

    printf("%d\n", bstSize(&testTree));

    printf("%d\n", bstMin(&testTree));

    printf("%d\n", bstMax(&testTree));
}
