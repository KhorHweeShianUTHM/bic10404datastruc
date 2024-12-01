#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode; // Point to itself, since it's the only node initially.
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != *head) { // Loop to find the last node
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtMiddle(Node *prev_node, int data) {
    if (!prev_node) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

void deleteNode(Node **head, Node *del_node) {
    if (*head == NULL || del_node == NULL) {
        return;
    }

    Node *temp = *head;
    if (*head == del_node) {
        if ((*head)->next == *head) {
            *head = NULL;
        } else {
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = del_node->next;
            *head = del_node->next;
        }
        free(del_node);
        return;
    }

    // Find the node before del_node in the list
    Node *prev = NULL;
    while (temp->next != *head && temp->next != del_node) {
        temp = temp->next;
    }
    if (temp->next == del_node) {
        prev = temp;
    }
    if (prev == NULL) {
        printf("Node not found\n");
    } else {
        prev->next = del_node->next;
        free(del_node);
    }
}

void searchNode(Node *head, int key) {
    Node *current = head;
    int index = 0;
    if (head != NULL) {
        do {
            if (current->data == key) {
                printf("Element %d found at position %d\n", key, index);
                return;
            }
            current = current->next;
            index++;
        } while (current != head);
    }
    printf("Element %d not found in the list\n", key);
}

void displayList(Node *head) {
    Node *temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("HEAD\n");
}

int main() {
    Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the middle\n");
        printf("3. Insert at the end\n");
        printf("4. Remove a node\n");
        printf("5. Search for an element\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
            	printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
				break;
			}
            case 2: {
            	printf("Enter position after which to insert: ");
                scanf("%d", &position);
                Node *current = head;
                for (int i = 0; i < position && current != NULL; i++) {
                    current = current->next;
                }
                if (current == NULL) {
                    printf("Invalid position\n");
                } else {
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insertAtMiddle(current, data);
                }
				break;
			}
            case 3: {
            	printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
				break;
			}
            case 4: {
            	printf("Enter position of the node to delete: ");
                scanf("%d", &position);
                current = head;
                for (int i = 0; i < position && current->next != head; i++) {
                    current = current->next;
                }
                if (current == NULL) {
                    printf("Invalid position\n");
                } else {
                    deleteNode(&head, current);
                }
				break;
			}
            case 5: {
            	printf("Enter element to search: ");
                scanf("%d", &data);
                searchNode(head, data);
				break;
			}
            case 6: {
            	displayList(head);
				break;
			}
            case 7: {
            	while (head != NULL) {
                    Node *temp = head;
                    deleteNode(&head, temp);
                }
                return 0;
				break;
			}
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}