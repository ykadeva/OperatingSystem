#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>

int main()
{
    int  pid;
    
    pid=fork();
   
    if(pid==0){
        printf("This is Child. ID : %d \n", pid);
        
    }else{
        sleep(1);
        printf("This is Parent. ID : %d \n",pid);
        
    }

    return 0;
}
