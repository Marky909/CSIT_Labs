#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100  

int evalPostfix(char* exp) {
    int stack[MAX], top = -1;  

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isdigit(c)) {
            stack[++top] = c - '0';  // Convert char to int and push  
        } else {  
            int op2 = stack[top--];  
            int op1 = stack[top--];  

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
    char exp[] = "53+62/*35+";  
    printf("Result: %d\n", evalPostfix(exp));  
    return 0;
}