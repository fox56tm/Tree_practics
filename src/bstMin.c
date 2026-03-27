#include "ListLogic.h"

int minData(Node* node)
{
    if (node == NULL)
        return 0;

    if (node->left != NULL)
        return minData(node->left);

    else
        return node->data;
}

int bstMin(BST* tree)
{
    return minData(tree->head);
}
