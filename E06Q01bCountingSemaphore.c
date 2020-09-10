/**** Experiment 06.
 
 Q 1.b- Counting Semaphore.
 
 ****/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include<pthread.h>
#include<semaphore.h>
#include <signal.h>


sem_t s;
void handler(int signal)
{
    sem_post(&s);
}
void *singsong(void *param)
{
    sem_wait(&s);
    printf("I had to wait until your signal released me!\n");
}
int main()
{
    int ok = sem_init(&s, 0, 0); 
    if (ok == -1) {
       perror("Could not create unnamed semaphore");
       return 1;
    }
    signal(SIGINT, handler); 

    pthread_t tid;
    pthread_create(&tid, NULL, singsong, NULL);
    pthread_exit(NULL); 
}