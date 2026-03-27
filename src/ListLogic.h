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
int minData(Node* node);
int bstMin(BST* tree);
void bstDelete(BST* tree, int value);
void nodeDeliter(Node* node, int value); // для bstDelete
#endif // LISTLOGIC_H_INCLUDED
