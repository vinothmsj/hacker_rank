#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void postorder_travsl(struct node * root)
{

    if(root == NULL)
        return;

    postorder_travsl(root->right);

    printf("data : %d \r\n" , root->data);

    postorder_travsl(root->left);

}
void inorder_travsl(struct node * root)
{

    if(root == NULL)
        return;

    inorder_travsl(root->left);

    printf("data : %d \r\n" , root->data);

    inorder_travsl(root->right);

}
void buildtree(int data , struct node * root)
{
    struct node *ptr = NULL;
    ptr = root;

    if(data >= ptr->data)
    {
        if(ptr->right == NULL)
        {
            ptr->right = malloc(sizeof(struct node));
            ptr = ptr->right;
            ptr->data = data;
            ptr->right = NULL;
        }
        else
        {
            buildtree(data , ptr->right);
        }
    }
    else 
    {

        if(ptr->left == NULL)
        {
            ptr->left = malloc(sizeof(struct node));
            ptr = ptr->left;
            ptr->data = data;
            ptr->left = NULL;
        }
        else
        {
            buildtree(data , ptr->left);
        }
    }

}
void printbt(struct node * root)
{
    if(root == NULL)
        return;

    printf("data : %d \r\n" , root->data);
    
    printbt(root->left);
    printbt(root->right);


}
void main()
{
    struct node *root = NULL;
    int size =0;
    int i = 0;
    int data =0;
    root = malloc(sizeof(struct node));
    if(root == NULL)
    {
        printf("malloc failed \r\n");
        return;
    }
    root->data = 10;
    printf("Enter the size \r\n");
    scanf("%d" , &size);

    while(i<size)
    {
        scanf("%d" , &data);
        buildtree(data , root);
        i++;
    }
    printbt(root);
    printf("----------------------------\r\n");
    inorder_travsl(root);
    printf("----------------------------\r\n");
    postorder_travsl(root);
}
