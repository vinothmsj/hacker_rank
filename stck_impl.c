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

    struct node *head = NULL;
    struct node *element = NULL , *nav = NULL;
    int userdata = 0;
    int count =0;

    element = malloc(sizeof(struct node));
    element->data = 3;
    element->next = NULL;

    head = element;
    while(count < 4)
    {
        printf("Insert a element to stack");
        scanf("%d" , &userdata);
        head = insert_to_stack(head , userdata);
        count++;
    }

    nav = head;
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
    struct node * temp = head;
    struct node * new = NULL;
    new = malloc(sizeof(struct node));
    new->data = userdata;
    new->next = temp;
    return new;
}

struct node* remove_from_stack(struct node *head)
{
    struct node * temp = NULL;
    temp = head->next;
    free(head);
    return temp;
}
