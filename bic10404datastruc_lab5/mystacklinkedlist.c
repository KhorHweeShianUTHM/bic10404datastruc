#include <stdio.h>
#include <stdlib.h>

struct stackNode {
    int data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int num);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions();

 
int main() {
    StackNodePtr stackPtr = NULL;
    unsigned int choice = 0;
    int value;

    while (choice != 3) {
        instructions();
        scanf("%u", &choice);
        switch (choice) {
            case 1:
                printf("Enter an integer: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            case 2:
                if (!isEmpty(stackPtr)) {
                    printf("Popped value: %d\n", pop(&stackPtr));
                    printStack(stackPtr);
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;
            case 3:
                printf("Exiting stack menu.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

void instructions() {
    printf("\n[----------------------]\n");
    printf("1 to push a value on the stack\n");
    printf("2 to pop a value off the stack\n");
    printf("3 to end program\n");
    printf("[----------------------]\n");
    printf("Please enter choice >> ");
}

void push(StackNodePtr *topPtr, int num) { // don't have size limit
    StackNodePtr newPtr = malloc(sizeof(StackNode));
    if (newPtr != NULL) {
        newPtr->data = num;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    } else {
        printf("%d not inserted. No memory available.\n", num);
    }
}

int pop(StackNodePtr *topPtr) {
    StackNodePtr tempPtr = *topPtr;
    int popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

void printStack(StackNodePtr currentPtr) {
    if (isEmpty(currentPtr)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is: ");
        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n");
    }
}

int isEmpty(StackNodePtr topPtr) {
    return topPtr == NULL;
}