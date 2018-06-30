#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#define FALSE 0
#define TRUE 1
/* first lets do the allocation */
void * start = NULL;
void * next = NULL;
size_t free_bytes =0;
int create_mempool(size_t size)
{

    start = malloc(size * sizeof(char));
    if(start == NULL)
    {
        printf("Disaster- No memory left in system \n");
        return FALSE;
    }
    memset(start , 0 , size);
    next = start;
    free_bytes = size;
    return TRUE;
}
void * allocate_memory(void **ptr , size_t size)
{

    if(size >  free_bytes)
    {
        printf("Requested memory cannot be allocated\n");
        return NULL;
    }
    /* Move the pointer to next free allocation 
       and return the poiter.
       Similarly move the next pointer accordingly */
    *ptr = next + 1;
    next = next + size + 1;
    free_bytes += size;
    return *ptr;
}
void int_array()
{
    int user_block = 0;
    int *arr = 0;
    int i = 0;
    printf("Enter user block space \n"); 
    scanf("%d" , &user_block);
    allocate_memory((void *) &arr , (size_t) user_block);
    if(arr == NULL)
    {
        return;
    }
    int total_int = user_block / sizeof(int) ;
    for(i = 0;i < total_int ;i++)
    {
        arr[i] = i;
        printf("%d\n" , arr[i]);
    }

}
void main()
{
    size_t pool_block;
    printf("Enter mempool block size \n");
    scanf("%zu" , &pool_block);
    if(create_mempool(pool_block) == FALSE)
    {
        exit(0);
    }
    int_array(); 
}



