#include <stdio.h>

#define MAX 5  
int queue[MAX];
int front = -1;
int rear = -1;


int isFull() {
    return (front == (rear + 1) % MAX);
}


int isEmpty() {
    return front == -1;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow! Cannot add %d\n", item);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;  // Circular increment
    }
    queue[rear] = item;
    printf("%d added to the queue\n", item);
}

// Remove element from queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to remove.\n");
        return;
    }
    printf("%d removed from the queue\n", queue[front]);
    if (front == rear) {
        // Queue has only one element, reset after removal
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;  // Circular increment
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
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
    enqueue(70);
    display();

    enqueue(80); 
    return 0;
}
