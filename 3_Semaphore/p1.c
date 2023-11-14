//1. Write a program in C, that creates two threads, one of which increases the value of a shared variable and the other decreases the value of the SAME shared variable, and show how semaphores can help to avoid RACE CONDITION.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s;
int shared = 5;

void *th1(){
	sem_wait(&s);
	int x=shared;
	printf("Value of shared before increment %d\n", shared);
	x++;
	sleep(2);
	shared=x;
	printf("Value of shared after increment %d\n", shared);	
	sem_post(&s);
}

void *th2(){
	sem_wait(&s);
	int x=shared;
	printf("Value of shared before decrement %d\n", shared);
	x--;
	sleep(2);
	shared=x;
	printf("Value of shared after decrement %d\n", shared);	
	sem_post(&s);
}

void main(){
	sem_init(&s, 0, 1);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, th1, NULL);
	pthread_create(&t2, NULL, th2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("The final value of shared is %d\n",shared);
}