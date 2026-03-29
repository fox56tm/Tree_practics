#include "ListLogic.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    BST testTree1 = { NULL };

    bstInsert(&testTree1, 10);
    bstInsert(&testTree1, 20);
    bstInsert(&testTree1, 30);
    bstInsert(&testTree1, 40);
    bstInsert(&testTree1, 50);
    bstInsert(&testTree1, 60);

    bstInorder(&testTree1);

    BST testTree2 = { NULL };

    printf("\n");

    bstInsert(&testTree2, 10);
    bstInsert(&testTree2, 57);
    bstInsert(&testTree2, 28);
    bstInsert(&testTree2, 19);

    bstInorder(&testTree2);

    printf("\n");

    BST* testMergeTree = bstMerge(&testTree1, &testTree2);

    bstInorder(testMergeTree);
}
