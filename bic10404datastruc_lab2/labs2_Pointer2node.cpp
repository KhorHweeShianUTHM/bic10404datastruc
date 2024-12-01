#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *dataPtr;
    struct node *link;
} NODE;

NODE* createNode(void *itemPtr) {
    NODE *nodePtr = (NODE*)malloc(sizeof(NODE));
    if (nodePtr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL; // Return NULL to indicate failure
    }
    nodePtr->dataPtr = itemPtr;
    nodePtr->link = NULL;
    return nodePtr;
}

int main() {
    int *newData;
    int *nodeData;

    NODE *node;

    // Allocate memory for newData
    newData = (int*)malloc(sizeof(int));
    if (newData == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Return 1 to indicate failure
    }
    *newData = 7;

    // Create a node with the newData
    node = createNode(newData);
    if (node == NULL) {
        fprintf(stderr, "Node creation failed\n");
        free(newData); // Free allocated memory before exiting
        return 1; // Return 1 to indicate failure
    }

    // Access the data stored in the node and print it
    nodeData = (int*)node->dataPtr;
    printf("Data from node: %d\n", *nodeData);

    // Free allocated memory before exiting
    free(newData);
    free(node);

    return 0; // Return 0 to indicate success
}