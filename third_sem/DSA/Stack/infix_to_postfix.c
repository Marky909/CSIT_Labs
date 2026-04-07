#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to get precedence of operators
int prec(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* exp) {
    int len = strlen(exp);
    char res[len + 1];  // Result array for the postfix expression
    char stack[len];    // Stack for operators
    int j = 0, top = -1;

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isalnum(c)) {
            res[j++] = c;  // Directly add operands to result
        } else if (c == '(') {
            stack[++top] = c;  // Push '(' to stack
        } else if (c == ')') {
            // Pop and add to result until '(' is found
            while (top != -1 && stack[top] != '(') {
                res[j++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(') {
                top--;  // Discard the '('
            }
        } else {
            // Operator: pop based on precedence
            while (top != -1 && prec(c) <= prec(stack[top]) && stack[top] != '(') {
                res[j++] = stack[top--];
            }
            stack[++top] = c;  // Push the current operator to stack
        }
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        res[j++] = stack[top--];
    }

    res[j] = '\0';  // Null-terminate the result
    printf("%s\n", res);  // Print the postfix expression
}

// Driver function
int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}