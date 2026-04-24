#include "bst.h"

int main()
{
    BST testTree = { NULL, 0 };

    bstInsert(&testTree, 10);
    bstInsert(&testTree, 20);
    bstInsert(&testTree, 30);
    bstInsert(&testTree, 40);
    bstInsert(&testTree, 50);
    bstInsert(&testTree, 60);

    printf("contains 50 (expected 1): %d\n", bstContains(&testTree, 50));
    printf("contains 100 (expected 0): %d\n", bstContains(&testTree, 100));
}
