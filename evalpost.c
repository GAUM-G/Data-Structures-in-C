#include<stdio.h>
#define max 100
int stack[max];
int top =-1;
void push (int e) {
    top++;
    stack[top]=e;
}
int pop () {
    if(top==-1) {
        return -1;
    }
    else {
        int v= stack[top];
        top--;
        return v;
    }
}
int is_operator(char symbol) {
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
    return 1;
    }
    return 0;
}
int eval(char expression[]) {
    int i=0;
    int op1, op2, result;
    char symbol=expression[i];
    while(symbol!='\0') {
        if(symbol>='0' && symbol<='9') {
            int num = symbol - '0';
            push(num);
        }
        else if (is_operator(symbol)) {
            op2 =pop();
            op1 =pop();
            switch (symbol) {
                case '+': result=op1+op2;
                break;
                case '-': result=op1-op2;
                break;
                case '*': result=op1*op2;
                break;
                case '/': result=op1/op2;
                break;
            }
            push(result);
        }
        i++;
        symbol=expression[i];
    }
        result=pop();
        return result;
}
void main() {
    char expression[max];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    int result = eval(expression);
    printf("Result: %d\n", result);
}
