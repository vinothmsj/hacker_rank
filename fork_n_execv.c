#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{

    pid_t id = fork();

    if(id < 0)
    {
        printf("error occured");
        exit(0);
    }
    else if(id == 0)
    {
        /* this is the child process */
        printf("Child process\n");
        execv("./print" , NULL); 
    }
    else if(id > 0)
    {
        /* parent process */
        printf("Parent process\n");

    }



}
