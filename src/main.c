#include "bst.h"

int main()
{
    BST testTree = { NULL, 0 };
    printf("epmptyTree: ");
    bstDelete(&testTree, 35);
    bstInsert(&testTree, 20);
    bstInsert(&testTree, 40);
    bstInsert(&testTree, 32);
    bstInsert(&testTree, 78);
    bstInsert(&testTree, 12);
    bstInsert(&testTree, 5);

    printf("contains before remove (expected 1): %d\n", bstContains(&testTree, 78));
    bstDelete(&testTree, 78);
    printf("contains before remove (expected 0): %d\n", bstContains(&testTree, 78));
}
