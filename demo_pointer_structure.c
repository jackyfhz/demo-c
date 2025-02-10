#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "demo_pointer_structure.h"


// Define a structure
typedef struct{
    char name[50];
    int age;
}Person;

// Function to print person details
void printPerson(Person p) {
    p.age = 60;
    printf("Name: %s. Address: %p\n", p.name, (void*)&(p.name));
    printf("Age: %d.  Address: %p\n", p.age, (void*)&(p.age));
}

// Function to print person details using pointer
void printPersonPtr(Person *p) {
    printf("Name: %s. Address: %p\n", p->name, (void*)&(p->name));
    printf("Age: %d.  Address: %p\n", p->age, (void*)&(p->age));
}

int demoStructPointer() {
    printHeader(__func__);

    // Create a structure variable
    Person person1 = {"", 0};
    
    // Assign values to the structure members
    strcpy(person1.name, "John Doe");
    person1.age = 30;
    
    printf("Print details using structure variable\n");
    printf("Person1 addrss: %p\n", (void*)&person1);
    printf("Name: %s. Address: %p\n", person1.name, (void*)&(person1.name));
    printf("Age: %d.  Address: %p\n", person1.age, (void*)&(person1.age));
    
    printf("\nPrint details using structure variable as a parameter passed to function\n");
    printPerson(person1);
    printf("++++This address is different because compiler clone a new structure to pass into function++++\n");
    printf("++++So anything you changed inside the fucntion won't change the actual value of struct.++++\n");


    Person *personPtr = &person1;
    printf("\nPrint details using pointer to structure\n");
    printf("Name: %s. Address: %p\n", personPtr->name, (void*)&(personPtr->name));
    printf("Age: %d.  Address: %p\n", personPtr->age, (void*)&(personPtr->age));

    printf("\nPrint details using pointer to structure as a parameter passed to function\n");
    printPersonPtr(personPtr);

    printFooter(__func__);
    return 0;
}