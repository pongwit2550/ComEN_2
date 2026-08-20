#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Class constructor employee
typedef struct Employee {
    int id;
    char name[100];
    int salary[100];
}Employee;

struct Employee* employeeArray[100];


//add employee to array
void addEmployee(int id, const char* name, const int salary) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->salary[0] = salary;

    // Store the employee in the array
    employeeArray[id] = newEmployee;
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
            printf("ID: %d, Name: %s, Salary: %d\n", emp->id, emp->name, emp->salary[0]);
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
            int salaryValue = emp->salary[0]; // Get the salary value
            if (salaryValue > 20000) {
                printf("Name: %s\n", emp->name);
            }
        }
    }
}


int main() {
    int id;
    char name[100];
    int salary;
    int i = 0;
    while(i < 10){
        int j = i;
        printf("employee  คนที่: %d in Array\n", j++);
        printf("Enter employee name: ");
        scanf("%s", name);
        printf("Enter employee salary: ");
        scanf("%d", &salary);
    
    
        addEmployee(i, name, salary);
        i++;
    }

    displayEmployees();
    DisplayCheckSalary();
    return 0;
}