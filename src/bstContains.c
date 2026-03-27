#include "ListLogic.h"
#include <stdio.h>

bool bstContains(BST* tree, int value)
{
    Node* curr = tree->head;

    while (curr != NULL) {
        if (curr->data == value) {
            return true;
        }

        if (curr->data > value) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return false;
}