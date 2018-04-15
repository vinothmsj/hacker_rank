#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int partition(int *arr , int start , int end);
void quicksort(int * arr , int start , int end);


int partition(int * arr , int start , int end)
{
    int pivot = arr[end];
    int pindex = start;
    int temp = 0 , i = 0;

    for(i =start ; i < end; i++)
    {
        if(arr[i] >= -10000 && arr[i] <= 10000)
        {
            if(arr[i] < pivot)
            {
                temp = arr[i];
                arr[i] = arr[pindex];
                arr[pindex] = temp;
                pindex++;
            }
        }

    }

    temp = arr[pindex];
    arr[pindex] = arr[end];
    arr[end] = temp;

    return pindex;
}
void quicksort(int *arr, int start , int end)
{
    int pindex = 0;
    if(start < end)
    {
        pindex = partition(arr , start , end);
        quicksort(arr, start , pindex -1);
        quicksort(arr , pindex+1 , end);

    }
}
double findMedian(int arr_size, int* arr) {
    // Complete this function
    int i =0,temp =0 , j=0;
    double out = 0;
    
    if(arr_size>= 1 && arr_size<= 100000)
    {

        quicksort(arr , 0 , arr_size - 1);
        if(arr_size % 2 == 0)
        {
            if(arr_size == 2)
            {
                out = ((double)arr[0] + (double)arr[1])/2;
                return out;
            }
            int temp =0;
            temp = arr_size / 2;
            out = ((double)arr[temp] + (double)arr[temp - 1]);
            out = out / 2;
        }
        else
        {
            out = arr[arr_size / 2 ];
        }
    }
    return out;
}

int main() {
    int n; 
    scanf("%i", &n);
    int counter = 1;
    int *arr = malloc(sizeof(int) * n);
    for (int arr_i = 0; arr_i < n; arr_i++) {
        scanf("%i",&arr[arr_i]);
        if(arr[arr_i] >= 0 && arr[arr_i] <=1000000)
        {
            double result = findMedian(counter, arr);
            printf("%.1f\n", result);
            counter++;
        }
    }
    return 0;
}

