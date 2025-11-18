#include <stdio.h>
#include <ctype.h>

int stack[50];
int top = -1;

// ---- PUSH NUMBER ----
void push(int x) {
    stack[++top] = x;
}

// ---- POP NUMBER ----
int pop() {
    return stack[top--];
}

int main() {
    char postfix[50];
    int i, a, b;

    // ---- INPUT POSTFIX EXPRESSION ----
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    // ---- EVALUATING POSTFIX ----
    for (i = 0; postfix[i] != '\0'; i++) {

        // If operand (digit) → push to stack
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');  // Convert char → int
        }

        // Operator encountered
        else {
            b = pop();
            a = pop();

            switch (postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    // Final answer on stack
    printf("Result = %d\n", pop());

    return 0;
}