#include "ListLogic.h"

void nodeChangerPost(Node* node)
{
    if (node == NULL)
        return;

    nodeChangerPost(node->left);

    nodeChangerPost(node->right);

    printf("%d\n", node->data);
}

void bstPostorder(BST* tree)
{
    nodeChangerPost(tree->head);
}