#include <stdio.h>
#include <stdlib.h>//malloc()
#include <pthread.h>

void *add(void *args){
    int *s = (int *)malloc(sizeof(int));
    int *x = (int *)args;
    s = x[0] + x[1];
    pthread_exit((void*)s);
}

void main(){
    int nums[2] = {1001 + 1055};
    void * res;
    pthread_t tid;
    pthread_create(&tid, NULL, add, (void*)nums);
    pthread_join(tid, &res);
    printf("The sum of 1001 and 1055 is: %d\n", (int *)res);
}