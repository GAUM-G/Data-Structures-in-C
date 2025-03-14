#include<stdio.h> 
#include<stdbool.h> 
int queue[100]; 
int max; 
int front = -1; 
int rear=-1; 
void enqueue(); 
void dequeue(); 
void display(); 
void isfull(); 
void isempty(); 
void peek(); 
void size(); 
void search(); 
void main() { 
    int c; 
    printf("Enter the size of queue [max 100] : "); 
    scanf("%d",&max); 
    printf("Circular queue operations : \n1) Enqueue \n2) Dequeue \n3) Display \n4) IsFull\n5) IsEmpty\n6) Peek\n7) Size\n8) Search\n9) Exit\n"); 
    do { 
        printf("Enter choice : "); 
        scanf("%d",&c); 
        switch(c) { 
            case 1 : enqueue(); break; 
            case 2 : dequeue(); break; 
            case 3 : display(); break; 
            case 4 : isfull(); break; 
            case 5 : isempty(); break; 
            case 6 : peek(); break; 
            case 7 : size(); break; 
            case 8 : search(); break; 
            case 9 : printf("End\n"); break; 
            default : printf("Enter valid choice\n"); 
        } 
    }while(c!=9); 
} 
void enqueue() { 
    int e; 
    if ((rear + 1) % max == front) { 
        printf("Queue is full\n"); 
    } 
    else { 
        printf("Enter element : "); 
        scanf("%d",&e); 
        if(front==-1 && rear==-1) { 
            front = rear = 0; 
        } 
        else { 
            rear = ( rear + 1 ) % max; 
        } 
        queue[rear]=e; 
    } 
} 
void dequeue() { 
    if(front==-1) { 
        printf("Queue is empty\n"); 
    } 
    else { 
        int temp = queue[front]; 
        if(front==rear) { 
            front=rear=-1; 
        } 
        else { 
            front=(front+1)%max; 
        } 
        printf("Elemant %d is deleted \n",temp); 
    } 
} 
void display() { 
    int i; 
    if(front==-1) { 
        printf("Queue is empty\n"); 
    } 
    else { 
        if(front<=rear) { 
            for(i=front; i<=rear; i++) { 
                printf ("%d ", queue[i]); 
            } 
        } 
        else { 
            for(i=front; i<max; i++) { 
                printf("%d ",queue[i]); 
            } 
            for(i=0; i<=rear; i++) { 
                printf("%d ",queue[i]); 
            } 
        } 
        printf("\n"); 
    } 
}
void isfull() { 
    if((rear + 1) % max == front) { 
        printf("Queue is full\n"); 
    } 
    else { 
        printf("Queue is not full\n"); 
    } 
} 
void isempty() { 
    if(front==-1) { 
        printf("Queue is empty\n"); 
    } 
    else { 
        printf("Queue is not empty\n"); 
    } 
} 
void peek() { 
    if(front==-1) { 
        printf("Queue is empty\n"); 
    } 
    else { 
        printf("Top element : %d \n",queue[front]); 
    } 
} 
void size() { 
    int i; 
    int count = 0 ; 
    if(front==-1) { 
        printf("Size of queue is : 0\n"); 
    } 
    else { 
        if(front<=rear) { 
            for(i=front; i<=rear; i++) { 
                count++; 
            } 
        } 
        else { 
            for(i=front; i<max; i++) { 
                count++; 
            } 
            for(i=0; i<=rear; i++) { 
                count++; 
            } 
        } 
    } 
    printf("Size of the queue is : %d\n",count); 
} 
void search() { 
    int target,i; 
    bool found = false; 
    printf("Enter the element to be searched : "); 
    scanf("%d",&target); 
    if(front==-1) { 
        printf("Queue is empty\n"); 
    } 
    else { 
        if(front<=rear) { 
            for(i=front; i<=rear; i++) { 
                if (queue[i] == target) { 
                    found = true; 
                    break; 
                } 
            } 
        } 
        else { 
            for(i=front; i<max; i++) { 
                if (queue[i] == target) { 
                    found = true; 
                    break; 
                } 
            } 
            if(!found) { 
                for(i=0; i<=rear; i++) { 
                    if (queue[i] == target) { 
                        found = true; 
                        break; 
                    } 
                } 
            } 
        } 
    } 
    if (found) { 
        printf("Element %d found in the queue.\n", target); 
    } else { 
        printf("Element %d not found in the queue.\n", target); 
    } 
}
