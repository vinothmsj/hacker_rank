#include<stdio.h>
#include<stdlib.h>

void reverse(char * str)
{
    if(*str == '\0')
        return;
    str++;
    reverse(str);

    printf("%c", *str);
   

}
void main()
{
    char str[] = "vinoth";
    reverse(&str[0]);

}
