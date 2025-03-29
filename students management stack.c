//Student stack program.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5  // Maximum size of the stack

// Structure to represent a student
typedef struct {
    int rollNumber;
    char name[50];
    int age;
} Student;

// Stack structure
typedef struct {
    Student data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push a student onto the stack
void push(Stack *stack, Student student) {
    if (isFull(stack)) {
        printf("Stack is full! Cannot add more students.\n");
    } else {
        stack->top++;
        stack->data[stack->top] = student;
        printf("Student %s added successfully.\n", student.name);
    }
}

// Function to pop a student from the stack
void pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No students to remove.\n");
    } else {
        Student removedStudent = stack->data[stack->top];
        stack->top--;
        printf("Student %s removed successfully.\n", removedStudent.name);
    }
}

// Function to display all students in the stack
void display(Stack *stack) {
	int i;
    if (isEmpty(stack)) {
        printf("Stack is empty! No students to display.\n");
    } else {
        printf("Students in the stack:\n");
        for ( i = stack->top; i >= 0; i--) {
            printf("Roll Number: %d, Name: %s, Age: %d\n", 
                   stack->data[i].rollNumber, stack->data[i].name, stack->data[i].age);
        }
    }
}

// Main function
int main() {
    Stack studentStack;
    initializeStack(&studentStack);

    int choice;
    do {
        printf("\n--- Student Stack Menu ---\n");
        printf("1. Add Student (Push)\n");
        printf("2. Remove Student (Pop)\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (isFull(&studentStack)) {
                    printf("Stack is full! Cannot add more students.\n");
                    break;
                }
                Student newStudent;
                printf("Enter roll number: ");
                scanf("%d", &newStudent.rollNumber);
                printf("Enter name: ");
                scanf(" %[^\n]s", newStudent.name); // Space before % to ignore newline
                printf("Enter age: ");
                scanf("%d", &newStudent.age);
                push(&studentStack, newStudent);
                break;
            }
            case 2:
                pop(&studentStack);
                break;
            case 3:
                display(&studentStack);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

