#include <stdio.h>
#include "utils.h"

int demoIntArrayPointer() {
    // Declare and initialize an array of integers
    int arr[5] = {10, 20, 30, 40, 50};

    // Declare a pointer to an integer
    int *ptr;

    // Point the pointer to the first element of the array
    ptr = arr;

    printHeader(__func__);

    // Access and print array elements using the array
    printf("Using array:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d.  Address %p\n", i, arr[i], (void*)&arr[i]);
    }

    // Access and print array elements using the pointer
    printf("\nUsing pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d. Address %p\n", i, *(ptr + i), (void*)(ptr + i));
    }

    printFooter(__func__);
    return 0;
}