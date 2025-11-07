#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20

typedef struct {
    char data[MAX];
    int top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char data) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = data;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->data[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^':
        case '$': return 3;
        default: return 0;
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    Stack* st = createStack();
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            push(st, ch);
        } 
        else if (ch == ')') {
            while (!isEmpty(st) && peek(st) != '(') {
                postfix[j++] = pop(st);
            }
            if (!isEmpty(st)) pop(st); // remove '('
        } 
        else {
            while (!isEmpty(st) && precedence(peek(st)) >= precedence(ch)) {
                postfix[j++] = pop(st);
            }
            push(st, ch);
        }
    }

    while (!isEmpty(st)) {
        postfix[j++] = pop(st);
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);

    free(st);
    return 0;
}
