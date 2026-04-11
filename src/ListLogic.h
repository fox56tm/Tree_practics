#ifndef LISTLOGIC_H_INCLUDED
#define LISTLOGIC_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Задача F
bool bstIsValid(BST* tree);

// Задача G
int bstKthMin(BST* tree, int k);

// Задача H
typedef struct Iterator Iterator;
Iterator* iteratorInit(BST* tree);
bool iteratorHasNext(Iterator* it);
int iteratorNext(Iterator* it);
/**
 * Возвращает следующий элемент в порядке inorder.
 * При вызове на исчерпанном итераторе возвращает INT_MIN.
 */
void iteratorFree(Iterator* it);

#endif

void bstInorder(BST* tree);
void nodeChangerIn(Node* node);
void nodeDeliter(Node* node, int value);
void bstDelete(BST* tree, int value);

#endif // LISTLOGIC_H_INCLUDED

