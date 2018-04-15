#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert_to_stack(struct node *head , int userdata);

struct node* remove_from_stack(struct node *head);
void main()
{
    /* remove from the frist and insert at the last 
       by moving another pointer rear */
    struct node *head = NULL;
    struct node *element = NULL , *nav = NULL;
    struct node * rear = NULL;
    int userdata = 0;
    int count =0;

    element = malloc(sizeof(struct node));
    element->data = 3;
    element->next = NULL;

    head = element;
    rear = element;

    nav = head;
    while(count < 4)
    {
        printf("Insert a element to stack");
        scanf("%d" , &userdata);
        rear = insert_to_stack(rear , userdata);
        count++;
    }

    while(nav!= NULL)
    {
        printf("Nav->data %d \r\n" , nav->data);
        nav = nav->next;
    }

    head = remove_from_stack(head);
    nav = head;
    while(nav!= NULL)
    {
        printf("Nav->data %d \r\n" , nav->data);
        nav = nav->next;
    }


}

struct node * insert_to_stack(struct node *head , int userdata)
{
    struct node * new = NULL;
    head->next = malloc(sizeof(struct node));
    new = head->next;
    new->data = userdata;
    new->next = NULL;
    return new;
}

struct node* remove_from_stack(struct node *head)
{
    struct node * temp = NULL;
    temp = head->next;
    free(head);
    return temp;
}
