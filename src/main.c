#include "bst.h"

int main()
{
    BST tree1 = { NULL, 0 };
    BST tree2 = { NULL, 0 };

    bstInsert(&tree1, 10);
    bstInsert(&tree1, 5);
    bstInsert(&tree1, 15);
    bstInsert(&tree1, 3);
    bstInsert(&tree1, 7);
    bstInsert(&tree1, 12);
    bstInsert(&tree1, 20);

    Node* wrongNode = malloc(sizeof(Node));
    wrongNode->data = 10;
    wrongNode->left = NULL;
    wrongNode->right = NULL;
    tree2.root = wrongNode;
    tree2.nodeCount = 1;

    Node* leftChild = malloc(sizeof(Node));
    leftChild->data = 20;
    leftChild->left = NULL;
    leftChild->right = NULL;
    wrongNode->left = leftChild;
    tree2.nodeCount++;

    printf("Tree1 is valid BST: %d\n", bstIsValid(&tree1));
    printf("Tree2 is valid BST: %d\n", bstIsValid(&tree2));

    bstFree(&tree1);
    bstFree(&tree2);
    free(leftChild);
    free(wrongNode);

    return 0;
}
