#include <stdio.h>
#include <stdlib.h>

struct queueNode 
{
	int data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;


void printQ(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value);
void instructions();

int main()
{
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	unsigned int choice;
	int item;

	instructions();
	printf("%s", "? ");
	scanf("%u", &choice);

	while (choice != 4) 
	{

		switch (choice) {
		case 1:
			printf("%s", "Enter a the Number >> ");
			scanf("\n%d", &item);
			enqueue(&headPtr, &tailPtr, item);
			printQ(headPtr);
			break;

		case 2:
			if (!isEmpty(headPtr))
			{
				item = dequeue(&headPtr, &tailPtr);
				printf("\n%c has been dequeued.\n");
			}
			printQ(headPtr);
			break;
		case 3:
			printQ(headPtr);
			break;
		default:
			puts("Invalid choice.\n ");
			instructions();
			break;
		}

		printf("%s", " ? ");
		scanf("%u", &choice);
	}

	puts("End of Run. ");
}

void instructions()
{
	puts("Enter choice: \n"
		"1 to add a item to the queue\n"
		"2 to remove a item to the queue\n"
		"3 to Print  the queue\n"		
		"4 to end program");
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value)
{
	QueueNodePtr newPtr;

	//newPtr = malloc(sizeof(QueueNode));
	newPtr = (struct queueNode *)malloc(sizeof(struct queueNode));

	if (newPtr != NULL)
	{
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		if (isEmpty(*headPtr))
		{
			*headPtr = newPtr;
		}
		else
		{
			(*tailPtr)->nextPtr = newPtr;
		}

		*tailPtr = newPtr;
	}
}

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	char value;
	QueueNodePtr tempPtr;

	value = (*headPtr)->data;
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
	{
		*tailPtr = NULL;
	}

	free(tempPtr);
	return value;
}

int isEmpty(QueueNodePtr headPtr)
{
	return headPtr == NULL;
}

void printQ(QueueNodePtr currentPtr)
{
	if (currentPtr == NULL)
	{
		puts("Queue is empty.\n");
	}
	else
	{
		puts("The Queue is : ");

		while (currentPtr != NULL) {
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		puts("NULL\n");
	}
}