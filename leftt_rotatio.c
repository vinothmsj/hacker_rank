#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int * left_rotate(int size , int shift , int * inarr);

int * left_rotate(int size , int shift , int * inarr)
{
	int *arr = NULL;
	int i =0;
	int counter = 0;
	arr= malloc(size * sizeof(int));
	for(i =0; i< size; i++)
	{
		if(i< shift)
		{
			arr[size - shift  + i] = inarr[i];
		}
		else
		{
			arr[counter] = inarr[i];
			counter++;
		}
	}

	return arr;

}

int main(){
	int n; 
	int k;
	int *outArr = NULL; 
	scanf("%d %d",&n,&k);
	int *a = malloc(sizeof(int) * n);
	for(int a_i = 0; a_i < n; a_i++){
		scanf("%d",&a[a_i]);
	}
	outArr = 	left_rotate(n , k , a);
	for(int a_i = 0; a_i < n; a_i++)
	{
		printf("%d ", outArr[a_i]);
	}	
	return 0;
}

