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

    printf("Contains 10: %d\n", bstContains(&testTree, 10));   
    printf("Contains 30: %d\n", bstContains(&testTree, 30));   
    printf("Contains 60: %d\n", bstContains(&testTree, 60));   
    
    printf("Contains 100: %d\n", bstContains(&testTree, 100)); 
  
    printf("Is valid BST: %d\n", bstIsValid(&testTree));       
    
    bstFree(&testTree);
    return 0;
}
