//4. Write a program in C, to create multiple threads (10) and show how they can increase the value of a local variable and a static variable.

#include <stdio.h>
#include <stdlib.h>//malloc()
#include <pthread.h>

struct ThreadData {
    int localVariable;
};

void *myThread(void *arg) {
    static int s = 0;
    struct ThreadData *data = (struct ThreadData *)arg;
    int myid = data->localVariable;
    printf("Thread ID %d static %d local %d\n", myid, s++, data->localVariable++);
}

int main() {
    int i, n = 10;
    pthread_t tid[n];  
    struct ThreadData threadData[n];  
    printf("Multiple threads created\n");
    for (i = 0; i < n; i++) {
        threadData[i].localVariable = i;
        pthread_create(&tid[i], NULL, myThread, (void *)&threadData[i]); 
    }
    printf("All threads created\n");
    for (i = 0; i < n; i++)
        pthread_join(tid[i], NULL);
    return 0;
}