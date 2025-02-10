#include <stdio.h>
#include <stdlib.h>

#include "demo_sizeof.h"
#include "demo_pointer_int.h"
#include "demo_pointer_array_int.h"
#include "demo_pointer_structure.h"


void function4() { printf("Function 4 executed.\n"); }
void function5() { printf("Function 5 executed.\n"); }
void function6() { printf("Function 6 executed.\n"); }
void usage() {
    printf("1: demo sizeof 1\n");
    printf("2: demo int pointer 2\n");
    printf("3: demo using pointer to handle Int Array 3\n");
    printf("4: demo using pointer to operate structure 4\n");
    printf("5: Run function 5\n");
    printf("6: Run function 6\n");
    printf("q: Quit the program\n");
    printf("Enter a key (1-6 to run a function, q to quit):\n");
}

int main() {
    char input;

    while (1) {
        usage();
        input = getchar();
        getchar(); // to consume the newline character

        switch (input) {
            case '1': demoSizeof(); break;
            case '2': demoIntPointer(); break;
            case '3': demoIntArrayPointer(); break;
            case '4': demoStructPointer(); break;
            case '5': function5(); break;
            case '6': function6(); break;
            case 'q': exit(0);
            default: printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}