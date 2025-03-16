#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *insert_beg(struct node *head)
{
    struct node *new_node,*ptr;
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    new_node=(struct node *) malloc (sizeof(struct node));
    if(head==NULL)
    {
        head=new_node;
        new_node->data=val;
        new_node->next=head;
    }
    else 
    {
        new_node->data=val;
        new_node->next=head;
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        head=new_node;
    }
    return head;
}
struct node *insert_end(struct node *head)
{
    struct node *ptr,*new_node;
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    new_node=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=new_node;
        new_node->data=val;
        new_node->next=head;
    }
    else 
    {
        new_node->data=val;
        ptr=head;
        while(ptr->next!=head) {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->next=head;
    }
    return head;
}
struct node *insert_before(struct node *head)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the data : ");
    scanf("%d", &val);
    printf("\nEnter the value before which the data has to be inserted : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=new_node;
        new_node->data=val;
        new_node->next=head;
    }
    else
    {
        new_node->data=val;
        ptr=head;
        preptr=ptr;
        while(ptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->next=ptr;   
    }
    return head;
}
struct node *insert_after(struct node *head)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter the data : ");
    scanf("%d", &val);
    printf("\nEnter the value after which the data has to be inserted : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=new_node;
        new_node->data=val;
        new_node->next=head;
    }
    else
    {
        new_node->data=val;
        ptr=head;
        preptr=ptr;
        while(preptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        new_node->next=ptr;
        preptr->next=new_node;
    }
    return head;
}
struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    if (head == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }
    else{
        if(head->next==head) {
            ptr=head;
            head=NULL;
            free(ptr);
        }
        else{
            ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=head->next;
            struct node *temp=head;
            head=head->next;
            free(temp);
        }
    }
    return head;
}
struct node *delete_end(struct node *head)
{
    struct node *ptr, *preptr;
    if (head == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return head;
    }
    ptr = head;
    while (ptr->next != head) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = head;
    free(ptr);
    return head;
}
struct node *delete_node(struct node *head)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter the value of the node which has to be deleted : ");
    scanf("%d", &val);
    if (head == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }
    if(head->next==head) {
        ptr=head;
        head=NULL;
        free(ptr);
    }
    preptr = head;                                                 
    ptr = head->next;
    while (ptr != head) {
        if (ptr->data == val) {
            preptr->next = ptr->next;
            free(ptr);
            return head;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    printf("\nNode with value %d not found\n", val);
    return head;
}
struct node *display(struct node *head)
{
    struct node *ptr;
    if (head == NULL) {
        printf("\nList is empty");
        return NULL;
    }
    else{
        ptr=head;
        while(ptr->next!=head) {
            printf("%d -> ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
    printf("\n");
    return head;
}
void main()
{
    int option;
    printf("\n*****MAIN MENU *****");
    printf("\n1: Insert a node at the beginning");
    printf("\n2: Insert a node at the end");
    printf("\n3: Insert a node before a given node");
    printf("\n4: Insert a node after a given node");
    printf("\n5: Delete a node from the beginning");
    printf("\n6: Delete a node from the end");
    printf("\n7: Delete a given node");
    printf("\n8: Display the list");
    printf("\n9: EXIT");
    do
    {
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: head = insert_beg(head);
            break;
            case 2: head = insert_end(head);
            break;
            case 3: head = insert_before(head);
            break;
            case 4: head = insert_after(head);
            break;
            case 5: head = delete_beg(head);
            break;
            case 6: head = delete_end(head);
            break;
            case 7: head = delete_node(head);
            break;
            case 8: head = display(head);
            break;
            case 9: printf("End");
            break;
            default: printf("\nEnter valid option\n");
            break;
        }
    } while(option !=9);
}
