#include "bst.h"

int main()
{
    BST testTree = { NULL, 0 };

    bstInsert(&testTree, 10);
    bstInsert(&testTree, 70);
    bstInsert(&testTree, 30);
    bstInsert(&testTree, 80);
    bstInsert(&testTree, 20);
    bstInsert(&testTree, 60);
    bstInsert(&testTree, 40);
    bstInsert(&testTree, 90);
    bstInsert(&testTree, 50);

    printf("preorder:\n");
    bstPreorder(&testTree);
    printf("postorder:\n");
    bstPostorder(&testTree);
    printf("inorder:\n");
    bstInorder(&testTree);
}
