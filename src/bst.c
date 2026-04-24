#include "bst.h"
void bstInsert(BST* tree, int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (tree->head == NULL) {
        tree->head = newNode;
        tree->treeCount++;
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

    tree->treeCount++;
}
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
    freeNode(tree->head);
    tree->head = NULL;
}