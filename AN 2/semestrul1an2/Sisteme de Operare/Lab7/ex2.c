#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

sem_t sem;
pthread_mutex_t mtx;

#define NTHRS 5
int S = NTHRS;
int ajunse_la_bariera = 0;

void barrier_point()
{
	pthread_mutex_lock(&mtx);
	ajunse_la_bariera++;
	pthread_mutex_unlock(&mtx);
	
	if(ajunse_la_bariera >= S - 1)
	{
		sem_post(&sem);
	}
	
	sem_wait(&sem);
	sem_post(&sem);
	
}

void* tfun(void* v)
{
	int* tid = (int*)v;
	printf("%d reached the barrier\n", *tid);
	barrier_point();
	printf("%d passed the barrier\n", *tid);
	free(tid);
	return NULL;
}


int main()
{
	sem_init(&sem, 0, -4);
	pthread_mutex_init(&mtx, NULL);
	int thread_nrs[] = {1,2,3,4,5};
	pthread_t threads[10];
	
	for(int i = 0; i < 5; i++)
	{
		int* v = malloc(sizeof(int));
		(*v) = thread_nrs[i];
		pthread_create(&threads[i], NULL, tfun, v);	
	}
	
	for(int i = 0; i < 5; i++)
		pthread_join(threads[i], NULL);
	
	sem_destroy(&sem);
	pthread_mutex_destroy(&mtx);
	return 0;
}








