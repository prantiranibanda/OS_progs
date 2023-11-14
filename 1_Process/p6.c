//6. Write a program in C, that creates an orphan, and displays its PID and PPID. Verify the PID, PPID values of the orphan process, from the system, using “ps” command.

#include<stdio.h>
#include<unistd.h>//fork()
#include<sys/wait.h>

void main(){
    if(fork()==0){//child process
        sleep(5);
        printf("\n\nI am a child process\n");
        printf("My PID is: %d\n",getpid());
        printf("My parent's PID is: %d\n\n",getppid());
        printf("My parent's PID is: 1. So, I am orphan.");
    }
    else{//parent process
	sleep(3);
        printf("\n\nI am a parent process\n");
        printf("My PID is: %d\n",getpid());
        printf("My parent's PID is: %d\n\n",getppid());
        printf("Parent leaving child");
    }
}