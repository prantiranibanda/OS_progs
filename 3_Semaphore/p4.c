//4. Write a program to create two threads where one is responsible for scanning two numbers and the other is responsible for adding them. Ensure that they run in an innite loop.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s;
int a,b;

void *input(){
	while(1){
		printf("Enter the value of a,b: ");
		scanf("%d %d",&a, &b);
		sem_post(&s);
		sleep(1);
	}
}

void *add(){
	while(1){
		sem_wait(&s);
		printf("Sum: %d\n", a+b);
	}
}

void main(){
	sem_init(&s, 0, 0);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, add, NULL);
	pthread_create(&t2, NULL, input, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}