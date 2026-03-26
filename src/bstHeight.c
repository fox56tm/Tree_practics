#include "ListLogic.h"


int nodeHeight(Node* node)
{
    if (node == NULL) return -1;

    int leftH = nodeHeight(node -> left);

    int rightH = nodeHeight(node -> right);

    return 1 + (leftH > rightH ? leftH : rightH);
}
int bstHeight(BST* tree)
{
    nodeHeight(tree -> head);
    
}