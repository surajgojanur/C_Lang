#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

char s[MAX];
int Top = 0;

void push(char elem) {
    s[++Top] = elem;
}

char pop() {
    return (s[Top--]);
}

int precd(char elem) {
    switch(elem) {
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 2;

        case '$':
        case '^': return 3;

        case '(': return 0;
    }
    return 0;
}

int main(void) {

    char infix[MAX], postfix[MAX], ch, elem;
    int i = 0, j = 0, k = 0;

    printf("\nEnter the Infix Expression : ");
    scanf("%s", infix);

    push('#');

    for(i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        if(isalnum(ch)) {
            postfix[j++] = ch;
        }
        else {
            if(ch == '(')
                push(ch);

            else if(ch == ')') {
                while(s[Top] != '(')
                    postfix[j++] = pop();
                elem = pop();  // pop '('
            }

            else {
                while(precd(s[Top]) >= precd(ch))
                    postfix[j++] = pop();
                push(ch);
            }
        }
    }

    while(s[Top] != '#') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);
    return 0;
}
