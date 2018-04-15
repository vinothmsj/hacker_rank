#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int pairs(int k, int arr_size, int* arr) {
    // Complete this function
    int i =0;
    int j = 1;
    int counter = 0;
    int iter = 0;
    while(iter < arr_size)
    {/*
        for(i = 0; i < arr_size; i++)
        {
        if(abs(arr[j] - arr[i] == k))
        {
        counter++;
        }
        }
        if(j >= 0)
        {
        j--;
        iter++;
        }
        else
        {
        break;
        }
      */
        int diff = arr[j] - arr[i];

        if (diff == k) {
            counter++;
            if(j <= arr_size)
            {
                j++;
            }
            else
            {
                break;
            }
        } else if (diff > k) {
            i++;
        } else if (diff < k) {
            if(j <= arr_size)
            {
                j++;
            }
            else
            {
                break;
            }
        }
    }
    return counter;
}

int main() {
	int n; 
	int k; 
	scanf("%i %i", &n, &k);
	int *arr = malloc(sizeof(int) * n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		scanf("%i",&arr[arr_i]);
	}
	qsort(arr , n , sizeof(int) , cmpfunc);
	int i =0;
	for(i =0 ; i < n ;i++)
	{
		printf("%d \r\n" , arr[i]);

	}

	int result = pairs(k, n, arr);
	printf("%d\n", result);
	return 0;
}

