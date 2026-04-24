#include "bst.h"

void nodeChangerIn(Node* node)
{
    if (node == NULL)
        return;
    nodeChangerIn(node->left);
    printf("%d\n", node->data);
    nodeChangerIn(node->right);
}

void bstInorder(BST* tree)
{
    if (!tree)
        return;
    nodeChangerIn(tree->root);
}

void nodeChangerPost(Node* node)
{
    if (node == NULL)
        return;
    nodeChangerPost(node->left);
    nodeChangerPost(node->right);
    printf("%d\n", node->data);
}

void bstPostorder(BST* tree)
{
    if (!tree)
        return;
    nodeChangerPost(tree->root);
}
void nodeChangerPre(Node* node)
{
    if (node == NULL)
        return;
    printf("%d\n", node->data);
    nodeChangerPre(node->left);
    nodeChangerPre(node->right);
}

void bstPreorder(BST* tree)
{
    if (!tree)
        return;
    nodeChangerPre(tree->root);
}
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