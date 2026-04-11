#include "ListLogic.h"
void bstInsert(BST* tree, int value)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (tree->head == NULL) {

        tree->head = newNode;
        return;
    }
    Node* curr = tree->head;

    Node* currPrev = tree->head;

    while (curr != NULL) {
        currPrev = curr;

        if (value == curr->data) {
            free(newNode);
            return;
        } else if (value > curr->data)
            curr = curr->right;

        else
            curr = curr->left;
    }
    if (value > currPrev->data)
        currPrev->right = newNode;

    else
        currPrev->left = newNode;
}
