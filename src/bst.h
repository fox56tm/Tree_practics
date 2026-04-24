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
void nodeChangerIn(Node* node); // для bstInorder
void bstInorder(BST* tree);
void bstPreorder(BST* tree);
void bstPostorder(BST* tree);
void nodeChangerPre(Node* node); // для bstPreorder
void nodeChangerPost(Node* node); // для bstPostorder