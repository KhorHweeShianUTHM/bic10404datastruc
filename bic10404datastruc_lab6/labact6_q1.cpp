#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    char data;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void instructions();
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
int isEmpty(QueueNodePtr headPtr);
void printQueue(QueueNodePtr currentPtr);

int main(){
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    int choice = 0;
    char item;

    while (choice != 4){
    	instructions();
    	printf(">> Enter your choice: ");
    	scanf("%d", &choice);
    	
        switch (choice){	
        case 1:
            printf("\n>> Enter a character: ");
            scanf(" %c", &item);  // Note the space before %c to consume any leftover newline character
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;
        case 2:
            if (!isEmpty(headPtr)){
                item = dequeue(&headPtr, &tailPtr);
                printf("\n>> %c has been dequeued.\n", item);
            }
            printQueue(headPtr);
            break;
        case 3:
            printQueue(headPtr);
            break;
        case 4:
        	printf("\n>> End program.");
        	break;
        default:
            printf("\n>> Invalid choice.\n");
            break;
        }
    }
    return 0;
}

void instructions(){
    printf("\n==== Queue Linked List Menu =====\n"
        "| 1. Add a item to the queue     |\n"
        "| 2. Remove a item from the queue|\n"
        "| 3. Print the queue             |\n"       
        "| 4. End program                 |\n"
        "=================================\n");
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value){
    QueueNodePtr newPtr;

    newPtr = (struct queueNode *)malloc(sizeof(struct queueNode));

    if (newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        if (isEmpty(*headPtr)){
            *headPtr = newPtr;
        }
        else{
            (*tailPtr)->nextPtr = newPtr;
        }
        *tailPtr = newPtr;
    }
}

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
    char value;
    QueueNodePtr tempPtr;

    value = (*headPtr)->data;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL){
        *tailPtr = NULL;
    }

    free(tempPtr);
    return value;
}

int isEmpty(QueueNodePtr headPtr){
    return headPtr == NULL;
}

void printQueue(QueueNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("\n>> Queue is empty.\n");
    }
    else{
        printf("\nTe Queue is : ");

        while (currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n");
    }
}