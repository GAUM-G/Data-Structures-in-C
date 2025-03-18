#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *top;

void main ()
{
    int choice;
    printf("Operations\n");
    printf("1.Push\n2.Pop\n3.Show\n4.Exit\n");
    do
    {
        printf("Enter your choice : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("End"); break;
            default: printf("Please Enter valid choice\n"); break;
        }
    }
    while(choice!=4);
}

void push () 
{
    int num;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter the number to be pushed in stack : \n");
        scanf("%d",&num);
        if(top==NULL)
        {
            new_node->data = num;
            new_node->next = NULL;
            top=new_node;
        }
        else
        {
            new_node->data = num;
            new_node->next = top;
            top=new_node;
        }
    }
}

void pop() 
{
    int item;
    struct node *ptr;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        item = top->data;
        ptr = top;
        top = top->next;
        free(ptr);
        printf("Item popped\n");
    }
}

void display()
{
    int i;
    struct node *ptr;
    ptr=top;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements \n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}
