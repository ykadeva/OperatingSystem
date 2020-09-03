/*********
  A C program to show multiple threads with local, global and static variables.
  Create three threads and print the value of the static, global and local variable.
**********/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 


int globalvar = 0; 


void *myThreadFun(void *vargp) 
{ 

	int *myid = (int *)vargp; 

	// static variable to observe its changes 
	static int staticVar = 0; 

	// Change static and global variables 
	++staticVar; ++globalvar; 

	// Printing the argument, static and global variables 
	printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, staticVar,globalvar); 
} 

int main() 
{ 
	int i; 
	pthread_t tid; 

	
	for (i = 0; i < 3; i++) {
		pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
		pthread_join(tid, NULL);
		printf("Local : %d\n",i);
    }
	pthread_exit(NULL); 
	return 0; 
} 
