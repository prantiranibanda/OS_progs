//2. Write a program in C, that creates two threads, one of which reads a message and the other writes or displays the same on screen. Synchronise these threads with semaphores to ensure that read comes before write.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s;
char msg[100];

void *readp(){
	printf("Enter your msg: ");
	scanf("%s",&msg);
	sem_post(&s);
}

void *writep(){
	sem_wait(&s);
	printf("\nYour msg: %s\n", msg);
}

void main(){
	sem_init(&s, 0, 0);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, readp, NULL);
	pthread_create(&t2, NULL, writep, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}