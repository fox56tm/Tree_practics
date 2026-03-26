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

    int treeCount;
} BST;


void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
void freeNode(Node* node); //очистка узла
void nodeChangerIn(Node* node); //для bstInorder
void bstInorder(BST* tree);
void bstPreorder(BST* tree);
void bstPostorder(BST* tree);
void nodeChangerPre(Node* node);// для bstPreorder
void nodeChangerPost(Node* node);//для bstPostorder

#endif // LISTLOGIC_H_INCLUDED
