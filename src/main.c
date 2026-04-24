#include "bst.h"

int main()
{
    BST testTree = { NULL, 0 };

    printf("min on empty bst (expected: bst is empty, returned value -1!): %d\n", bstMin(&testTree));
    printf("max on empty bst (expected: bst is empty, returned value -1!): %d\n", bstMax(&testTree));

    bstInsert(&testTree, 3);
    bstInsert(&testTree, 1);
    bstInsert(&testTree, 35);
    bstInsert(&testTree, 42);
    bstInsert(&testTree, 17);

    printf("\n");
    printf("testHeight (expected 2): %d\n", bstHeight(&testTree));
    printf("testSize (expected 5): %d\n", bstSize(&testTree));
    printf("testMin (expected 1): %d\n", bstMin(&testTree));
    printf("testMax (expected 42): %d\n", bstMax(&testTree));
}
