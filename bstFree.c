#include "ListLogic.h"



void freeNode(Node* Node)
{
    if(Node == NULL) return;

    freeNode(Node -> right);

    freeNode(Node -> left);

    free(Node);

}
void bstFree(BST* tree)
{
    freeNode(tree -> head);

    tree -> head = NULL;

    tree ->treeCount = 0;


}