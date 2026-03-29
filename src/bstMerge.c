#include "ListLogic.h"

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
    size_t lenArrTree1 = bstSize(tree1);
    size_t lenArrTree2 = bstSize(tree2);
    int index1 = 0;
    int index2 = 0;

    int* arrayForTree1 = malloc(lenArrTree1 * sizeof(int));

    if (arrayForTree1 == NULL)
        return NULL;

    int* arrayForTree2 = malloc(lenArrTree2 * sizeof(int));

    if (arrayForTree2 == NULL) {
        free(arrayForTree1);
        return NULL;
    }

    memset(arrayForTree1, 0, lenArrTree1 * sizeof(int));
    memset(arrayForTree2, 0, lenArrTree2 * sizeof(int));

    nodeChangerInAdd(tree1->head, arrayForTree1, &index1);

    nodeChangerInAdd(tree2->head, arrayForTree2, &index2);

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

    mergeTree->head = createNode(mergeArray, 0, realNodeCount - 1);

    if (mergeTree->head == NULL) {
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