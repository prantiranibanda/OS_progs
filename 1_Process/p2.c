//2. Write a program in C, that creates a child and assigns a job of decreasing a variable while it itself increases the value.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    int var = 5;
    int f=fork();
    if(f==0){//child process
        printf("\n\nThis is a Child process.\n");
        var = var-1;
        printf("After decresing the value of var is: %d\n", var);
    }
    else{//parent process
    	wait(0);
        printf("\n\nThis is Main process.\n");
        var = var+1;
        printf("After incresing the value of var is: %d\n", var);
    }	
}
