#include "ListLogic.h"

void nodeDeliter(Node* node, int value)
{
    Node* curr = node;
    Node* currPrev = NULL;

    while (curr != NULL) {

        if (curr->data == value) {

            if (currPrev != NULL) {

                if ((curr->left != NULL) && (curr->right != NULL)) {
                    curr->data = minData(curr->right);
                    nodeDeliter(curr->right, minData(curr->right));
                    return;
                } else if (((curr->left == NULL) && (curr->right != NULL))) {
                    if (currPrev->data > curr->data)
                        currPrev->left = curr->right;
                    else
                        currPrev->right = curr->right;
                    free(curr);
                    return;
                } else if (((curr->left != NULL) && (curr->right == NULL))) {
                    if (currPrev->data > curr->data)
                        currPrev->left = curr->left;
                    else
                        currPrev->right = curr->left;
                    free(curr);
                    return;
                } else {
                    if (currPrev->data > curr->data)
                        currPrev->left = NULL;
                    else
                        currPrev->right = NULL;
                    free(curr);
                    return;
                }
            } else {
                if ((curr->left != NULL) && (curr->right != NULL)) {
                    curr->data = minData(curr->right);
                    nodeDeliter(curr->right, minData(curr->right));
                    return;
                } else if (((curr->left == NULL) && (curr->right != NULL)) || ((curr->left != NULL) && (curr->right == NULL))) {

                    free(curr);
                    return;

                }

                else {
                    currPrev = NULL;
                    free(curr);
                    return;
                }
            }
        }

        if (curr->data > value) {
            currPrev = curr;
            curr = curr->left;
        } else {
            currPrev = curr;
            curr = curr->right;
        }
    }
    printf("takogo uzla net");
}

void bstDelete(BST* tree, int value)
{
    nodeDeliter(tree->head, value);
}