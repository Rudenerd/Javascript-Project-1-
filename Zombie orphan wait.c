Zombie:

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();
  
    // Parent process 
    if (child_pid > 0)
        sleep(50);
  
    // Child process
    else        
        exit(0);
  
    return 0;
}

Orphan:
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
  
int main()
{
    // Create a child process      
    int pid = fork();
  
    if (pid > 0)
        printf("in parent process");
  
    // Note that pid is 0 in child process
    // and negative if fork() fails
    else if (pid == 0)
    {
        sleep(30);
        printf("in child process");
    }
  
    return 0;
}

wait:

int main()
{
    pid_t cpid;
    if (fork()== 0)
        exit(0);           /* terminate child */
    else
        cpid = wait(NULL); /* reaping parent */
    printf("Parent pid = %d\n", getpid());
    printf("Child pid = %d\n", cpid);
 
    return 0;
}
