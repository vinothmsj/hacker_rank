#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pair
{
    int data;
    int key;
}HASH;

void main()
{

    char a[] = "abbaczzzzzfeddaa";
    int size = strlen(a);
    HASH ht[26];
    int i =0;

    memset(&ht , 0 , sizeof(ht));
    for(i =0 ; i < size;i++)
    {

        int index = a[i] % 97;
        ht[index].key = index;
        ht[index].data = ht[index].data + 1;

    }

    printf("key \t Value \n");
    for(i =0 ;i<26;i++)
    {
        if(ht[i].data != 0)
        {
            printf("%c \t %d \n" , ht[i].key + 97 , ht[i].data);
        }
    }

}
