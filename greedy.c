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

int* closestNumbers(int arr_size, int* arr, int *result_size) {
	// Complete this function
	int *outarr = NULL;
	outarr = malloc((2 * arr_size) * sizeof(int));
	int i = 0 ,  j = 0;
	int diff = 0;
	int counter = 0;
	if(arr_size >=2 && arr_size <= 20000)
	{
		for(i =0 ; i < arr_size ; i++)
		{
			for(j = i+1 ; j< arr_size ;j++)
			{
				if((arr[i] >= -1000000 && arr[i]  <= 10000000) && (arr[j] >= -1000000 && arr[j] <= 10000000))
				{
					diff = arr[j] - arr[i];
				//	printf("arr[j] : %d , arr[i] : %d , diff : %d \r\n", arr[j] , arr[i] ,  diff);
					if(counter != 0)
					{
						if(abs(diff) < abs(outarr[counter -1] - outarr[counter - 2]))
						{
							if(arr[j] > arr[i])
							{
								outarr[counter - 2] = arr[i];
								outarr[counter - 1] = arr[j];
							}
							else
							{
								outarr[counter - 2] = arr[j];
								outarr[counter - 1] = arr[i];
							}
						}
						else if(abs(diff) == abs(outarr[counter -1] - outarr[counter - 2]))
						{
							if(arr[j] > arr[i])
							{
								outarr[counter] = arr[i];
								outarr[counter + 1] = arr[j];
							}
							else
							{
								outarr[counter] = arr[j];
								outarr[counter + 1] = arr[i];
							}
							counter+=2;
						}
					}
					else
					{
						if(arr[j] > arr[i])
						{
							outarr[counter] = arr[i];
							outarr[counter + 1] = arr[j];
						}
						else
						{
							outarr[counter] = arr[j];
							outarr[counter + 1] = arr[i];
						}
						counter+=2;
					}
				}
			}
		}
	}
	
	quicksort(outarr , 0 , counter -1);	
	*result_size= counter;

	return outarr;  
}

int main() {
	int n; 
	scanf("%i", &n);
	int *arr = malloc(sizeof(int) * n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		scanf("%i",&arr[arr_i]);
	}
	int result_size;
	int* result = closestNumbers(n, arr, &result_size);
	for(int result_i = 0; result_i < result_size; result_i++) {
		if(result_i) {
			printf(" ");
		}
		printf("%d", result[result_i]);
	}
	puts("");


	return 0;
}

