#ifndef LISTLOGIC_H_INCLUDED
#define LISTLOGIC_H_INCLUDED
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
    Node* head;
} BST;

void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
void freeNode(Node*);
void nodeChangerIn(Node* node);
void bstInorder(BST* tree);
int nodeCounter(Node* node);
int bstSize(BST* tree);
Node* createNode(int* array, int l, int r);
void nodeChangerInAdd(Node* node, int* arrayForTree, int* index);
BST* bstMerge(BST* tree1, BST* tree2);
#endif // LISTLOGIC_H_INCLUDED
