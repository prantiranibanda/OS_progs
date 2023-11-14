//1. Write a program in C, that creates a child process using fork(), and also displays the child PID, and its own PID, using getpid() and getppid().

#include <stdio.h>
#include <unistd.h>//getppid(), getpid(), fork()
#include <sys/wait.h>

void main(){
    int f=fork();
    if(f==0){   //child process
        printf("\n\nThis is a Child process.\n");
        printf("My parent's PID is: %d\n",getppid());
        printf("My PID is: %d\n",getpid());
    }
    else{
    	wait(0);
    }	
}
