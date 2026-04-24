#include "bst.h"

int main()
{
    BST testTree1 = { NULL, 0 };
    bstInsert(&testTree1, 10);
    bstInsert(&testTree1, 20);
    bstInsert(&testTree1, 30);
    bstInsert(&testTree1, 40);
    bstInsert(&testTree1, 50);
    bstInsert(&testTree1, 60);

    BST testTree2 = { NULL, 0 };
    printf("\n");
    bstInsert(&testTree2, 10);
    bstInsert(&testTree2, 57);
    bstInsert(&testTree2, 28);
    bstInsert(&testTree2, 19);
    printf("\n");

    BST* testMergeTree = bstMerge(&testTree1, &testTree2);
    bstInorder(testMergeTree);
}
