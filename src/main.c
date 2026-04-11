#include "ListLogic.h"

int main()
{
    BST testTree = { NULL };

    bstInsert(&testTree, 20);
    bstInsert(&testTree, 40);
    bstInsert(&testTree, 32);
    bstInsert(&testTree, 78);
    bstInsert(&testTree, 12);
    bstInsert(&testTree, 5);

    printf("%d\n", bstContains(&testTree, 78));

    bstDelete(&testTree, 78);

    printf("%d\n", bstContains(&testTree, 78));
}
