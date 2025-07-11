//Implement the history list of file directories using a doubly linked list.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node* next;
    struct Node* pre;
};

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* current = NULL;

// Insert new directory or file into history
void insertAtEnd(char data[]) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->data, data);
    newnode->next = NULL;
    newnode->pre = NULL;

    if (head == NULL) {
        head = tail = current = newnode;
    } else {
        // Clear forward history if current is not at tail
        if (current != tail) {
            struct Node* temp = current->next;
            while (temp) {
                struct Node* toFree = temp;
                temp = temp->next;
                free(toFree);
            }
            current->next = NULL;
            tail = current;
        }

        tail->next = newnode;
        newnode->pre = tail;
        tail = newnode;
        current = newnode;
    }
}

// Go back in directory history
void goBack() {
    if (current && current->pre) {
        current = current->pre;
        printf("Moved back to: %s\n", current->data);
    } else {
        printf("No previous directory.\n");
    }
}

// Go forward in directory history
void goForward() {
    if (current && current->next) {
        current = current->next;
        printf("Moved forward to: %s\n", current->data);
    } else {
        printf("No forward directory.\n");
    }
}

// Display full path
void displayFullPath() {
    struct Node* temp = head;
    printf("\nCurrent Path: ");
    while (temp != NULL) {
        if (temp == current)
            printf("[%s]/", temp->data);  // mark current position
        else
            printf("%s/", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Interactive menu
void menu() {
    int choice;
    char input[100];

    while (1) {
        printf("\n==== Directory Navigation ====\n");
        printf("1. Enter folder or file\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Show full path\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter directory or file name: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // remove newline
                insertAtEnd(input);
                displayFullPath();
                break;
            case 2:
                goBack();
                displayFullPath();
                break;
            case 3:
                goForward();
                displayFullPath();
                break;
            case 4:
                displayFullPath();
                break;
            case 5:
                printf("Exiting navigation.\n");
                return;
            default:
                printf("Invalid option.\n");
        }
    }
}

// Free memory
void freeList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* toFree = temp;
        temp = temp->next;
        free(toFree);
    }
}

int main() {
    menu();
    freeList();
    return 0;
}
