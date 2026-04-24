#include "bst.h"

Node* createNode(int* array, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = l + (r - l) / 2;
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return NULL;
    newNode->right = createNode(array, mid + 1, r);
    newNode->data = array[mid];
    newNode->left = createNode(array, l, mid - 1);

    return newNode;
}
void nodeChangerInAdd(Node* node, int* arrayForTree, int* index)
{
    if (node == NULL)
        return;
    nodeChangerInAdd(node->left, arrayForTree, index);
    arrayForTree[*index] = node->data;
    (*index)++;
    nodeChangerInAdd(node->right, arrayForTree, index);
}
BST* bstMerge(BST* tree1, BST* tree2)
{
    if (!tree1 || !tree2) {
        printf("one tree is empty");
        return NULL;
    }
    size_t lenArrTree1 = bstSize(tree1);
    size_t lenArrTree2 = bstSize(tree2);
    int index1 = 0;
    int index2 = 0;
    if (lenArrTree1 == 0 || lenArrTree2 == 0)
        return NULL;
    int* arrayForTree1 = malloc(lenArrTree1 * sizeof(int));
    if (arrayForTree1 == NULL)
        return NULL;
    int* arrayForTree2 = malloc(lenArrTree2 * sizeof(int));
    if (arrayForTree2 == NULL) {
        free(arrayForTree1);
        return NULL;
    }
    nodeChangerInAdd(tree1->root, arrayForTree1, &index1);
    nodeChangerInAdd(tree2->root, arrayForTree2, &index2);
    int* mergeArray = malloc((lenArrTree1 + lenArrTree2) * sizeof(int));
    if (mergeArray == NULL) {
        free(arrayForTree1);
        free(arrayForTree2);
        return NULL;
    }
    int i = 0, j = 0;
    int realNodeCount = 0;
    while (i < lenArrTree1 && j < lenArrTree2) {
        if (arrayForTree1[i] < arrayForTree2[j])
            mergeArray[realNodeCount++] = arrayForTree1[i++];
        else if (arrayForTree1[i] > arrayForTree2[j])
            mergeArray[realNodeCount++] = arrayForTree2[j++];
        else {
            mergeArray[realNodeCount++] = arrayForTree1[i++];
            j++;
        }
    }
    while (i < lenArrTree1)
        mergeArray[realNodeCount++] = arrayForTree1[i++];
    while (j < lenArrTree2)
        mergeArray[realNodeCount++] = arrayForTree2[j++];
    BST* mergeTree = malloc(sizeof(BST));
    if (mergeTree == NULL) {
        free(arrayForTree1);
        free(arrayForTree2);
        free(mergeArray);
        return NULL;
    }
    mergeTree->root = createNode(mergeArray, 0, realNodeCount - 1);
    mergeTree->nodeCount = realNodeCount;
    if (mergeTree->root == NULL) {
        free(arrayForTree1);
        free(arrayForTree2);
        free(mergeArray);
        free(mergeTree);
        return NULL;
    }
    free(arrayForTree1);
    free(arrayForTree2);
    free(mergeArray);
    return mergeTree;
}
void nodeChangerIn(Node* node)
{
    if (node == NULL)
        return;
    nodeChangerIn(node->left);
    printf("%d\n", node->data);
    nodeChangerIn(node->right);
}
void bstInorder(BST* tree)
{
    if (!tree)
        return;
    nodeChangerIn(tree->root);
}
int nodeCounter(Node* node)
{
    if (node == NULL)
        return 0;

    return 1 + nodeCounter(node->right) + nodeCounter(node->left);
}
int bstSize(BST* tree)
{
    if (!tree) {
        printf("please create bst, returned value -1!\n");
        return -1;
    }
    return nodeCounter(tree->root);
}
void bstInsert(BST* tree, int value)
{
    if (!tree)
        return;
    Node* newNode = malloc(sizeof(Node));
    if (!newNode)
        return;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (tree->root == NULL) {
        tree->root = newNode;
        tree->nodeCount++;
        return;
    }
    Node* curr = tree->root;
    Node* currPrev = tree->root;
    while (curr != NULL) {
        currPrev = curr;
        if (value == curr->data) {
            free(newNode);
            return;
        } else if (value > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if (value > currPrev->data)
        currPrev->right = newNode;
    else
        currPrev->left = newNode;

    tree->nodeCount++;
}