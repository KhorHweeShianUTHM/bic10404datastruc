#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   
    void* dataPtr;
    struct node* link;
} NODE;

NODE* createNode(void* itemPtr)
{
    NODE* nodePtr = (NODE*)malloc(sizeof(NODE));
    if (nodePtr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    nodePtr->dataPtr = itemPtr;
    nodePtr->link = NULL;
    return nodePtr;
}

int main() {
    // Example usage:
    int* value = (int*)malloc(sizeof(int));
    *value = 42;

    NODE* newNode = createNode(value);
    printf("New node data: %d\n", *((int*)newNode->dataPtr));

    free(value); // Don't forget to free the allocated memory
    free(newNode);

    return 0;
}
