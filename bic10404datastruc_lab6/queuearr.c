#include <stdio.h>
#include <stdlib.h>


#define size 5

struct queue {
	int head;
	int tail;
	int data[size];
};

typedef struct queue Queue;

void createQueue(Queue *Q);
void menue();
int empty(Queue *Q);
int full(Queue *Q);
void enqueue(Queue *Q);
void dequeue(int *item, Queue *Q);
void display(Queue *Qt);

int main()
{
	Queue q1, q2;
	int choice = 0;
	int value;

	createQueue(&q1);

	while (choice != 4)
	{
		menue();
		scanf("%d", &choice);

		switch (choice) {
		case 1: 	printf("\nEnqueue ");
			enqueue(&q1);
			break;

		case 2: 	printf("\nDequeue ");
			dequeue(&value, &q1);
			break;

		case 3:	printf("\nDisplay Queue");
			q2 = q1;
			display(&q2);
			break;

		case 4:	printf("\nExit stack menue ");
			break;

		default:	printf("\n<< Invalid entry, Please select 1,2,3 or 4 >>\n");
		}//switch
	}//while

	printf("\n<<<<< Exit system >>>>>");
	//_getch();
	return 0;
}

void createQueue(Queue *Q)
{
	Q->head = 0;
	Q->tail = 0;
}

void menue()
{
	printf("\n\n[----- Queue Menue -----]");
	printf("\n1 : Add Value");
	printf("\n2 : Delete Value");
	printf("\n3 : Display Queue");
	printf("\n4 : Exit Menue");
	printf("\nPlease enter choice >> ");
}

int empty(Queue *Q)
{
	if (Q->head == Q->tail)
		return(1);
	else
		return (0);
}


int full(Queue *Q)
{
	if (Q->tail == size)
	// Q->head = 0;
	// Q->tail = 0;
		return(1);
	else
		return (0);
}

void enqueue(Queue *Q)
{
	int value;
	if (full(Q) == 1)
	{
		printf("\nFULL");
	}
	else
	{
		printf("\nEnter value into Queue >> ");
		scanf("%d", &value);

		
		Q->data[Q->tail] = value;
		Q->tail++;
		printf("\n Head index after enQ : %d ", Q->head);
		printf("\n Tail index after enQ : %d ", Q->tail);
	}
}


void dequeue(int *item, Queue *Q)
{
	if (empty(Q) == 1)
	{
		printf("\nEMPTY");
	}
	else
	{
		*item = Q->data[Q->head];
		Q->head++;
		printf("\nValue %d has been dequeued", *item);
		printf("\n Head index after deQ : %d ", Q->head);
		printf("\n Tail index after deQ : %d ", Q->tail);
	}
}


void display(Queue *Qt)
{
	int i;

	int temp;
	temp = Qt->head;
	for (i = temp; i<Qt->tail; i++)
	{
		printf("\n%d -> %d ", i, Qt->data[i]);
	}
}