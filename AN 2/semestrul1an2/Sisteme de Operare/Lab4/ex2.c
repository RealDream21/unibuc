#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void printCollatz(int n)
{
    printf("%d: ", n);
    while(n > 1)
    {
        printf("%d ", n);
        if(n % 2 == 0)
            n = n/2;
        else
            n = 3 * n + 1;
    }
    printf("1\n");
    return;
}

int main(int argc, char**argv)
{
    pid_t pid = fork();
    
    if(pid < 0)
        return errno;
    else if(pid == 0)
        printCollatz(atoi(argv[1]));
    else
    {
        pid_t childPID = wait(NULL);
        printf("Child %d finished\n", childPID);
    }

    return 0;
}
