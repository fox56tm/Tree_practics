#include "bst.h"

typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

struct Iterator {
    StackNode* stack;
};

static int counter;

static void push(StackNode** top, Node* node)
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return;
    }
    newNode->treeNode = node;
    newNode->next = *top;
    *top = newNode;
}

static Node* pop(StackNode** top)
{
    if (*top == NULL) {
        return NULL;
    }
    StackNode* temp = *top;
    Node* node = temp->treeNode;
    *top = temp->next;
    free(temp);
    return node;
}

static void pushLeft(Iterator* it, Node* node)
{
    while (node != NULL) {
        push(&it->stack, node);
        node = node->left;
    }
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

Iterator* iteratorInit(BST* tree)
{
    if (tree == NULL || tree->root == NULL)
        return NULL;

    Iterator* it = (Iterator*)malloc(sizeof(Iterator));
    if (it == NULL)
        return NULL;

    it->stack = NULL;
    pushLeft(it, tree->root);
    return it;
}

bool iteratorHasNext(Iterator* it)
{
    return it != NULL && it->stack != NULL;
}

int iteratorNext(Iterator* it)
{
    if (!iteratorHasNext(it))
        return INT_MIN;

    Node* node = pop(&it->stack);
    if (node->right != NULL)
        pushLeft(it, node->right);

    return node->data;
}

void iteratorFree(Iterator* it)
{
    if (it == NULL)
        return;
    while (it->stack != NULL)
        pop(&it->stack);
    free(it);
}

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

static int counter;

static int inorderKth(Node* node, int k)
{
    if (node == NULL)
        return INT_MIN;

    int left = inorderKth(node->left, k);
    if (counter >= k)
        return left;

    counter++;
    if (counter == k)
        return node->data;

    return inorderKth(node->right, k);
}

int bstKthMin(BST* tree, int k)
{
    if (tree == NULL || tree->root == NULL || k <= 0)
        return INT_MIN;

    counter = 0;
    int result = inorderKth(tree->root, k);

    if (counter < k)
        return INT_MIN;

    return result;
}
