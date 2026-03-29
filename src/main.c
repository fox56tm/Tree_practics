#include "ListLogic.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    BST testTree = { NULL };

    bstInsert(&testTree, 3);
    bstInsert(&testTree, 1);
    bstInsert(&testTree, 35);
    bstInsert(&testTree, 43);
    bstInsert(&testTree, 17);
    bstInorder(&testTree);
    printf("\n");
    printf("%d\n", bstHeight(&testTree));

    printf("%d\n", bstSize(&testTree));

    printf("%d\n", bstMin(&testTree));

    printf("%d\n", bstMax(&testTree));
}
