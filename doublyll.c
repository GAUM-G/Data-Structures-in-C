#include <stdio.h>
#include <malloc.h>
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *start = NULL; 

struct node *insert_beg(struct node *);
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node)); 
    if(new_node==NULL) {
        printf("\nMemory allocation failed");
        return start;
    }
    new_node->data=num;
    new_node->next=start;
    new_node->prev=NULL;
    if(start!=NULL) {
        start->prev=new_node;
    }
    start=new_node;
    return start;
}

struct node *insert_end(struct node *);
struct node *insert_end(struct node *start)
{
    struct node *ptr,*new_node;
    int num;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next=new_node;
    new_node->prev=ptr;
    new_node->next=NULL;
    return start;
}

struct node *insert_before(struct node *);
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    printf("\nEnter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data != val)
    {
        ptr = ptr -> next;
    }
    new_node -> next = ptr;
    new_node -> prev = ptr-> prev;
    ptr -> prev -> next = new_node;
    ptr -> prev = new_node;
    return start;
}

struct node *insert_after(struct node *);
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    printf("\nEnter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data != val)
    {
        ptr = ptr -> next;
    }
    new_node -> prev = ptr;
    new_node -> next = ptr -> next;
    ptr -> next -> prev = new_node;
    ptr -> next = new_node;
    return start;
}

struct node *delete_beg(struct node *);
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    start -> prev = NULL;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *);
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> prev -> next = NULL;
    free(ptr);
    return start;
}

struct node *delete_before(struct node *);
struct node *delete_before(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the value before which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    while(ptr -> data != val)
    {
        ptr = ptr -> next;
    }
    temp = ptr -> prev;
    if(temp == start)
    {
        start = delete_beg(start);
    }
    else
    {
        ptr -> prev = temp -> prev;
        temp -> prev -> next = ptr;
    }
    free(temp);
    return start;
}

struct node *delete_after(struct node *);
struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    while(ptr -> data != val)
    {
        ptr = ptr -> next;
    }
    temp = ptr -> next;
    ptr -> next = temp -> next;
    if(temp->next !=NULL) {
    temp -> next -> prev = ptr;
    }
    free(temp);
    return start;
}

struct node *display(struct node *);
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr ->next;
    }
    printf("NULL\n");
    return start;
}
void main()
{
    int option;
    printf("\n\n *****MAIN MENU *****");
    printf("\n1: Insert a node at the beginning");
    printf("\n2: Insert a node at the end");
    printf("\n3: Insert a node before a given node");
    printf("\n4: Insert a node after a given node");
    printf("\n5: Delete a node from the beginning");
    printf("\n6: Delete a node from the end");
    printf("\n7: Delete a node before a given node");
    printf("\n8: Delete a node after a given node");
    printf("\n9: Display the list");
    printf("\n10: EXIT");
    do
    {
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch(option)
        { 
            case 1: start = insert_beg(start); break;
            case 2: start = insert_end(start); break;
            case 3: start = insert_before(start); break;
            case 4: start = insert_after(start); break;
            case 5: start = delete_beg(start); break;
            case 6: start = delete_end(start); break;
            case 7: start = delete_before(start); break;
            case 8: start = delete_after(start); break;
            case 9: start = display(start); break;
            case 10: printf("\nEnd"); break;
            default : printf("\nEnter a valid option"); break;
        }
    }while(option != 10);
}
