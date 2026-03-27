#ifndef LISTLOGIC_H_INCLUDED
#define LISTLOGIC_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

int bstHeight(BST* tree);

int nodeHeight(Node* node);

int nodeCounter(Node* node);

int bstSize(BST* tree);

int bstMin(BST* tree); // на пустом дереве вернет 0

int bstMax(BST* tree); // на пустом дереве вернет 0

int minData(Node* node); // для bstMin

int maxData(Node* node); // для bstMax
#endif // LISTLOGIC_H_INCLUDED
