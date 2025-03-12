#include<stdio.h>
#define max 100
int stack[max],n,c,e,v;
int top = -1;
void push();
void pop();
void peek();
void display();
void main () {
    printf("Enter the size of stack [Max 100] : ");
    scanf("%d",&n);
    printf("Stack Operations : \n1] Push\n2] Pop\n3] Peek\n4] Display\n5] Exit \n");
    do {
        printf("Enter choice : ");
        scanf("%d",&c);
        switch (c) {
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : peek(); break;
            case 4 : display(); break;
            case 5 : printf("End"); break;
            default : printf("Enter valid choice\n"); break;
        }
    } while(c!=5);
}
void push () {
    if(top==n-1) {
        printf("Stack is Full\n");
    }
    else {
        printf("Enter element to be pushed : ");
        scanf("%d",&e);
        top++;
        stack[top]=e;
    }
}
void pop () {
    if(top==-1) {
        printf("Stack is Empty\n");
    }
    else {
        v= stack[top];
        printf("Element %d is deleted\n",v);
        top--;
    }
}
void peek () {
    if(top==-1) {
        printf("Stack is Empty\n");
    }
    else {
        printf("Top Element : %d \n",stack[top]);
    }
}
void display () {
    if(top==-1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack Elements : \n");
        for(int i = 0;i<=top ; i++) {
        printf("%d\n",stack[i]);
        }
    }
}
