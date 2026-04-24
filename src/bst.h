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
