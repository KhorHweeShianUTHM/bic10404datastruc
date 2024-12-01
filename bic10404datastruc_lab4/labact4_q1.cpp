#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent each node of the circular singly linked list
/*   ______________
**  |_data_|_next_|
*/
struct Student {
    char name[50]; // data
    struct Student *next; // next
};

// Function to insert a student node into the circular singly linked list
/*        ____*head_____       ____*temp_____       ____*temp_____       _*temp(newStudent)__
**  ---> |_data_|_next_| ---> |_data_|_next_| ---> |_data_|_next_| ---> |____data____|_next_| --  
**  ↑         ↑                     |                    |                          |          |
**  |         |_____________________|____________________|__________________________|         |
**  |                                                                                        |
**  -----------------------------------------------------------------------------------------
*/
void insertStudent(struct Student **head, char name[]) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
        newStudent->next = *head; // Point to itself to make it circular
    } else {
        struct Student *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->next = *head; // Make it circular
    }
}

// Function to display the list of students
/*        ____*head_____       ____*temp_____       ____*temp_____       ____*temp_____
**  ---> |_data_|_next_| ---> |_data_|_next_| ---> |_data_|_next_| ---> |_data_|_next_| --  
**  ↑         ↑                     |                    |                    |          |
**  |         |_____________________|____________________|____________________|          |
**  |                                                                                    |
**  -------------------------------------------------------------------------------------
*/
void displayStudents(struct Student *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Student *temp = head;
    do {
        printf("%s\n", temp->name);
        temp = temp->next;
    } while (temp != head);
}

// Function to display student names in ascending order
/*   __________        __________        __________        __________
**   |   temp   | ---> |  current | ---> |  current | ---> |   temp   |
**   |  Node 1  |      |  Node 2  |      |  Node 3  |      |  Node 4  |
**   |__________| <--- |__________| <--- |__________| <--- |__________
*/
void displayAscending(struct Student *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Student *temp = head;
    struct Student *current = NULL;
    char tempName[50];

    // Sorting student names using bubble sort
    do {
        current = temp->next; // temporary pointer used for comparison during sorting
        while (current != head) {
            if (strcmp(temp->name, current->name) > 0) {
                strcpy(tempName, temp->name);
                strcpy(temp->name, current->name);
                strcpy(current->name, tempName);
            }
            current = current->next;
        }
        temp = temp->next;
    } while (temp->next != head);

    temp = head;
    do {
        printf("%s\n", temp->name);
        temp = temp->next;
    } while (temp != head);
}

// Function to count the number of elements in the circular singly linked list
int countElements(struct Student *head) {
    if (head == NULL) {
        return 0;
    }

    struct Student *temp = head;
    int count = 0;

    // Traverse the list until you reach the head node again
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    struct Student *head = NULL;

    // Inserting students into the circular singly linked list
    insertStudent(&head, "Juana");
    insertStudent(&head, "Amia");
    insertStudent(&head, "Siti");
    insertStudent(&head, "Benny");

    // Displaying the list of students
    printf("List of students:\n");
    displayStudents(head);
    
    // Displaying student names in ascending order
    printf("\nStudent names in ascending order:\n");
	displayAscending(head);
    	    
    // Displaying count the number of elements in the list
    int numElements = countElements(head);
	printf("\nNumber of elements in the circular singly linked list: \n%d", numElements);    

    // Freeing allocated memory
    struct Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}