#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int main() {
    char exp[MAX];
    int i, flag = 1;
    char temp;

    printf("Enter an expression: ");
    gets(exp);

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                flag = 0;
                break;
            } else {
                temp = pop();
                if ((exp[i] == ')' && (temp == '{' || temp == '[')) ||
                    (exp[i] == '}' && (temp == '(' || temp == '[')) ||
                    (exp[i] == ']' && (temp == '{' || temp == '('))) {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if (top >= 0) {
        flag = 0;
    }

    if (flag == 1) {
        printf("\nValid Expression.\n");
    } else {
        printf("\nInvalid Expression.\n");
    }

    return 0;
}
