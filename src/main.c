#include "ListLogic.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    BST testTree = { NULL };

    printf("%d\n", bstHeight(&testTree));

    printf("%d\n", bstSize(&testTree));

    printf("%d\n", bstMin(&testTree));

    printf("%d\n", bstMax(&testTree));
}
