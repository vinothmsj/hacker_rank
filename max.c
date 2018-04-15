#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* missingNumbers(int arr_size, int* arr, int brr_size, int* brr, int *result_size) {
	// Complete this function
	int * outarr = NULL;
	int * resarr = NULL;
	outarr = malloc(10001 * sizeof(int));
	resarr = malloc(10001 * sizeof(int));

	memset(outarr , 0 , sizeof(outarr));
	memset(resarr , 0 , sizeof(resarr));
	int i = 0 ;
	/* array a */
	for(i =0;i<arr_size;i++)
	{
		outarr[arr[i]]++;
//		printf("i : arr[i] : outarr[] %d : %d :  %d \r\n" ,i , arr[i] , outarr[arr[i]]);
	}
//	printf("--------------------------");
	for(i =0;i<brr_size;i++)
	{
		outarr[brr[i]]--;
//		printf("i : brr[i] : outarr[] %d : %d :  %d \r\n" ,i , brr[i] , outarr[brr[i]]);
	}

	int counter = 0;
	for(i = 0;i<10001;i++)
	{
		if(outarr[i] != 0)
		{
			resarr[counter] = i;
			counter++;
		}	
	}
	*result_size = counter;
	return resarr;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int arr_i = 0; arr_i < n; arr_i++) {
       scanf("%i",&arr[arr_i]);
    }
    int m; 
    scanf("%i", &m);
    int *brr = malloc(sizeof(int) * m);
    for (int brr_i = 0; brr_i < m; brr_i++) {
       scanf("%i",&brr[brr_i]);
    }
    int result_size;
    int* result = missingNumbers(n, arr, m, brr, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    puts("");


    return 0;
}

