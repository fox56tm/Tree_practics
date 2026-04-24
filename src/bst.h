#pragma once
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
void freeNode(Node*);
int minData(Node* node);
int bstMin(BST* tree);
void bstDelete(BST* tree, int value);
void nodeDeliter(Node** node, int value); // для bstDelete
