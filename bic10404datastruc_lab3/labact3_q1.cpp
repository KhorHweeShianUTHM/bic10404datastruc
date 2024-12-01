#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee
/*  _____________
** |____data____| --->(next)
*/ 
struct Employee {
    int id;
    char firstName[50];
    char lastName[50];
    int age;
    float salary;
    struct Employee* next;
};

// Function to create a new node
/*  _____________
** |____data____| --->(next)
*/ 
struct Employee* createEmployee(int id, const char* firstName, const char* lastName, int age, float salary){
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee)); // allocate memory
    if (newEmployee == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newEmployee->id = id; // new node 'id' named as 'id'
    strcpy(newEmployee->firstName, firstName); // new node 'first name' named as 'first name'
    strcpy(newEmployee->lastName, lastName); // new node 'last name' named as 'last name'
    newEmployee->age = age; // new node 'age' named as 'age'
    newEmployee->salary = salary; // new node 'salary' named as 'salary'
    newEmployee->next = NULL; // link as NULL
    return newEmployee;
}

// Function to insert a new employee node at the end of the linked list
/*  _____TEMP___________  (next)    ________TEMP________
** |__head__|___data___| --------> |__head__|___data___| 
*/ 
void insertEmployee(struct Employee** head, struct Employee* newEmployee) {
    if (*head == NULL) {
        *head = newEmployee;
        return;
    }
    struct Employee* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newEmployee;
}

// Function to print all employees in the linked list
void printList(struct Employee* head){
    struct Employee* temp = head;
    while (temp != NULL){
        printf("ID: %d\nName: %s %s\nAge: %d\nSalary: %.2f\n\n", temp->id, temp->firstName, temp->lastName, temp->age, temp->salary);
        temp = temp->next;
    }
}

// Function to print the linked list in reverse, as a normal linked list, it read from left node to right node
// because it is reverse, that mean it read from right node to left node
/*  _____TEMP___________  (next)    ________TEMP________  (next)    ________TEMP________
** |__head__|___data___| --------> |__head__|___data___| --------> |__head__|___data___|
*/ 
void printReverse(struct Employee* head){
    if (head == NULL){
    	return;
	}
    printReverse(head->next);
    
    printf("ID: %d\nName: %s %s\nAge: %d\nSalary: %.2f\n\n", head->id, head->firstName, head->lastName, head->age, head->salary);
}

// Function to calculate total salary of all employees
// add all the salary of employee
float totalSalary(struct Employee* head){
    float total = 0.0;
    struct Employee* temp = head;
    while (temp != NULL){
        total += temp->salary; // only choose 'salary' data in each node
        temp = temp->next;
    }
    printf("\n%.2f\n", total);
    return total;
}

// Function to print the middle employee information
struct Employee* findMiddle(struct Employee* head){
    if (head == NULL){
    	return NULL;
	}
    struct Employee *slow_ptr = head, *fast_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    printf("\nID: %d\nName: %s %s\nAge: %d\nSalary: %.2f\n\n", slow_ptr->id, slow_ptr->firstName, slow_ptr->lastName, slow_ptr->age, slow_ptr->salary);
    return slow_ptr;
}

// Function to find the oldest employee
struct Employee* findOldest(struct Employee* head){
    if (head == NULL){
    	return NULL;
	}
    struct Employee* oldest = head;
    struct Employee* temp = head->next;
    while (temp != NULL){
        if (temp->age > oldest->age){
        	oldest = temp;
		}
        temp = temp->next;
    }
    printf("\nID: %d\nName: %s %s\nAge: %d\nSalary: %.2f\n\n", oldest->id, oldest->firstName, oldest->lastName, oldest->age, oldest->salary);
    return oldest;
}

int main(){
    struct Employee* head = NULL;
    int choice;
    
    // Adding 11 employees' information
    insertEmployee(&head, createEmployee(101, "Amir", "Abdullah", 30, 1200));
    insertEmployee(&head, createEmployee(102, "Nurul", "Tan", 35, 1000));
    insertEmployee(&head, createEmployee(103, "Hafiz", "Lee", 40, 800));
    insertEmployee(&head, createEmployee(104, "Siti", "Wong", 25, 600));
    insertEmployee(&head, createEmployee(105, "Razak", "Ibrahim", 45, 1800));
    insertEmployee(&head, createEmployee(106, "Farah", "Lim", 32, 1500));
    insertEmployee(&head, createEmployee(107, "Ahmad", "Teh", 38, 1300));
    insertEmployee(&head, createEmployee(108, "Aisyah", "Low", 28, 700));
    insertEmployee(&head, createEmployee(109, "Haziq", "Raj", 42, 1850));
    insertEmployee(&head, createEmployee(110, "Jasmine", "Goh", 33, 1500));
    insertEmployee(&head, createEmployee(111, "Arif", "Ng", 36, 1500));

    do {
        printf("\n=========== WELCOME TO UTHM COMPANY ===========\n");
        printf("1. Print the Linked List\n");
        printf("2. Print reverse of the Linked List\n");
        printf("3. Print the total salary of all employees\n");
        printf("4. Print the employee information in the middle of the link list\n");
        printf("5. Print the information of the oldest employee\n");
        printf("6. Exit\n");
        printf("=================== THANK YOU ===================\n");
        printf("Enter your choice: ");
		scanf("%d", &choice);

        switch (choice) {
			case 1:
				printf("\nList of Employee:\n");
                printList(head);
                break;
            case 2:
            	printf("\nReverse List of Employee:\n");
                printReverse(head);
                break;
            case 3:
                 printf("\nTotal Salary of All Employees:\n");
				 totalSalary(head);
                break;
            case 4: {
            	printf("\nMiddle List of Employee:\n");
                findMiddle(head);
                break;
            }
            case 5: {
            	printf("\nOldest List of Employee:\n");
                findOldest(head);
                break;
            }
            case 6:
                printf("Exiting...\n");
                exit(1);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    // Freeing memory
    struct Employee *temp = head;
    while (temp != NULL) {
        struct Employee *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}