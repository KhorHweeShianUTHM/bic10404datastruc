#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int n);
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAtMiddle(Node* head, int position, int data);
int removeAtBeginning(Node** head);
int removeFromEnd(Node** head);
int removeFromMiddle(Node* head, int position);
Node* searchNode(Node* head, int key);
int lengthOfLinkedList(Node* head);
void displayList(Node* head);
void displayMenu();

int main() {
    Node* head = NULL;
    int choice, data, n, position, result;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                head = createLinkedList(n);
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter position to insert data in the middle: ");
                scanf("%d", &position);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtMiddle(head, position, data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 5:
                result = removeAtBeginning(&head);
                if (result != -1)
                    printf("Data removed from beginning: %d\n", result);
                break;
            case 6:
                printf("Enter position to remove from middle: ");
                scanf("%d", &position);
                result = removeFromMiddle(head, position);
                if (result != -1)
                    printf("Data removed from position %d: %d\n", position, result);
                break;
            case 7:
                result = removeFromEnd(&head);
                if (result != -1)
                    printf("Data removed from end: %d\n", result);
                break;
            case 8:
                printf("Enter data to search: ");
                scanf("%d", &data);
                Node* found = searchNode(head, data);
                if (found != NULL)
                    printf("Data %d found in the list.\n", found->data);
                else
                    printf("Data not found.\n");
                break;
            case 9:
                printf("Length of the linked list: %d\n", lengthOfLinkedList(head));
                break;
            case 10:
                displayList(head);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

Node* createLinkedList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    Node* p = NULL;
    for (int i = 0; i < n; i++) {
        temp = (Node*)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtMiddle(Node* head, int position, int data) {
    if (position < 1 || (head == NULL && position > 1)) {
        printf("Invalid position!\n");
        return;
    }
    Node* temp = head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
        if (temp == NULL || temp->next == NULL) {
            printf("Position exceeds list size.\n");
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int removeAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return -1;
    }
    Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

int removeFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    Node* temp = *head;
    Node* prev = NULL;

    if (temp->next == NULL) {
        int data = temp->data;
        free(temp);
        *head = NULL;
        return data;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    int data = temp->data;
    free(temp);
    return data;
}

int removeFromMiddle(Node* head, int position) {
    if (position < 1 || head == NULL) {
        printf("Invalid position or empty list!\n");
        return -1;
    }

    Node* current = head;
    Node* previous = NULL;

    if (position == 1) {
        head = current->next;
        int data = current->data;
        free(current);
        return data;
    }

    for (int i = 1; current != NULL && i < position; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Position exceeds list size.\n");
        return -1;
    }

    previous->next = current->next;
    int data = current->data;
    free(current);
    return data;
}

Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int lengthOfLinkedList(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void displayList(Node* head) {
    Node* temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create Linked List\n");
    printf("2. Insert at beginning\n");
    printf("3. Insert at middle\n");
    printf("4. Insert at end\n");
    printf("5. Remove from beginning\n");
    printf("6. Remove from middle\n");
    printf("7. Remove from end\n");
    printf("8. Search for a node\n");
    printf("9. Print length of linked list\n");
    printf("10. Display list\n");
    printf("0. Exit\n");
}