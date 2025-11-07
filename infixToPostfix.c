#include <stdio.h> // Standard input/output [12]
#include <ctype.h> // For isalnum() [12]
#include <stdlib.h> // For standard library functions [12]
#include <string.h> // For strlen() [12]

#define MAX 20 // Define the maximum size of the stack/arrays [12]

// Global Stack Variables
char s[MAX]; // Stack array [12]
int Top = 0; // Stack pointer, initialized to 0 (representing an empty stack) [12]

// Stack Operations
void push(char elem)
{
    s[++Top] = elem; // Increment Top and assign element [12]
}

char pop()
{
    return (s[Top--]); // Return element and decrement Top [12]
}

// Function to determine operator precedence
// Higher return value means higher precedence
int precd(char elem)
{
    switch(elem)
    {
        case '+':
        case '-': return 1; // Lowest precedence shown [12]
        case '*':
        case '/': return 2;
        case '$': // Exponentiation (or '^') [18]
        case '^': return 3; // Highest precedence (exponentiation is Right-to-Left associative, though standard infix-to-postfix logic usually pops <= precedence operators, or strictly < for non-right-associative operators. Here we use >= for non-exponentiation and rely on the stack logic below.) [12]
        case '(': return 0; // Lowest precedence for '(' inside the stack [12]
        case '#': return 0; // Stack bottom marker [12]
        default: return -1;
    }
}

// Main function containing the conversion logic
void main(void)
{
    char infix[MAX], postfix[MAX];
    char ch, elem;
    int i = 0, j = 0; // i for infix scan, j for postfix array [14]

    printf("\nEnter the Infix Expression : ");
    scanf("%s", infix); // Read the infix expression [14]

    // Initialize stack with bottom marker '#' [14, 19]
    push('#'); 

    // Scan the Infix expression left to right [8]
    for(i=0; i<strlen(infix); i++)
    {
        ch = infix[i]; // Current character

        // If the character is an operand (alphanumeric)
        if(isalnum(ch))
        {
            postfix[j++] = ch; // Output the character to the Postfix Expression [8, 16]
        }
        else
        {
            // If '(' is encountered, push it onto the stack [6, 8]
            if(ch == '(')
            {
                push(ch);
            }
            // If ')' is encountered
            else if(ch == ')')
            {
                // Repeatedly pop and output all operators until '(' is popped from the stack [7, 8]
                while(s[Top] != '(')
                {
                    postfix[j++] = pop();
                }
                elem = pop(); // Remove '(' from stack (but not output it) [16]
            }
            // If a regular operator (@) is encountered
            else 
            {
                // Repeatedly pop each operator (y) which has the same precedence or higher precedence than the current operator (x) from the stack and append it to P [7, 10]
                while(precd(s[Top]) >= precd(ch))
                {
                    postfix[j++] = pop();
                }
                push(ch); // Push the current operator to the stack [7, 16]
            }
        }
    }
    
    // After scanning the entire infix expression, pop and output remaining operators until the stack is empty ('#') [16]
    while(s[Top] != '#')
    {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; // Null terminate the postfix string [16]
    
    printf("\nResultant Postfix Expression is : %s\n", postfix);
}

