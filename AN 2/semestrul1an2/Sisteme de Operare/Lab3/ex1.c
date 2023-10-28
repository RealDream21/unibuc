#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char** argv)
{
    pid_t pid = fork();
    if(pid < 0)
    {
        return errno;
    }
    else if(pid == 0)
    {
        printf("My PID =  %d, Child PID = %d\n", getppid(), getpid());
        //sunt in copil
        execve("/usr/bin/ls", NULL, NULL);
    }
    else
    {
        //sunt in tata
        pid_t child_pid = wait(NULL);
        printf("Child %d finished\n", pid);
    }

    return 0;
}
