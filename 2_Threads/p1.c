#include <stdio.h>
#include <pthread.h>

void *threadFunction(){
    printf("\n\nPrinting 20-30... In thread\n");
    for(int i=20; i<31; i++)
        printf("%d ", i);
}

void main(){
    printf("\n\nPrinting 0-10... In Main\n");
    for(int i=0; i<11; i++)
        printf("%d ", i);

    pthread_t tid;
    pthread_create(&tid, NULL, threadFunction, NULL);
    pthread_join(tid, NULL);
}