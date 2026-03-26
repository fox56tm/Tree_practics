#ifndef LISTLOGIC_H_INCLUDED
#define LISTLOGIC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int bstMin(BST* tree);
int bstMax(BST* tree);
int minData(Node* node);// для bstMin
int maxData(Node* node);// для bstMax
int bstMax(BST* tree);
#endif // LISTLOGIC_H_INCLUDED
