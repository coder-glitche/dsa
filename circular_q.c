#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size;
int *cq;   // Dynamic array pointer (circular queue)

// ---- INSERT (ENQUEUE) ----
void insert(int x) {
    // Queue full condition
    if ((rear + 1) % size == front) {
        printf("Queue is Full!\n");
        return;
    }

    if (front == -1)        // First element
        front = 0;

    rear = (rear + 1) % size;
    cq[rear] = x;

    printf("Inserted: %d\n", x);
}

// ---- DELETE (DEQUEUE) ----
void delete() {
    if (front == -1) {      // Queue empty
        printf("Queue is Empty!\n");
        return;
    }

    printf("Deleted: %d\n", cq[front]);

    if (front == rear)      // Only one element
        front = rear = -1;
    else
        front = (front + 1) % size;
}

// ---- DISPLAY QUEUE ----
void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Circular Queue: ");
    int i = front;

    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int choice, val;

    // ---- SET QUEUE SIZE ----
    printf("Enter size of circular queue: ");
    scanf("%d", &size);

    cq = (int*)malloc(size * sizeof(int));   // Dynamic allocation

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
}