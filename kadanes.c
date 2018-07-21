#include<stdio.h>
#include<stdlib.h>
/* This program is the implementation of the 
   kadanes algorithm of dynamic programming to 
   find the max of contigious subarray*/

int find_max_sum_sbarray(int * arr , int size)
{
    int max_till_now =0;
    int max_here =0;
    int i =0;
    for(i =0;i<size;i++)
    {
        /* 1. store the max_here till index i. 
           2. If the max_here is less than 0, the sum is 0.
           3. If the max_here is greater than max_till_now. Assign max_here to max-till_no
           It runs at O(n);
         */
        max_here = max_here + arr[i];
        if(max_here < 0)
            max_here = 0;
        if(max_till_now < max_here)
            max_till_now = max_here;
    }
    return max_till_now;

}
void main()
{
    int arr_siz = 0;
    int *arr_elmns = NULL;
    int max = 0;

    printf("Enter array size \n");
    scanf("%d" , &arr_siz);
    if(arr_siz!=0)
        arr_elmns = malloc(sizeof(int) * arr_siz);
    else
    {
        printf("Invalid size\n");
        main();
    }
    if(arr_elmns != NULL)
    {
        printf("Enter array elements\n");
        int i = 0;
        while(i < arr_siz )
        {
            int in = 0;
            scanf("%d" , &in);
            arr_elmns[i] = in;
            i++;
        }
    }
    max = find_max_sum_sbarray(arr_elmns , arr_siz); 
    printf("max Sum is %d \n" , max);
    exit(0);
}
