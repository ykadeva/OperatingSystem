/*******
3-(b) A zombie process or defunct process is a process that has completed execution but still has an
entry in the process table. Write a C program to create the Zombie process.
********/
#include <stdlib.h>
#include<sys/types.h> 
#include<pthread.h>
#include<stdio.h> 
#include<unistd.h> 

int main() 
{ 
	
	pid_t child_pid = fork(); 

	
	if (child_pid > 0)
	{   
		sleep(10);
		printf("Parent\n");
		
	}

	else		
	    printf("Child\n");
		exit(0); 

	return 0; 
} 
