#include "bst.h"
void bstInsert(BST* tree, int value)
{
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