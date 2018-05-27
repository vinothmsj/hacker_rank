#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

int variable = 0;

void send_event_th2()
{
    pthread_mutex_lock(&lock);
    variable = 1;
    pthread_mutex_unlock(&lock);
}

void send_event_th1()
{

    pthread_mutex_lock(&lock);
    variable = 0;
    pthread_mutex_unlock(&lock);

}
void *fun_1()
{
    printf("This is from th1\n");
    sleep(1);
    send_event_th2();
}

void *fun_2()
{
    printf("This is from th2\n");
    while(1)
    {
        if(variable == 1)
        {
            printf("Thread 1 changed the state\n");
            send_event_th1();
        }
    }
}

void main()
{

    pthread_t th[2];

    if(pthread_create(&th[0] , NULL , fun_1 , NULL) != 0)
    {
        printf("error creating thread \n");
        return;
    }


    if(pthread_create(&th[0] , NULL , fun_2 , NULL) != 0)
    {
        printf("error creating thread \n");
        return;
    }

    pthread_mutex_init( &lock, NULL);

    pthread_join(th[0] , NULL);
    pthread_join(th[1] , NULL);

    printf("Exiting the program \n");
}
