#include <stdio.h>
#include <stdlib.h>

struct stackNode {
    char data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode* StackNodePtr; // Ensure consistency in typedef naming

void menu();
int isEmpty(StackNodePtr topPtr);
void push(StackNodePtr* topPtr, char ch);
char pop(StackNodePtr* topPtr);
void printStack(StackNodePtr currentPtr);

int main() {
    StackNodePtr stackPtr = NULL;
    int choice = 0;
    char value;

    while (choice != 3) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter a character: ");
                scanf(" %c", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            case 2:
                if (!isEmpty(stackPtr)) {
                    printf("\nPopped value: %c\n", pop(&stackPtr));
                    printStack(stackPtr);
                } else {
                    printf("\nStack is empty. Cannot pop.\n");
                }
                break;
            case 3:
                printf("\nExiting stack menu.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}

void menu() {
    printf("\n[----- Stack Menu -----]\n");
    printf("1 : Push Stack\n");
    printf("2 : Pop Stack\n");
    printf("3 : Exit Menu\n");
    printf("\nPlease enter choice >> ");
}

int isEmpty(StackNodePtr topPtr) {
    return topPtr == NULL;
}

void push(StackNodePtr* topPtr, char ch) {
    StackNodePtr newPtr = (StackNodePtr)malloc(sizeof(StackNode)); // Cast malloc return to StackNodePtr
    if (newPtr == NULL) {
        printf("\nMemory allocation failed. Cannot push %c\n", ch);
        return;
    }
    newPtr->data = ch;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
}

char pop(StackNodePtr* topPtr) {
    StackNodePtr tempPtr = *topPtr;
    char popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

void printStack(StackNodePtr currentPtr) {
    if (isEmpty(currentPtr)) {
        printf("\nStack is empty\n");
    } else {
        printf("\nStack elements:\n");
        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n");
    }
}