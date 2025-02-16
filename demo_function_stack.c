#include <stdio.h>
#include <string.h>
#include "utils.h"

// Define structure
typedef struct{
    char city[50];
    char country[50];
}Address;

typedef struct{
    char name[50];
    Address *addr;
}Person;

void testParameterMemoryAddress(int a, int *b) {
    a = 20;
    *b = 21;
    printf("In %s: addrsss of a: %p. a = %d\n", __func__, &a, a);
    printf("In %s: addrsss of b: %p. b = %d\n", __func__, b, *b);
}

void wrongSwap(Person *p1, Person *p2) {
    Person *temp = p1;
    p1 = p2;
    p2 = temp;
    printf("In %s: address of p1: %p. p1.name = %s\n", __func__, p1, p1->name);
    printf("In %s: address of p2: %p. p2.name = %s\n", __func__, p2, p2->name);
}

void swapByCopy(Person *p1, Person *p2) {
    Person temp;
    Address tempAddr;
    temp.addr = &tempAddr;

    strcpy(temp.name, p1->name);
    strcpy(temp.addr->city, p1->addr->city);
    strcpy(temp.addr->country, p1->addr->country);
    strcpy(p1->name, p2->name);
    strcpy(p1->addr->city, p2->addr->city);
    strcpy(p1->addr->country, p2->addr->country);
    strcpy(p2->name, temp.name);
    strcpy(p2->addr->city, temp.addr->city);
    strcpy(p2->addr->country, temp.addr->country);
}

void swapByChangePointer(Person **p1, Person **p2) {
    Person *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int demo_function_stack() {
    int x = 10;
    int y = 11;

    printHeader(__func__);
    testParameterMemoryAddress(x, &y);
    printf("In %s: address of x: %p. x after function called: %d\n", __func__, &x, x);
    printf("In %s: address of y: %p. y after function called: %d\n", __func__, &y, y);
    printFooter(__func__);

    Address addr1 = {"Hanoi", "Vietnam"};
    Address addr2 = {"New York", "USA"};
    Person p1 = {"John", &addr1};
    Person p2 = {"Mary", &addr2};

    printHeader(__func__);
    printf("test wrpmgSwap\n");
    printf("Before swap: p1 %p, p1.name = %s. p2 %p p2.name = %s\n", &p1, p1.name, &p2, p2.name);
    wrongSwap(&p1, &p2);
    printf("After swap: p1 %p, p1.name = %s. p2 %p p2.name = %s\n", &p1, p1.name, &p2, p2.name);
    printFooter(__func__);

    printHeader(__func__);
    printf("test swapByCopy\n");
    printf("Before swap: p1 %p, p1.name = %s. p2 %p p2.name = %s\n", &p1, p1.name, &p2, p2.name);
    swapByCopy(&p1, &p2);
    printf("After swap: p1 %p, p1.name = %s. p2 %p p2.name = %s\n", &p1, p1.name, &p2, p2.name);
    printFooter(__func__);

    printHeader(__func__);
    printf("test swapByChangePointer\n");
    Person *p3 = &p1;
    Person *p4 = &p2;
    printf("Before swap: p3 %p, p3.name = %s. p4 %p p4.name = %s\n", p3, p3->name, p4, p4->name);
    swapByChangePointer(&(p3), &(p4));
    printf("After swap: p3 %p, p3.name = %s. p4 %p p4.name = %s\n", p3, p3->name, p4, p4->name);
    printFooter(__func__);

    return 0;
}