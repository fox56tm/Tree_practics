#include <stdio.h>
#include <stdlib.h>
#include "ListLogic.h"


int main()
{
    BST testTree = {NULL};

    

    

    printf("%d\n" , bstContains(&testTree, 100));

    printf("%d\n", bstHeight(&testTree));

    printf("%d\n", bstSize(&testTree));
    
    printf("%d\n", bstMin(&testTree));
    
    printf("%d\n", bstMax(&testTree));

}
