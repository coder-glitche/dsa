#include <stdio.h>
#include <stdlib.h>

// ---- NODE STRUCTURE ----
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;    // Stack top pointer

// ---- PUSH OPERATION ----
void push(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;   // Attach previous top
    top = newNode;
    printf("Pushed %d\n", value);
}

// ---- POP OPERATION ----
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! (Empty Stack)\n");
        return;
    }

    struct Node *temp = top;
    printf("Popped %d\n", top->data);

    top = top->next;     // Move top down
    free(temp);
}

// ---- DISPLAY STACK ----
void display() {
    if (top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack contents: ");
    struct Node *temp = top;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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

    return 0;
}