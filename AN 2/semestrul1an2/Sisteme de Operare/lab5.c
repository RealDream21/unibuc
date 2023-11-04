#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <limits.h>

void writeCollatz(int* v, int n)
{
    int k = 0;
    v[k++] = INT_MAX;
    while(n > 1)
    {
        v[k++] = n;
        if(n % 2 == 0)
            n = n/2;
        else
            n = 3 * n + 1;   
    }
    v[k++] = 1;
    v[k++] = INT_MAX;
}


int main(int argc, char** argv)
{
    printf("Starting parent %d\n", getpid());

    const char* shm_name = "collatzSharedMem";

    //creez zona de memorie comuna, primind un fd pe care va fi nevoie sa l dau mai departe
    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if(shm_fd < 0)
    {
        //verific erori la creearea zonei
        perror(NULL);
        return errno;
    }
    //redimensionez zona
    const int page_size = getpagesize();
    const int shm_size = (argc - 1) * page_size;

    if(ftruncate(shm_fd, shm_size)) 
        return errno;

    //deschid zona pentru programul parinte
    void * shm_ptr = mmap(NULL, shm_size, PROT_READ, MAP_SHARED, shm_fd, 0);
    if(shm_ptr == MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name);
        return errno;
    }
    
    for(int i = 1; i < argc; i++)
    {
        int n = atoi(argv[i]);
        //pentru fiecare element => create child, write in mem, delete child
        pid_t pid = fork();
        if(pid < 0)
            return errno;
        else if(pid == 0)
        {
            int* child_shm_ptr = (int*)mmap(0, page_size, PROT_WRITE, MAP_SHARED, shm_fd, (i - 1) * page_size);
            writeCollatz(child_shm_ptr, n);
            return 0;
        }
        else if(pid > 0)
        {
            printf("Done parent %d, Me %d\n", getpid(), wait(NULL));
        }
    }
    
    int t = 0;
    int* v = (int*)shm_ptr;
    bool write = 0;
    int n = 0;

    while(t < shm_size)
    {
        bool x = write;
        if(v[t] == INT_MAX)
            write = !write;
        if(write != x && write == false){
            printf("\n");
            n++;
        }
        if(write && v[t] != INT_MAX)
            printf("%d ", v[t]);
        t++;
    }


    if(munmap(shm_ptr, shm_size) || shm_unlink(shm_name))
        return errno;
    
    printf("Done parent %d Me %d\n", getppid(), getpid());
    return 0;
}
