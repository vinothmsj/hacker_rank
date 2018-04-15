#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

bool is_balanced(char expression[]) {

	int size = 0;
	char *arr = NULL;
	int counter = 1;
	int index = 0;
	bool out = 0;
	size = strlen(expression);
	arr = malloc(size * sizeof(char));

	if(expression[0] == '}' || expression[0] == ']' || expression[0] == ')')
	{
		return 0;
	}
	arr[index] = expression[0];
	while(counter < size)
	{
        if(arr[index] == '}' || arr[index] == ']' || arr[index] == ')')
        {
            return out;
        }
		if(arr[index] == '{' &&  expression[counter] =='}')
		{
			arr[index] = '\0';
			if(index > 0)
			{
				index--;
			}
		}
		else if(arr[index] == '[' &&  expression[counter] ==']')
		{
			arr[index] = '\0';
			if(index > 0)
			{
				index--;
			}
		}
		else if(arr[index] == '(' &&  expression[counter] ==')')
		{
			arr[index] = '\0';
			if(index > 0)
			{
				index--;
			}
		}
		else
		{
			index++;	
			arr[index] =  expression[counter];
		}
		counter++;
	}
	if(strlen(arr) == 0)
	{
		out = 1;

	}
	return out;
}

int main(){
	int t; 
	scanf("%d",&t);
	for(int a0 = 0; a0 < t; a0++){
		char* expression = (char *)malloc(512000 * sizeof(char));
		scanf("%s",expression);
		bool answer = is_balanced(expression);
		if(answer)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

