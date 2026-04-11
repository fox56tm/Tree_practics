#include "ListLogic.h"
#include <stdlib.h>
#include <limits.h>

typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

struct Iterator {
    StackNode* stack;
};

static void push(StackNode** top, Node* node) {
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode->treeNode = node;
    newNode->next = *top;
    *top = newNode;
}

static Node* pop(StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    
    StackNode* temp = *top;
    Node* node = temp->treeNode;
    *top = temp->next;
    free(temp);
    return node;
}

static void pushLeft(Iterator* it, Node* node) {
    while (node != NULL) {
        push(&it->stack, node);
        node = node->left;
    }
}

Iterator* iteratorInit(BST* tree) {
    if (tree == NULL) {
        return NULL;
    }
    
    Iterator* it = malloc(sizeof(Iterator));
    it->stack = NULL;
    pushLeft(it, tree->head);
    return it;
}

bool iteratorHasNext(Iterator* it) {
    return it != NULL && it->stack != NULL;
}

int iteratorNext(Iterator* it) {
    if (!iteratorHasNext(it)) {
        return INT_MIN;
    }
    
    Node* node = pop(&it->stack);
    
    if (node->right != NULL) {
        pushLeft(it, node->right);
    }
    
    return node->data;
}

void iteratorFree(Iterator* it) {
    if (it == NULL) {
        return;
    }
    
    while (it->stack != NULL) {
        pop(&it->stack);
    }
    free(it);
}