#include "bst.h"

int nodeHeight(Node* node)
{
    if (node == NULL)
        return -1;
    int leftH = nodeHeight(node->left);
    int rightH = nodeHeight(node->right);

    return 1 + (leftH > rightH ? leftH : rightH);
}
int bstHeight(BST* tree)
{
    if (!tree)
        return -1;
    return nodeHeight(tree->root);
}

int nodeCounter(Node* node)
{
    if (node == NULL)
        return 0;

    return 1 + nodeCounter(node->right) + nodeCounter(node->left);
}

int bstSize(BST* tree)
{
    if (!tree) {
        printf("please create bst, returned value -1!\n");
        return -1;
    }
    return nodeCounter(tree->root);
}

int maxData(Node* node)
{
    if (node->right != NULL)
        return maxData(node->right);
    else
        return node->data;
}
int bstMax(BST* tree)
{
    if (!tree) {
        printf("please create bst, returned value -1!\n");
        return -1;
    }
    if (tree->nodeCount == 0) {
        printf("bst is empty, returned value -1!\n");
        return -1;
    }
    return maxData(tree->root);
}

int minData(Node* node)
{
    if (node->left != NULL)
        return minData(node->left);
    else
        return node->data;
}
int bstMin(BST* tree)
{
    if (!tree) {
        printf("please create bst, returned value -1!\n");
        return -1;
    }
    if (tree->nodeCount == 0) {
        printf("bst is empty, returned value -1!\n");
        return -1;
    }
    return minData(tree->root);
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