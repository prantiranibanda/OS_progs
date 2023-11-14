//3. Write a program in C, that creates two threads, one of which is responsible to increase the value of a global variable, and the other is responsible to read and print the same. Synchronise these threads with semaphores.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s;
int g;

void *readwrite(){
	printf("Enter the value of global: ");
	scanf("%d",&g);
	printf("The value of global %d\n",g);
	sem_post(&s);
}

void *increment(){
	sem_wait(&s);
	g++;
}

void main(){
	sem_init(&s, 0, 0);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, readwrite, NULL);
	pthread_create(&t2, NULL, increment, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("After increment the value of global %d\n",g);
}