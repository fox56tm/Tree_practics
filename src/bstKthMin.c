#include "ListLogic.h"
#include <limits.h>

static int counter;

static int inorderKth(Node* node, int k) {
    if (node == NULL) return INT_MIN;
    int left = inorderKth(node->left, k);
    if (counter >= k) return left;
    counter++;
    if (counter == k) return node->data;
    return inorderKth(node->right, k);
}

int bstKthMin(BST* tree, int k) {
    if (tree == NULL || k <= 0) return INT_MIN;
    counter = 0;
    int result = inorderKth(tree->head, k);
    if (counter < k) return INT_MIN;
    return result;
}
