#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void nodeChangerIn(Node* node);
void bstInorder(BST* tree);
int nodeCounter(Node* node);
int bstSize(BST* tree);
Node* createNode(int* array, int l, int r);
void nodeChangerInAdd(Node* node, int* arrayForTree, int* index);
BST* bstMerge(BST* tree1, BST* tree2);
