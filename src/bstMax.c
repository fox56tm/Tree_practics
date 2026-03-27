#include "ListLogic.h"

int maxData(Node* node)
{
    if (node == NULL)
        return 0;

    if (node->right != NULL)
        return maxData(node->right);

    else
        return node->data;
}

int bstMax(BST* tree)
{
    return maxData(tree->head);
}
