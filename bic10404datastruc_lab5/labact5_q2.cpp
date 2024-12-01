#include <stdio.h>
#define SIZE 5

struct Stack {
    int top;
    char data[SIZE]; // Change data type to char
};

typedef struct Stack stack; // Rename from 'Stack' to 'stack'

void createStack(stack *S);
void menu();
int isEmpty(stack *S);
int isFull(stack *S);
void push(stack *S);
void pop(stack *S);
void printStack(stack *S);

int main() {
    stack s;
    int choice = 0;
    createStack(&s);

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPush to the stack\n");
                push(&s);
                printStack(&s);
                break;

            case 2:
                printf("\nPop from the stack\n");
                pop(&s);
                printStack(&s);
                break;

            case 3:
                printf("\nExiting stack menu\n");
                return 1;
                break;

            default:
                printf("\nInvalid entry, Please select 1, 2, 3, or 4\n");
        }
    } while (choice != 4);

    return 0;
}

void createStack(stack *S) {
    S->top = -1;
}

void menu() {
    printf("\n[----- Stack Menu -----]\n");
    printf("1 : Push Stack\n");
    printf("2 : Pop Stack\n");
    printf("3 : Exit Menu\n");
    printf("\nPlease enter choice >> ");
}

int isEmpty(stack *S) {
    return S->top == -1;
}

int isFull(stack *S) {
    return S->top == SIZE - 1;
}

void push(stack *S) {
    char value;

    if (isFull(S)) {
        printf("\nStack overflow - can't push\n");
    } else {
        printf("\nEnter character value to push into the stack: ");
        scanf(" %c", &value); // Add space before %c to skip leading whitespace and newline
        S->top++;
        S->data[S->top] = value;
    }
}

void pop(stack *S) {
    if (isEmpty(S)) {
        printf("\nStack underflow - can't pop\n");
    } else {
        printf("\nPopped value: %c\n", S->data[S->top]);
        S->top--;
    }
}

void printStack(stack *S) {
    if (isEmpty(S)) {
        printf("\nStack is empty\n");
    } else {
        printf("\nStack elements:\n");
        for (int i = S->top; i >= 0; i--) {
            printf("%c\n", S->data[i]);
        }
    }
}