#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
char* encryption(char* s) {
    // Complete this function
    float len = 0;
    int row = 0;
    int clmn =0;
    int x = 0;
    len = strlen(s);
    char *arr = NULL;
    char **arry = NULL;
    int i =0;
    char *ptr = NULL;
    char *temp = NULL;
    if(strlen(s) > 0 && strlen(s) <= 81)
    {

        arr = malloc(100 * sizeof(char));
        temp = arr;
        x = (int) floor( sqrt(len));
        printf("x : %d " , x);
        /*get the row */
        row = x;
        clmn = (int) ceil(sqrt(len));
        if(clmn * row  < strlen(s))
        {
            if(clmn >= row)
            {
                row++;
            }
            else
            {
                clmn++;
            }
        }

        arry = malloc(row * sizeof(char *));
        for(i =0; i < row ;i++)
        {
            arry[i] = malloc(clmn * sizeof(char));
        }
        ptr = s;
        for(i=0;i < row;i++) 
        {
            strncpy(arry[i] , ptr , clmn);
            ptr = ptr + clmn;
            printf("%s \n" , arry[i]);
        }
        int j =0;
        int counter = 0;
        memset(arr , 0 , 100); 
        while(j<clmn)
        {
            for(i=0; i<row;i++)
            {
                if(arry[i][j] != '\0')
                {
                    memcpy(arr , &arry[i][j], sizeof(char));
                    arr++;
                }
            }
            *arr = ' ';
            arr++;
            j++;
        }
    }

    return temp;

}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int result_size;
    char* result = encryption(s);
    printf("%s\n", result);
    return 0;
}

