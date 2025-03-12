#include<stdio.h>
#define max 100
int queue[max],n,c,e,temp;
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void peek();
void display();
void isempty();
void isfull();
void main () {
    printf("Enter the size of queue [Max 50] : ");
    scanf("%d",&n);
    printf("Stack Operations : \n1] Enqueue\n2] Dequeue\n3] Peek\n4] Display\n5] IsEmpty\n6] IsFull\n7] Exit\n");
    do {
        printf("Enter Choice : ");
        scanf("%d",&c);
        switch (c) {
            case 1 : enqueue(); break;
            case 2 : dequeue(); break;
            case 3 : peek(); break;
            case 4 : display(); break;
            case 5 : isempty(); break;
            case 6 : isfull(); break;
            case 7 : printf("End\n"); break;
            default : printf("Enter Valid Choice\n"); break;
        }
    } while(c!=7);
}
void enqueue() {
    if (rear == n-1) {
        printf("The Queue Is Full\n");
    }
    else {
        if(rear==-1 && front ==-1) {
            front =0;
        }
        printf("Enter Element : ");
        scanf("%d",&e);
        rear ++;
        queue[rear]=e;
    }
}
void dequeue () {
    if ( front ==-1 || front>rear) {
        printf("Queue Is Empty\n");
    }
    else {
        temp=queue[front];
        printf("Element %d Is Deleted\n",temp);
        front++;
        if(front>rear) {
            front = rear =-1; 
        }
    }
}
void display () {
    if ( front ==-1 || front>rear) {
        printf("Queue Is Empty\n");
    }
    else {
        printf("Queue Elements : \n");
        for(int i = front ;i<=rear ; i++) {
        printf("%d\n",queue[i]);
        }
    }
}
void peek () {
    if ( front ==-1 || front>rear) {
        printf("Queue Is Empty\n");
    }
    else {
        printf("Top Element : %d \n",queue[front]);
    }
}
void isempty () {
    if ( front ==-1 || front>rear) {
        printf("Queue Is Empty\n");
    }
    else {
        printf("Queue Is Not Empty\n");  
    }
}
void isfull () {
    if (rear == n-1) {
        printf("The Queue Is Full\n");
    }
    else {
        printf("The Queue Is Not Full\n");
    }
}
