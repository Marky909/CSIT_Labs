#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100  

int evalPrefix(char* exp) {
    int stack[MAX], top = -1, len = strlen(exp);

    // Scan the prefix expression from right to left
    for (int i = len - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit(c)) {
            stack[++top] = c - '0';  // Convert char to int and push  
        } else {  
            int op1 = stack[top--];  
            int op2 = stack[top--];  

            switch (c) {  
                case '+': stack[++top] = op1 + op2; break;  
                case '-': stack[++top] = op1 - op2; break;  
                case '*': stack[++top] = op1 * op2; break;  
                case '/': stack[++top] = op1 / op2; break;  
            }  
        }  
    }
    return stack[top];  // Final result  
}

int main() {
    char exp[] = "+23/62";  // Example prefix expression
    printf("Result: %d\n", evalPrefix(exp));  
    return 0;
}