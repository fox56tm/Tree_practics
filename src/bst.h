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
int bstHeight(BST* tree);
int nodeHeight(Node* node);
int nodeCounter(Node* node);
int bstSize(BST* tree);
int bstMin(BST* tree); // на пустом дереве вернет 0
int bstMax(BST* tree); // на пустом дереве вернет 0
int minData(Node* node); // для bstMin
int maxData(Node* node); // для bstMax
