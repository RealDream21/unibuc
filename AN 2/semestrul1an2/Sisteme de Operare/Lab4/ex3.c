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

int main(int argc, char** argv)
{
    for(int i = 1; i < argc; i++)
    {
        pid_t pid = fork();
        if(pid < 0)
            return errno;
        else if(pid == 0)
        {
            char* argnew[] = {"collatz", argv[i], NULL};
            if(execve("collatz", argnew, NULL) < 0)
            {
                perror("Executabilul collatz nu a fost gasit\n");
                return errno;            
            }
        }
        else
        {
            printf("Done %d <- Child, %d <- Parent\n", wait(NULL), getpid());
        }
    }

    return 0;
}
