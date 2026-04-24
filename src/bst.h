#pragma once
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode {
    struct BstNode* left;
    struct BstNode* right;
    int data;
} Node;

typedef struct BstTree {
    Node* root;
    int nodeCount;
} BST;

void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
bool bstIsValid(BST* tree);
int bstKthMin(BST* tree, int k);
typedef struct Iterator Iterator;
Iterator* iteratorInit(BST* tree);
bool iteratorHasNext(Iterator* it);
int iteratorNext(Iterator* it);
void iteratorFree(Iterator* it);
