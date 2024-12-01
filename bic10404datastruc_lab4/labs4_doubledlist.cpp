#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) return;

    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) return;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterNode(Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    Node *newNode = createNode(data);
    newNode->next = prev_node->next;
    newNode->prev = prev_node;
    prev_node->next = newNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void deleteNode(Node **head, Node *del_node) {
    if (*head == NULL || del_node == NULL) {
        return;
    }

    if (*head == del_node) {
        *head = del_node->next;
    }

    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }

    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }

    free(del_node);
}

void searchNode(Node *head, int key) {
    Node *temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}

void displayList(Node *head) {
    Node *temp = head;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert after a node\n");
        printf("3. Insert at the end\n");
        printf("4. Delete a node\n");
        printf("5. Search for an element\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter position to insert after: ");
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
                    insertAfterNode(current, data);
                }
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Enter position of the node to delete: ");
                scanf("%d", &position);
                current = head;
                for (int i = 0; i < position && current != NULL; i++) {
                    current = current->next;
                }
                if (current == NULL) {
                    printf("Invalid position\n");
                } else {
                    deleteNode(&head, current);
                }
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchNode(head, data);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                while (head != NULL) {
                    Node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}