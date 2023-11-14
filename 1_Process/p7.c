//7. Write a program in C, that creates an zombie, and displays its PID and PPID. Verify the PID, PPID values of the zombie process, from the system, using “ps” command. Also show how to eradicate zombies.

#include<stdio.h>
#include<unistd.h>//fork()
#include<sys/wait.h>

void main(){
    if(fork()==0){//child process
        sleep(4);
        printf("\n\nI am a child process\n");
        printf("My PID is: %d\n",getpid());
        printf("My parent's PID is: %d\n\n",getppid());
        printf("Child Exiting\n");
    }
    else{//parent process
	    //wait(0);
        sleep(10);
        printf("\n\nI am a parent process\n");
        printf("My PID is: %d\n",getpid());
        printf("My parent's PID is: %d\n\n",getppid());
    }
}