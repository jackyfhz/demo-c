#include <stdio.h>
#include "utils.h"

void printHeader(const char *funcName) {
    printf("*****************************%s start*****************************\n", funcName);
}
void printFooter(const char *funcName) {
    printf("*****************************%s end*****************************\n", funcName);
}