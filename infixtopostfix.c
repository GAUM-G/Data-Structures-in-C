#include <stdio.h>
#include <ctype.h>
#include <string.h>
int stack[100];
int top = -1;
void push(char ch) {
    top++;
    stack[top] = ch; 
}
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--]; 
    }
}
int priority(char op) {
    if (op == '(') {
        return 0;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return -1;
}
void main() {
    char infix[100];
    char op;
    printf("Enter the infix expression: ");
    gets(infix);  
    printf("\nPostfix expression: ");
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            printf("%c ", infix[i]);
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((op = pop()) != '(') {
                printf("%c ", op);
            }
        } else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                printf("%c ", pop());
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        printf("%c ", pop());
    }
    printf("\n");
}
