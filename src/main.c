#include "bst.h"

int main()
{
    BST testTree = { NULL, 0 };
    BST tree = { NULL, 0 };

    bstInsert(&testTree, 10);
    bstInsert(&testTree, 20);
    bstInsert(&testTree, 30);
    bstInsert(&testTree, 40);
    bstInsert(&testTree, 50);
    bstInsert(&testTree, 60);

    bstInsert(&tree, 10);
    bstInsert(&tree, 5);
    bstInsert(&tree, 15);
    bstInsert(&tree, 3);
    bstInsert(&tree, 7);
    bstInsert(&tree, 12);
    bstInsert(&tree, 20);

    printf("%d\n", bstContains(&testTree, 100));

    Iterator* it = iteratorInit(&tree);
    printf("Inorder: ");
    while (iteratorHasNext(it)) {
        printf("%d ", iteratorNext(it));
    }
    printf("\n");
    iteratorFree(it);

    bstFree(&tree);
    bstFree(&testTree);

    return 0;
}
