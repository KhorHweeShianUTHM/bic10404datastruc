#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
struct Book{
    char author[100];
    char publishDate[100];
    char title[100];
    char edition[100];
    char publicationBy[100];
    char callNumber[100];
    struct Book* prev;
    struct Book* next;
};

// Function to create a new book node
struct Book* createBook(const char* author, const char* publishDate, const char* title, const char* edition, const char* publicationBy, const char* callNumber){
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newBook->author, author);
    strcpy(newBook->publishDate, publishDate);
    strcpy(newBook->title, title);
    strcpy(newBook->edition, edition);
    strcpy(newBook->publicationBy, publicationBy);
    strcpy(newBook->callNumber, callNumber);
    newBook->prev = NULL;
    newBook->next = NULL;
    return newBook;
}

// Function to insert a book in alphabetical order by title
void insertBook(struct Book** head, struct Book* newBook){
    if (*head == NULL || strcmp(newBook->title, (*head)->title) < 0){
        newBook->next = *head;
        if (*head != NULL){
            (*head)->prev = newBook;
        }
        *head = newBook;
        return;
    }
    struct Book* temp = *head;
    while (temp->next != NULL && strcmp(newBook->title, temp->next->title) > 0){
        temp = temp->next;
    }
    newBook->next = temp->next;
    if (temp->next != NULL){
        temp->next->prev = newBook;
    }
    temp->next = newBook;
    newBook->prev = temp;
}

// Function to print the list of books
void printBooks(struct Book* head){
    printf("\nList of Books:\n");
    struct Book* temp = head;
    while (temp != NULL){
        printf("Title: %s\nAuthor: %s\nPublish Date: %s\nEdition: %s\nPublication By: %s\nCall Number: %s\n\n", temp->title, temp->author, temp->publishDate, temp->edition, temp->publicationBy, temp->callNumber);
        temp = temp->next;
    }
}

int main(){
    struct Book* head = NULL;
    int choice;
    char author[100], publishDate[100], title[100], publicationBy[100], callNumber[100], edition[100];

    do {
        printf("\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
        printf("1. Add a New Book\n");
        printf("2. Display All Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice){
            case 1:
                printf("\nEnter Book Details:\n");
                printf("Author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0'; // remove newline character
                
                printf("Publish Date: ");
                fgets(publishDate, sizeof(publishDate), stdin);
                publishDate[strcspn(publishDate, "\n")] = '\0'; // remove newline character
                
                printf("Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // remove newline character
                
                printf("Edition: ");
                fgets(edition, sizeof(edition), stdin);
                edition[strcspn(edition, "\n")] = '\0'; // remove newline character
                
                printf("Publication By: ");
                fgets(publicationBy, sizeof(publicationBy), stdin);
                publicationBy[strcspn(publicationBy, "\n")] = '\0'; // remove newline character
                
                printf("Call Number: ");
                fgets(callNumber, sizeof(callNumber), stdin);
                callNumber[strcspn(callNumber, "\n")] = '\0'; // remove newline character
                
                insertBook(&head, createBook(author, publishDate, title, edition, publicationBy, callNumber));
                printf("\nBook Added Successfully!\n");
                break;
            case 2:
                printBooks(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    // Freeing memory
    struct Book* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}