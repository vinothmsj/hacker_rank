#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{

    char *a[5] = {
        "vinoth",
        "andal" ,
        "ishu" ,
        "jagan"
    };

    char **b = NULL;
    int count =0;
    int i =0;
    b = malloc(10 * sizeof(char *));

    for(i =0;i < 10;i++)
    {
        b[i] = malloc(15 * sizeof(char));

        snprintf(b[i] , 15 , "%s %d" , "vinoth" ,i);

    }

    for(i=0;i< 10;i++)
    {
        printf("%s \r\n" , b[i]); 

    }

    while(count < 10)
    {
       char str ;
       str = *(b[count] + 7);
       
       printf("%c \r\n" , str);
       count++;

    }
    for(i = 0; i < 5 ; i++)
    {
        printf("%s\r\n" , a[i]);

    }

}
