#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void print_data()
{
    /* print the data */
    struct node *temp = NULL;
    temp = head;
    while(temp)
    {
        printf("%d \n" , temp->data);
        temp = temp->next;
    }
}
void insert_node(int data)
{
    struct node *temp = NULL;
    struct node *current = NULL;
    struct node *next = NULL;

    if(head == NULL)
    {

        /* this is the firt node */
        temp = malloc(sizeof(struct node));
        if(temp == NULL)
        {
            printf("Error %s", __func__);
            return;
        }
        temp->data = data;
        temp->next =NULL;
        head = temp;
        return;
    }
    current = head;
    next = head->next;
    while(current != NULL)
    {
        if(data > current->data )
        {
            /* inserting at head */

            temp = malloc(sizeof(struct node));
            if(temp == NULL)
            {
                printf("Error");
                return;
            }
            temp->data = data;
            temp->next = current;
            head = temp;
            return;
        }
        else if( data < current->data && head->next == NULL)
        {

            /* inserting at last */

            temp = malloc(sizeof(struct node));
            if(temp == NULL)
            {
                printf("Error");
                return;
            }
            temp->data = data;
            current->next = temp;
            temp->next = NULL;
            return;
        }
        else if( data < current->data && next && data > next->data)
        {
            /* inserting between the nodes */
            temp = malloc(sizeof(struct node));
            if(temp == NULL)
            {
                printf("Error");
                return;
            }
            temp->data = data;
            current->next = temp;
            temp->next = next;
            return;
        }
        else if(current->next == NULL && data < current->data)
        {
            /* inserrting at last */
            temp = malloc(sizeof(struct node));
            if(temp == NULL)
            {
                printf("Error");
                return;
            }
            temp->data = data;
            current->next = temp;
            temp->next = NULL;
            return;

        }
        else
        {
            /* moving the pointer */
            current = current->next;
            next = next->next;
        }

    }

}
void main()
{
    int data;
    while(1)
    {
        printf("Enter data to be inserted \r\n");
        scanf("%d" , & data);
        insert_node(data);
        print_data();
    }
}



