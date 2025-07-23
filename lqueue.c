#include <stdio.h>

#define MAX 5  // Maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to add an element to the queue
void enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow! Cannot add %d\n", item);
        return;
    }
    if (front == -1) {
        front = 0;  // Initialize front when the first element is added
    }
    queue[++rear] = item;
    printf("%d added to the queue\n", item);
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to remove.\n");
        return;
    }
    printf("%d removed from the queue\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;  // Reset the queue when it's empty
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(60);
    display();

    return 0;
}


