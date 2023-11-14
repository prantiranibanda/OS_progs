//5. Write a program in C, that replaces itself with another program using exec(). Also show the PID being the same.

#include<stdio.h>
#include<stdlib.h>//exit()
#include <unistd.h>//getpid(), getppid(), exec()
#include<sys/wait.h>//wait()
#include<sys/types.h>//pid_t

void main(){
    printf("I am the main process\n");
    printf("My PID is: %d\n",getpid());
    printf("My parent's PID is: %d\n",getppid());
    printf("Now, REPLACING MYSELF\n\n");
    execl("repl", NULL);

    printf("This line will not be printed\n");
}