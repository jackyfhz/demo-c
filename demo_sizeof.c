#include "demo_sizeof.h"
#include "utils.h"


int demoSizeof() {
    printHeader(__func__);

    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Size of pointer: %zu bytes\n", sizeof(void*));
    
    struct MyStruct {
        int a;
        double b;
        char c[20];
    };
    printf("Size of MyStruct: %zu bytes\n", sizeof(struct MyStruct));

    printFooter(__func__);
    return 0;
}