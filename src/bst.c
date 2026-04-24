#include "bst.h"

void nodeDeliter(Node** node, int value)
{
    Node* curr = *node;
    Node* currPrev = NULL;
    while (curr != NULL) {
        if (curr->data == value) {
            if ((curr->left != NULL) && (curr->right != NULL)) { // два ребёнка
                curr->data = minData(curr->right);
                nodeDeliter(&curr->right, minData(curr->right));
                return;
            } else if (curr->left == NULL && curr->right != NULL) {
                if (currPrev == NULL)
                    *node = curr->right; // меняем root если корень
                else if (currPrev->data > curr->data)
                    currPrev->left = curr->right;
                else
                    currPrev->right = curr->right;
                free(curr);
                return;
            } else if (curr->left != NULL && curr->right == NULL) {
                if (currPrev == NULL)
                    *node = curr->left; // меняем root если корень
                else if (currPrev->data > curr->data)
                    currPrev->left = curr->left;
                else
                    currPrev->right = curr->left;
                free(curr);
                return;
            } else {
                if (currPrev == NULL) // нет детей
                    *node = NULL; // обнуляем корень
                else if (currPrev->data > curr->data)
                    currPrev->left = NULL;
                else
                    currPrev->right = NULL;
                free(curr);
                return;
            }
        }
        if (curr->data > value) {
            currPrev = curr;
            curr = curr->left;
        } else {
            currPrev = curr;
            curr = curr->right;
        }
    }
    printf("there is no such value\n");
}

void bstDelete(BST* tree, int value)
{
    if (!tree) {
        printf("please create bst\n");
        return;
    }
    if (!bstContains(tree, value)) {
        printf("there is no such value\n");
        return;
    }
    nodeDeliter(&(tree->root), value);
    tree->nodeCount--;
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