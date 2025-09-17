#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
} Node;

Node* current = NULL;

Node* createNode(char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void visitNewPage(char* url) {
    Node* newNode = createNode(url);
    if (current != NULL) {
        Node* temp = current->next;
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = newNode;
        newNode->prev = current;
    }
    current = newNode;
    printf("Visited: %s\n", url);
}

void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

void displayCurrentPage() {
    if (current == NULL) {
        printf("No page visited yet\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\nMenu:\n1. Visit New Page\n2. Go Back\n3. Go Forward\n4. Display Current Page\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitNewPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                printf("Exiting Browser Simulation\n");
                while (current != NULL && current->prev != NULL) {
                    current = current->prev;
                }
                while (current != NULL) {
                    Node* temp = current;
                    current = current->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
