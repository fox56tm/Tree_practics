#include "ListLogic.h"

void nodeChangerPre(Node* node)
{
    if (node == NULL)
        return;

    printf("%d\n", node->data);

    nodeChangerPre(node->left);

    nodeChangerPre(node->right);
}

void bstPreorder(BST* tree)
{
    nodeChangerPre(tree->head);
}