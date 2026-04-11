#include "ListLogic.h"
#include <stdio.h>

int main()
{
    BST tree = { NULL, 0 };

    // Вставляем узлы
    bstInsert(&tree, 10);
    bstInsert(&tree, 5);
    bstInsert(&tree, 15);
    bstInsert(&tree, 3);
    bstInsert(&tree, 7);
    bstInsert(&tree, 12);
    bstInsert(&tree, 20);

    // Тест F
    printf("Is valid BST? %d\n", bstIsValid(&tree));

    // Тест G
    printf("1st min: %d\n", bstKthMin(&tree, 1));
    printf("3rd min: %d\n", bstKthMin(&tree, 3));
    printf("7th min: %d\n", bstKthMin(&tree, 7));
    printf("10th min (invalid): %d\n", bstKthMin(&tree, 10));

    // Тест H
    Iterator* it = iteratorInit(&tree);
    printf("Inorder: ");
    while (iteratorHasNext(it)) {
        printf("%d ", iteratorNext(it));
    }
    printf("\n");
    iteratorFree(it);

    bstFree(&tree);
    return 0;
}
