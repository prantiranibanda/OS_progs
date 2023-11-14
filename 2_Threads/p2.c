//2. Write a program to print process ID and two threads that print their respective thread ID’s.

#include <stdio.h>
#include <unistd.h>//getpid()
#include <pthread.h>

void *threadFunction(){
    printf("\n\nI am thread\n");
    printf("My thread Id: %u\n", (unsigned long)pthread_self());
}

void main(){
    printf("\n\nI am main\n");
    printf("My PID is: %d\n",getpid());

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, threadFunction, NULL);
    pthread_create(&tid2, NULL, threadFunction, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}
