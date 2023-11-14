#include<stdio.h>
#include<unistd.h>//getpid() & getppid()

void main(){
    printf("I am a replacement process\n");
    printf("My PID is: %d\n",getpid());
    printf("My parent's PID is: %d\n",getppid());
    printf("EXITING\n\n");
}