/*******
3-( C): Create a multi-process program with one parent and 3 children. Implement the cascade execution
order of process with ID and Name.
********/
#include <stdlib.h>
#include<sys/types.h> 
#include<pthread.h>
#include<stdio.h> 
#include<unistd.h> 

int main() 
{ 
	int i=1;
	printf(">>Main\n");
	pid_t child_pid = fork(); 
    
    if (child_pid > 0){
        printf("Parent and wait\n");
    	wait(NULL);
        printf("Parent: pid: %d \nEnd of Parent process\n",child_pid);	
    }
    else if (child_pid == 0)
	{   
	    printf("Child #%d: pid: %d\n",i,child_pid);
	    printf(">>Second fork Call\n");
	    pid_t child_pid2= fork();
	    
	    if(child_pid2 >0)
        {
            printf("Entered and wait \n");
            
        	wait(NULL);
        	
	        printf("Child #%d: pid: %d \n",i+2,child_pid2);
	        printf("Exit\n");
	        
        }
        else if(child_pid2==0) {
            
	        printf("Child #%d: pid: %d\n",i+1,child_pid2);
        }
	}
    
	return 0; 
} 
