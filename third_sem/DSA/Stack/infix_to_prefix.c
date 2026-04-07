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

// Function to reverse a string
void reverseStr(char* str) {  
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char* exp) {
    int len = strlen(exp);
    char res[len + 1], stack[len];
    int j = 0, top = -1;

    // Reverse the expression
    reverseStr(exp);

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < len; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }

    // Convert to postfix
    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isalnum(c)) {
            res[j++] = c;  
        } else if (c == '(') {
            stack[++top] = c;  
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                res[j++] = stack[top--];
            }
            top--;  
        } else {  
            while (top != -1 && prec(c) < prec(stack[top])) {
                res[j++] = stack[top--];
            }
            stack[++top] = c;  
        }  
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        res[j++] = stack[top--];
    }

    res[j] = '\0';  
    // Reverse the result to get prefix
    reverseStr(res);
    printf("%s\n", res);
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPrefix(exp);
    return 0;
}