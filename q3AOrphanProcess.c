/*******
3-(a) "An orphan process is a computer process whose parent process has finished or terminated,
        though it remains running itself." Write a C program for orphan process using the fork() system
        call.
********/
#include<sys/types.h> 
#include<pthread.h>
#include<stdio.h> 
#include<unistd.h> 

int main() 
{ 
	
	int pid = fork(); 

	if (pid > 0){ 
	    
		printf("in parent process"); 
		
	}else if (pid == 0){ 
	    
		sleep(10); //long delay
		printf("in child process"); 
	} 
	return 0; 
} 
