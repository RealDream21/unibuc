#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int nargs, char** args)
{
    //open first file + get info
    struct stat stat_file1;
    int fd_file1 = open(args[1], O_RDONLY);
    if(fd_file1 < 0 || fstat(fd_file1, &stat_file1))
    {
        perror("First file didn't open corectly");
        return errno;
    }

    //open/create second file with perms
    int fd_file2 = open(args[2], O_CREAT | O_WRONLY, stat_file1.st_mode);
    if(fd_file2 < 0)
    {
        perror("Second file didn't open corectly");
        return errno;
    }

    //start copying data
    int toCopy = stat_file1.st_size;
    int totalCopied = 0;
    while(totalCopied < toCopy)
    {
        char* buf = (char*)malloc(toCopy);
        int actualRead = read(fd_file1, buf, toCopy);
        int written = 0;
        while(written < actualRead)
        {
            written += write(fd_file2, buf, toCopy);
        }
        totalCopied += written;
        printf("Written %d byes out of %d bytes\n", totalCopied, toCopy);
        free(buf);
    }
    
    if(close(fd_file1))
    {
        perror("Error closing file1");
        return errno;
    }
    if(close(fd_file2))
    {
        perror("Error closing file2");
        return errno;    
    }

    return 0;
}
