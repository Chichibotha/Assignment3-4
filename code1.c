#include <stdio.h>
#include <string.h>
typedef struct {
    char name[100];
    int studentID;
    int age;
} Person;

void init(Person* p, const char* inputName, int id, int inputAge) {
    strcpy(p->name, inputName);
    p->studentID = id;
    p->age = inputAge;
}

void printStudentInfo(Person* p) {
    printf("Name: %s, ID: %d, Age: %d", p->name, p->studentID, p->age);
}

int getID(Person* p) {
    return p->studentID;
}
int getAge(Person* p) {
    return p->age;
}
char* getName(Person* p) {
    return p->name;
}

void personSwap(Person* a, Person* b) {
    Person temp;
    strcpy(temp.name, a->name);
    temp.studentID = a->studentID;
    temp.age = a->age;
    
    strcpy(a->name, b->name);
    a->studentID = b->studentID;
    a->age = b->age;
    
    strcpy(b->name, temp.name);
    b->studentID = temp.studentID;
    b->age = temp.age;
}

int main() {
    Person alice, bob;
    
    init(&alice, "Alice", 2026312345, 20);
    init(&bob, "Bob", 2019354321, 25);
    
    printf("Before Swap: \n");
    printStudentInfo(&alice);
    printf(" ");
    printf("\n");
    printStudentInfo(&bob);
    printf("\n");
    printf("\n");
    
    personSwap(&alice, &bob);
    
    printf("After Swap: \n");
    printStudentInfo(&alice);
    printf(" ");
    printf("\n");
    printStudentInfo(&bob);
    printf("\n");
    
    return 0;
}