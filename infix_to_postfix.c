#include <stdio.h>
#include <ctype.h>   // For isalnum()

char stack[50];
int top = -1;

// ---- PUSH OPERATOR ON STACK ----
void push(char x) {
    stack[++top] = x;
}

// ---- POP OPERATOR FROM STACK ----
char pop() {
    return stack[top--];
}

// ---- PRIORITY OF OPERATORS ----
int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;   // For '('
}

int main() {
    char infix[50], *p, x;

    // ---- INPUT INFIX EXPRESSION ----
    printf("Enter infix expression: ");
    scanf("%s", infix);

    p = infix;

    printf("Postfix Expression: ");

    // ---- TRAVERSING INFIX EXPRESSION ----
    while (*p != '\0') {

        // If operand → print it
        if (isalnum(*p)) {
            printf("%c", *p);
        }

        // If '(' → push to stack
        else if (*p == '(') {
            push(*p);
        }

        // If ')' → pop until '('
        else if (*p == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }

        // Operator case (+, -, *, /)
        else {
            while (top != -1 && priority(stack[top]) >= priority(*p)) {
                printf("%c", pop());
            }
            push(*p);
        }
        p++;
    }

    // ---- POP REMAINING OPERATORS ----
    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}