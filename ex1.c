#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#define MAX_RESOURCES 5
int available_resources = MAX_RESOURCES;
pthread_mutex_t mtx;

int decrease_count(int count)
{
	if(available_resources < count)
		return -1;
	else
	{
		pthread_mutex_lock(&mtx);
		available_resources -= count;
		pthread_mutex_unlock(&mtx);
	}
	return 0;
}

int increase_count(int count)
{
	pthread_mutex_lock(&mtx);
	available_resources += count;
	pthread_mutex_unlock(&mtx);
	return 0;
}


void* resource_test(void* arg)
{
	//int* ptr_a = (int*)(arg);
	//int a = (*ptr_a);
	int a = *(int*)(arg);
	if(!decrease_count(a))
	{
		printf("Got %d resources %d remaining\n", a, available_resources);
		increase_count(a);
		printf("Released %d resources %d remaining\n", a, available_resources);
	}
	else{
		printf("Not enough resources for thread\n");
	}
}

int main()
{
	pthread_t threads[10];
	pthread_mutex_init(&mtx, NULL);
	printf("MAX_RESOURCES = %d\n", MAX_RESOURCES);
	int resource_list[] = {1,2,10,4,5};
	
	for(int i = 0; i < 5; i++)
	{
		pthread_create(&threads[i], NULL, resource_test, &resource_list[i]);
	}
	
	for(int i = 0; i < 5; i++)
		pthread_join(threads[i], NULL);

	pthread_mutex_destroy(&mtx);
	return 0;
}




