#ifndef LISTLOGIC_H_INCLUDED
#define LISTLOGIC_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BstNode {
    struct BstNode* left;
    struct BstNode* right;
    int data;
} Node;

typedef struct BstTree {
    Node* head;
    int treeCount;
} BST;

void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
void freeNode(Node*);

// Задача F
bool bstIsValid(BST* tree);

// Задача G
int bstKthMin(BST* tree, int k);

// Задача H
typedef struct Iterator Iterator;
Iterator* iteratorInit(BST* tree);
bool iteratorHasNext(Iterator* it);
int iteratorNext(Iterator* it);
void iteratorFree(Iterator* it);

#endif