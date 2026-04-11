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

    int treeCount;
} BST;

void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
void freeNode(Node*);
#endif // LISTLOGIC_H_INCLUDED

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

    int treeCount;
} BST;

void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
void freeNode(Node*);
void bstInorder(BST* tree);
void nodeChangerIn(Node* node);
void nodeDeliter(Node* node, int value);
void bstDelete(BST* tree, int value);

#endif // LISTLOGIC_H_INCLUDED

