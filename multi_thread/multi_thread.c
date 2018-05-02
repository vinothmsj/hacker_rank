#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <sys/types.h>
#include <pthread.h>

#define THREAD_CNT 10
void *thread_fun(void * sock_id)
{
    char buffer[1024];
    int s_fd = *((int *) sock_id);
    while(1)
    {
        recv(s_fd , buffer , 1024 , 0);
        printf("%s \r\n" , buffer);
    }
}

void main()
{
    pthread_t th[THREAD_CNT];
    pthread_t poll_fd;

    struct sockaddr_in add;
    int sock_fd , client_sock;
    int addrlen = sizeof(add); 
    int cnt = 0;
    int *arg = malloc(sizeof(*arg));

    sock_fd = socket(AF_INET , SOCK_STREAM , 0);
   
    if(sock_fd == -1)
    {
        printf("Unable to create Socket\r\n");
        return;
    }
    
    add.sin_family = AF_INET;
    add.sin_port = htons(5230);
    add.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock_fd , (struct sockaddr *) &add , sizeof(add)) < 0)
    {
        printf("Bind on the socket failed\r\n");
        return;
    }
    
    if(listen(sock_fd , 2) < 0)
    {
        printf("listen failed \r\n");
        return;
    }

    while(client_sock = accept(sock_fd , (struct sockaddr *) &add , (socklen_t*)&addrlen))
    {
        if(cnt == THREAD_CNT -1 )
        {
            send(client_sock , "Connection pool exhausted" , 150 , 0);
            if(shutdown(client_sock , SHUT_RDWR) < 0)
            {
                printf("Premature closure \r\n");
            }
            continue;
        }
        send(client_sock , "Connection established" , 150 , 0);
        *arg = client_sock;
        pthread_create(&th[cnt] , NULL , thread_fun , arg);
        cnt++;
     
    }
}
