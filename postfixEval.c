#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

// ---------- Stack ----------
typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

// ---------- Integer Power (no math.h) ----------
int intPow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

// ---------- Main ----------
int main() {
    Stack st;
    init(&st);

    printf("Enter a postfix expression (use spaces, end with #):\n");
    // Example input: 5 1 2 + 4 * + 3 - #

    char token[20];
    while (1) {
        scanf("%s", token); // Read token one by one

        if (token[0] == '#') // Stop input
            break;

        // If operator
        if (strlen(token) == 1 && strchr("+-*/^", token[0])) {
            if (st.top < 1) {
                printf("Error: Not enough operands\n");
                return 1;
            }

            int b = pop(&st);
            int a = pop(&st);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        return 1;
                    }
                    result = a / b; break;
                case '^': result = intPow(a, b); break;
                default:
                    printf("Error: Unknown operator %s\n", token);
                    return 1;
            }
            push(&st, result);
        } 
        else { 
            // Number
            int num = atoi(token);
            push(&st, num);
        }
    }

    if (st.top != 0) {
        printf("Error: Invalid postfix expression\n");
        return 1;
    }

    printf("Result = %d\n", pop(&st));
    return 0;
}
