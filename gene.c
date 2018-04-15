#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int steadyGene(char* gene) {
	// Complete this function
	int len = 0;
	int comparator = 0;
	char *ptr = NULL;
	int char_val = 0 ;
	int a = 0 ,  g = 0 , t = 0 , c = 0;
	len = strlen(gene);
	comparator = len / 4;
	int replace = 0;
	ptr	= gene;
	if((len >= 4 && len <= 50000) && (len%4 == 0))
	{	
		while(*ptr != '\0')
		{
			char_val = *ptr;
			switch(char_val)
			{
				case 65:
					/* A*/
					a++;
					break;
				case 67:
					/* C */
					c++;
					break;
				case 71:
					/* G */
					g++;
					break;
				case 84:
					/* T */
					t++;
					break;
				default:
					break;
			}
			ptr++;
		}

		if(a > comparator)
		{
			replace+= a - comparator ;
		}
		if(c > comparator)
		{
			replace+= c - comparator;
		}
		if(g > comparator)
		{
			replace+= g - comparator;
		}
		if(t > comparator)
		{
			replace+= t - comparator;
		}
	}
	return replace;
}

int main() {
    int n; 
    scanf("%i", &n);
    char* gene = (char *)malloc(512000 * sizeof(char));
    scanf("%s", gene);
    int result = steadyGene(gene);
    printf("%d\n", result);
    return 0;
}

