#include "bst.h"

int main()
{
    BST testTree = { NULL, 0 };

    bstInsert(&testTree, 10);
    bstInsert(&testTree, 20);
    bstInsert(&testTree, 30);
    bstInsert(&testTree, 40);
    bstInsert(&testTree, 50);
    bstInsert(&testTree, 60);

    printf("Contains 100: %d\n", bstContains(&testTree, 100));
    
    for (int i = 1; i <= 7; i++) {
        int kth = bstKthMin(&testTree, i);
        if (kth != INT_MIN) {
            printf("%d-th minimum: %d\n", i, kth);
        } else {
            printf("%d-th minimum not found\n", i);
        }
    }
    
    bstFree(&testTree);
    
    return 0;
}
