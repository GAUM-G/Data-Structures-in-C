#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;

void enqueue();
void dequeue();
void display();

void main ()
{
    int choice;
    printf("Operations\n");
    printf("1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
    do
    {
        printf("Enter your choice : \n");
        scanf("%d",& choice);
        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("END"); break;
            default: printf("Enter valid choice\n");
        }
    }
    while(choice!=4);
}
void enqueue()
{
    struct node *new_node;
    int val;
    new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Queue is full\n");
        return;
    }
    printf("Enter value: \n");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next=NULL;
    if (front == NULL)  
    {
        front = new_node;
        rear = new_node;
        front->next = NULL;
        rear->next = NULL;
    }
    else
    {
        rear->next = new_node;  
        rear = new_node;    
        rear->next = NULL;   
    }
}

void dequeue()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d\n",ptr -> data);
            ptr = ptr -> next;
        }
    }
}
