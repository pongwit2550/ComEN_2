#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* employeeArray[100];

//Class constructor employee
typedef struct Employee {
    int id;
    char name[50];
    char salary[50];
}Employee;

//add employee to array
void addEmployee(int id, const char* name, const char* salary) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    strcpy(newEmployee->salary, salary);

    // Store the employee in the array
    employeeArray[id] = (char*)newEmployee;
    if(employeeArray[id] == NULL) {
        printf("Memory allocation failed for employee %d\n", id);
        return;
    }
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    printf("Employee List:\n");
    for (int i = 0; i < 10; i++) {
        if (employeeArray[i] != NULL) {
            struct Employee* emp = (struct Employee*)employeeArray[i];
            printf("ID: %d, Name: %s, Salary: %s\n", emp->id, emp->name, emp->salary);
        }
    }
}
//check salary over20000 
void DisplayCheckSalary() {
    printf("================================================================\n");
    printf("Employee Salary > 20000\n");
    for (int i = 0; i < 10; i++) {
        if (employeeArray[i] != NULL) {
            struct Employee* emp = (struct Employee*)employeeArray[i];
            // Simple check - replace with actual salary comparison if needed
            if (strcmp(emp->salary, "20000") > 0) {
                printf("Name: %s\n", emp->name);
            }
        }
    }
}


int main() {
    int id;
    char name[50];
    char salary[50];
    int i = 0;
    while(i < 10){
        printf("employee  คนที่: %d in Array\n", i);
        printf("Enter employee name: ");
        scanf("%s", name);
        printf("Enter employee salary: ");
        scanf("%s", salary);
    
    
        addEmployee(i, name, salary);
        i++;
    }

    displayEmployees();
    DisplayCheckSalary();
    return 0;
}