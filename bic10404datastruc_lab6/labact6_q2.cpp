#include <stdio.h>
#include <stdlib.h>

#define size 5

struct queueArray{
	int head;
	int tail;
	char data[size];
};

typedef struct queueArray QueueArray;

void createQueue(QueueArray *qa);
void instructions();
void enqueue(QueueArray *qa);
void dequeue(char *item, QueueArray *qa);
int isEmpty(QueueArray *qa);
int isFull(QueueArray *qa);
void printQueue(QueueArray *qa);

int main(){
	QueueArray q1;
	int choice = 0;
	char item;
	
	createQueue(&q1);
	
	while (choice != 4){
		instructions();
    	printf(">> Enter your choice: ");
    	scanf("%d", &choice);
    	
		switch (choice){
		case 1: 	
			if (!isFull(&q1)){
				enqueue(&q1);
				printQueue(&q1);	
			} else {
				printf("\n>> The Queue is FULL.\n");
				continue; // Skip to the next iteration to check the choice again
			}
			break;
		case 2: 	
			if (!isEmpty(&q1)){
				dequeue(&item, &q1);
				printQueue(&q1);	
			} else {
				printf("\n>> The Queue is EMPTY.\n");	
				continue; // Skip to the next iteration to check the choice again
			}
			break;
		case 3:
			printQueue(&q1);
			break;
		case 4:
			printf("\n>> End program.");
			break;
		default:	
			printf("\n>> Invalid choice.\n");
		}
	}
	return 0;
}

void createQueue(QueueArray *qa){
	qa->head = 0;
	qa->tail = 0;
}

void instructions(){
    printf("\n======== Queue Array Menu ========\n"
        "| 1. Add a item to the queue     |\n"
        "| 2. Remove a item from the queue|\n"
        "| 3. Print the queue             |\n"       
        "| 4. End program                 |\n"
        "==================================\n");
}

int isEmpty(QueueArray *qa){
	if (qa->head == qa->tail)
		return(1);
	else
		return (0);
}

int isFull(QueueArray *qa){
	if (qa->tail == size)
	/* 
	** qa->head = 0;
	** qa->tail = 0;
	** if you want to repeat program
	*/
		return(1);
	else
		return (0);
}

void enqueue(QueueArray *qa){
	char value;
	
	printf("\n>> Enter a character: ");
	scanf(" %c", &value);
		
	qa->data[qa->tail] = value;
	qa->tail++;
		
	printf("\n>> Head index after enQ: %d", qa->head);
	printf("\n>> Tail index after enQ: %d", qa->tail);
}

void dequeue(char *item, QueueArray *qa){
	*item = qa->data[qa->head];
	qa->head++;
		
	printf("\n>> %c has been dequeued.", *item);
	printf("\n>> Head index after deQ: %d", qa->head);
	printf("\n>> Tail index after deQ: %d", qa->tail);
}

void printQueue(QueueArray *qa){
	int i;
	int temp;
	if (isEmpty(qa)){
		printf("\n>> The Queue is EMPTY.\n");
		return;
	} else {
	printf("\n\nThe Queue is: ");
	temp = qa->head;
	for (i = temp; i<qa->tail; i++){
		printf("\n%d -> %c", i, qa->data[i]);
		}	
	}
}