#include "ListLogic.h"
#include <stdio.h>

bool bstContains(BST* tree, int value)
{
    Node* curr = tree -> head;

    Node* curr_prev = NULL;
    
    while(curr != NULL){

        curr_prev = curr;

        if (curr_prev -> data != value){

            if(curr_prev -> data > value) {curr_prev = curr; curr = curr -> left;}

            else{curr_prev = curr; curr = curr -> right;}
        }
        else return 1;
    }

    return 0;
}