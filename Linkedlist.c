#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *insert_beg(struct node *);
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    new_node=(struct node *) malloc (sizeof(struct node));
    new_node->data=val;
    new_node->next=start;
    start=new_node;
    return start;
}
struct node *insert_end(struct node *);
struct node *insert_end(struct node *start)
{
    struct node *ptr,*new_node;
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=NULL;
    if(start==NULL) {
        start=new_node;
    }
    else {
        ptr=start;
        while(ptr->next!=NULL) {
            ptr = ptr->next;
        }
    }
    ptr->next=new_node;
    return start;
}
struct node *insert_before(struct node *);
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the data : ");
    scanf("%d", &val);
    printf("\nEnter the value before which the data has to be inserted : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = val;
    ptr = start;
    preptr=ptr;
    while(ptr -> data != num)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = new_node;
    new_node -> next = ptr;
    return start;
}
struct node *insert_after(struct node *);
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the data : ");
    scanf("%d", &val);
    printf("\nEnter the value after which the data has to be inserted : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = val;
    ptr = start;
    preptr = ptr;
    while(preptr -> data != num)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next=new_node;
    new_node -> next = ptr;
    return start;
}
struct node *delete_beg(struct node *);
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node*);
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    if (start == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }
    if(start->next==NULL) {
        free(start);
        return NULL;  
    }
    ptr = start;
    while(ptr -> next != NULL)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = NULL;
    free(ptr);
    return start;
}
struct node *delete_node(struct node *);
struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter the value of the node which has to be deleted : ");
    scanf("%d", &val);
    if (start == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }
    ptr = start;
    if(ptr -> data == val)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while(ptr -> data != val)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        free(ptr);
        return start;
    }
}
struct node *display(struct node*);
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("NULL\n");
    return start;
}
void main() 
{
    int option;
    printf("\n*****MAIN MENU *****");
    printf("\n1:  Insert a node at the beginning");
    printf("\n2:  Insert a node at the end");
    printf("\n3:  Insert a node before a given node");
    printf("\n4:  Insert a node after a given node");
    printf("\n5:  Delete a node from the beginning");
    printf("\n6:  Delete a node from the end");
    printf("\n7:  Delete a given node");
    printf("\n8:  Display the list");
    printf("\n9:  EXIT");
    do
    {
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: start = insert_beg(start);
            break;
            case 2: start = insert_end(start);
            break;
            case 3: start = insert_before(start);
            break;
            case 4: start = insert_after(start);
            break;
            case 5: start = delete_beg(start);
            break;
            case 6: start = delete_end(start);
            break;
            case 7: start = delete_node(start);
            break;
            case 8: start = display(start);
            break;
            case 9: printf("End");
            break;
            default: printf("\nEnter valid option\n");
            break;
        }
    }
    while(option !=9);
}
