#include "ListLogic.h"
#include <limits.h>

static bool isValidHelper(Node* node, int min, int max) {
    if (node == NULL) {
        return true;
    }
    
    if (node->data <= min || node->data >= max) {
        return false;
    }
    
    return isValidHelper(node->left, min, node->data) &&
           isValidHelper(node->right, node->data, max);
}

bool bstIsValid(BST* tree) {
    if (tree == NULL || tree->head == NULL) {
        return true;
    }
    
    return isValidHelper(tree->head, INT_MIN, INT_MAX);
}