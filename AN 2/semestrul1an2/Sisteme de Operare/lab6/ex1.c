#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void inplace_reverse(char * str)
{
  if (str)
  {
    char * end = str + strlen(str) - 1;

    // swap the values in the two given variables
    // XXX: fails when a and b refer to same memory location
#   define XOR_SWAP(a,b) do\
    {\
      a ^= b;\
      b ^= a;\
      a ^= b;\
    } while (0)

    // walk inwards from both ends of the string, 
    // swapping until we get to the middle
    while (str < end)
    {
      XOR_SWAP(*str, *end);
      str++;
      end--;
    }
#   undef XOR_SWAP
  }
}

void* thread_routine(char* arg)
{
	inplace_reverse(arg);
	return arg;
}

int main(int argc, char**argv)
{
	char* ret;
	pthread_t thread;
	pthread_create(&thread, NULL, thread_routine, argv[1]);
	pthread_join(thread, &ret);
	printf("%s", ret);
	return 0;
}


