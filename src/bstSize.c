#include "ListLogic.h"

int nodeCounter(Node* node)
{
    if (node == NULL)
        return 0;

    return 1 + nodeCounter(node->right) + nodeCounter(node->left);
}

int bstSize(BST* tree)
{
    return nodeCounter(tree->head);
}