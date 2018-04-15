#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int h1_sum = 0;
int h2_sum = 0;
int h3_sum = 0;
int max = 0;
int findmax()
{

    if(h1_sum > h2_sum && h1_sum > h3_sum)
    {
        max = h1_sum;
    }
    else if(h2_sum > h1_sum && h2_sum >h3_sum)
    {
        max = h2_sum;
    }
    else
    {
        max = h3_sum;
    }

}
int recursive_stack_check(int n1 , int * h1, int n2 , int * h2 , int n3, int * h3)
{

    int i = 0;
    int *arr;
    int iter = 0;
    if(h1_sum == max)
    {
        iter = n1;
        arr = h1;
    }
    else (h2_sum == max)
    {
        iter = n2;
        arr =h2;
    }
    else if(h3_sum == max)
    {
        iter = n3;
        arr = h3;
    }
        
    int count = 0;

    for(i = 0;i < n1;i++)
    {
        if(arr[i] != 0 && count == 0)
        {
            arr[i] = 0;
            count++;
        }

    }



}

int main(){
    int n1; 
    int n2; 
    int n3;

    int result = 0;
    scanf("%d %d %d",&n1,&n2,&n3);
    int *h1 = malloc(sizeof(int) * n1);
    for(int h1_i = 0; h1_i < n1; h1_i++){
       scanf("%d",&h1[h1_i]);
       h1_sum += h1[h1_i];
    }
    int *h2 = malloc(sizeof(int) * n2);
    for(int h2_i = 0; h2_i < n2; h2_i++){
       scanf("%d",&h2[h2_i]);
       h2_sum += h2[h2_i];
    }
    int *h3 = malloc(sizeof(int) * n3);
    for(int h3_i = 0; h3_i < n3; h3_i++){
       scanf("%d",&h3[h3_i]);
       h3_sum += h3[h3_i];
    }

    if(h1_sum == h2_sum && h1_sum == h3_sum && h2_sum == h3_sum)
    {
        printf("%d" , result);
        return 0;
    }
    else
    {
              result = recursive_stack_check(n1 , &h1 , n2 , &h2 , n3 , &h3);

    }
    return 0;
}


