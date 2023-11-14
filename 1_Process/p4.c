//4. Write a program in C, that creates mutiple children, and the parent waits for each child, collects the exit status with MACROS and each child exits with a particular exit code.

#include<stdio.h>
#include<stdlib.h>//exit()
#include<unistd.h>//fork()
#include<sys/wait.h>
#include<sys/types.h>

void main(){
    int i, status;
    pid_t pid[5];
	for (i=0; i<5; i++){
        	if ((pid[i] = fork()) == 0){//child process
			printf("Child %d created with PID: %d & PARENT_ID:%d\n",i,getpid(),getppid());
			sleep(1);
			exit(100+i);
        	}
	}
	
	// Using waitpid() and printing exit status of children.
	for (i=0; i<5; i++)
	{
        	//printf("pid[%d]=%d\n\n",i,pid[i]);
		pid_t cpid = waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			printf("Child %d terminated with status: %d\n", cpid, WEXITSTATUS(status));
	}
}
