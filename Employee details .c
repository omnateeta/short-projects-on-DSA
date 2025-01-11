#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee
typedef struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee* next;
} Employee;

// Function to create a new employee node
Employee* createEmployee(int id, char name[], float salary) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to add an employee to the list
void addEmployee(Employee** head, int id, char name[], float salary) {
    Employee* newEmployee = createEmployee(id, name, salary);
    if (*head == NULL) {
        *head = newEmployee;
        return;
    }
    Employee* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newEmployee;
}

// Function to display all employees
void displayEmployees(Employee* head) {
    if (head == NULL) {
        printf("No employees found.\n");
        return;
    }
    printf("Employee Details:\n");
    printf("ID\tName\t\tSalary\n");
    printf("-----------------------------------\n");
    while (head != NULL) {
        printf("%d\t%s\t\t%.2f\n", head->id, head->name, head->salary);
        head = head->next;
    }
}

// Function to search for an employee by ID
void searchEmployee(Employee* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            printf("Employee Found:\n");
            printf("ID: %d\nName: %s\nSalary: %.2f\n", head->id, head->name, head->salary);
            return;
        }
        head = head->next;
    }
    printf("Employee with ID %d not found.\n", id);
}

// Function to delete an employee by ID
void deleteEmployee(Employee** head, int id) {
    if (*head == NULL) {
        printf("No employees to delete.\n");
        return;
    }

    Employee* temp = *head;
    Employee* prev = NULL;

    // If the employee to be deleted is the head
    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Employee with ID %d deleted successfully.\n", id);
        return;
    }

    // Search for the employee to be deleted
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the employee was not found
    if (temp == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Employee with ID %d deleted successfully.\n", id);
}

// Main function
int main() {
    Employee* head = NULL;
    int choice, id;
    char name[50];
    float salary;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                printf("Enter Employee Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Employee Salary: ");
                scanf("%f", &salary);
                addEmployee(&head, id, name, salary);
                printf("Employee added successfully.\n");
                break;
            case 2:
                displayEmployees(head);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                searchEmployee(head, id);
                break;
            case 4:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(&head, id);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

