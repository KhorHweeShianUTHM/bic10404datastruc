#include <stdio.h>

#define SIZE 5
/*
**    __Stack____
** 4 |__________|
** 3 |__________|
** 2 |__________|
** 1 |__________|
** 0 |__________|
*/
struct Stack {
    int top;
    int data[SIZE];
};

typedef struct Stack stack; // rename from 'Stack' to 'stack'

void createStack(stack *S);
void menu();
int empty(stack *S);
int full(stack *S);
void push(stack *S);
void pop(stack *S);
void display(stack *S);

int main() {
    stack s;
    int choice = 0;
    createStack(&s); // call function

    do {
        menu(); // call function
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPush to the stack\n");
                push(&s);
                break;

            case 2:
                printf("\nPop from the stack\n");
                pop(&s);
                break;

            case 3:
                printf("\nDisplay the stack\n");
                display(&s);
                break;

            case 4:
                printf("\nExiting stack menu\n");
                break;

            default:
                printf("\nInvalid entry, Please select 1, 2, 3, or 4\n");
        }
    } while (choice != 4);

    return 0;
}

void createStack(stack *S) {
    S->top = -1; // initial value of stack is -1 that mean the stack is initially empty 
}

void menu() {
    printf("\n\n[----- Stack Menu -----]\n");
    printf("1 : Push Stack\n");
    printf("2 : Pop Stack\n");
    printf("3 : Display Stack\n");
    printf("4 : Exit Menu\n");
    printf("\nPlease enter choice >> ");
}

int empty(stack *S) {
    return S->top == -1;
}

int full(stack *S) {
    return S->top == SIZE - 1; 
}

void push(stack *S) {
    int value;

    if (full(S)) {
        printf("Stack overflow - can't push\n");
    } else {
        printf("Enter integer value to push into the stack: ");
        scanf("%d", &value);
        S->top++;
        S->data[S->top] = value;
    }
}

void pop(stack *S) {
    if (empty(S)) {
        printf("Stack underflow - can't pop\n");
    } else {
        printf("Popped value: %d\n", S->data[S->top]);
        S->top--;
    }
}

void display(stack *S) {
    if (empty(S)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = S->top; i >= 0; i--) {
            printf("%d\n", S->data[i]);
        }
    }
}