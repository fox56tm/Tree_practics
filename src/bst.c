#include "bst.h"

static int counter;

static int inorderKth(Node* node, int k)
{
    if (node == NULL) {
        return INT_MIN;
    }

    int left = inorderKth(node->left, k);
    if (counter >= k) {
        return left;
    }

    counter++;
    if (counter == k) {
        return node->data;
    }

    return inorderKth(node->right, k);
}

int bstKthMin(BST* tree, int k)
{
    if (tree == NULL || tree->root == NULL || k <= 0) {
        return INT_MIN;
    }

    counter = 0;
    int result = inorderKth(tree->root, k);

    if (counter < k) {
        return INT_MIN;
    }

    return result;
}

void bstInsert(BST* tree, int value)
{
    if (!tree)
        return;
    Node* newNode = malloc(sizeof(Node));
    if (!newNode)
        return;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (tree->root == NULL) {
        tree->root = newNode;
        tree->nodeCount++;
        return;
    }
    Node* curr = tree->root;
    Node* currPrev = tree->root;
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
    tree->nodeCount++;
}

bool bstContains(BST* tree, int value)
{
    if (!tree)
        return false;
    Node* curr = tree->root;
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

void freeNode(Node* node)
{
    if (node == NULL)
        return;
    freeNode(node->right);
    freeNode(node->left);
    free(node);
}

void bstFree(BST* tree)
{
    if (!tree)
        return;
    freeNode(tree->root);
    tree->root = NULL;
    tree->nodeCount = 0;
}
