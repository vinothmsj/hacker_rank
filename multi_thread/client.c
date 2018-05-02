#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>



void main()
{


    int sock_fd = 0;
    struct sockaddr_in add;
    char in[1024]; 
    char out[1024];
    sock_fd = socket(AF_INET , SOCK_STREAM , 0);
    if(sock_fd < 0)
    {
       printf("Error creating socket\r\n");
       return;
    }

    add.sin_family = AF_INET;
    add.sin_port = htons(5230);

    if(inet_pton(AF_INET , "127.0.0.1" , &add.sin_addr) < 0)
    {
        printf("Error converting Ip \r\n");
        return;
    }
    printf("sock : %d\r\n", sock_fd);
    if(connect(sock_fd ,(struct sockaddr *) &add , sizeof(add)) < 0)
    {
        printf("error connecting \r\n");
        return;
    }
    while(1)
    {
        recv(sock_fd , out , 1024 , 0);
        scanf("%s" , in);
        send(sock_fd , in , 1024 , 0);
    }
    close(sock_fd);
}
