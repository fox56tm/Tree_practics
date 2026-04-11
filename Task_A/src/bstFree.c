#include "ListLogic.h"

void freeNode(Node* node)
{
    if (node == NULL)
        return;

    freeNode(node->right);

    freeNode(node->left);

    free(node);
}
void bstFree(BST* tree)
{
    freeNode(tree->head);

    tree->head = NULL;
}