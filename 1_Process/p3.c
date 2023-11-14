//3. Write a program to create multiple children from a process and print their respective PID’s. Also print the PPID and ensure that they are generated from the same parent.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    int f;
    for(int i = 0; i <5; i++){
        f=fork();
        if(f==0){//child process
            printf("\n\nThis is %dth Child process.\n",i);
            printf("My parent's PID is: %d\n",getppid());
            printf("My PID is: %d\n",getpid());
            exit(0);
        }
        else{
            wait(0);
        }
    }	
}
