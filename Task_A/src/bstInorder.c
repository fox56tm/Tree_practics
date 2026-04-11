#include "ListLogic.h"

void nodeChangerIn(Node* node)
{
    if (node == NULL)
        return;

    nodeChangerIn(node->left);

    printf("%d\n", node->data);

    nodeChangerIn(node->right);
}

void bstInorder(BST* tree)
{
    nodeChangerIn(tree->head);
}