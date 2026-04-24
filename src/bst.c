#include "bst.h"

static bool isValidHelper(Node* node, int min, int max)
{
    if (node == NULL)
        return true;
    if (node->data <= min || node->data >= max)
        return false;
    return isValidHelper(node->left, min, node->data) && isValidHelper(node->right, node->data, max);
}

bool bstIsValid(BST* tree)
{
    if (tree == NULL || tree->root == NULL)
        return true;
    return isValidHelper(tree->root, INT_MIN, INT_MAX);
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

static void freeNode(Node* node)
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
