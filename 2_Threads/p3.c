//3. Write a program where a thread adds and prints two numbers, provided to it by main. Also ensure that the thread returns the sum to the main for printing.

#include <stdio.h>
#include <stdlib.h> //malloc()
#include <pthread.h>

void *add(void *args){
    int *s = (int *)malloc(sizeof(int));
    int *x = (int *)args;
    s = x[0] + x[1];
    pthread_exit((void*)s);
}

void main(){
    int nums[2] = {30, 25};
    void * res;
    pthread_t tid;
    pthread_create(&tid, NULL, add, (void*)nums);
    pthread_join(tid, &res);
    printf("The sum of 30 and 25 is: %d\n", (int *)res);
}