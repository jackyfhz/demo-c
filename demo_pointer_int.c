#include <stdio.h>
#include "utils.h"

// Function to demonstrate the use of int pointer
int demoIntPointer() {
    int num = 10;
    int *ptr = &num;

    printHeader(__func__);

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value of ptr: %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    printf("Modify the value using the pointer\n");
    *ptr = 20;
    printf("New value of num after modification: %d\n", num);

    printFooter(__func__);
    return 0;
}
