#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "buffer.h"

using namespace std;
buffer_item bufferItem[BUFFER_SIZE];

int i = 0;
int count = 0;

// semaphores needed for syncronization

// mutex lock
pthread_mutex_t tmutex;

// counting semaphore
sem_t tfull;
// counting semaphore
sem_t tempty;



int insert_item(buffer_item item)
{
	if (count == BUFFER_SIZE)
	{
		// insert item into buffer
		bufferItem[i] = item;
		i = (i + 1) % BUFFER_SIZE;
		count++;
		// return 0 if succesful, otherwise
		return 0;
	}

	// return -1 indicating an error condition
	return -1;
}

int remove_item(buffer_item *item) 
{
	// remove an object from buffer
	if (count == 0)
	{
		// placing it in item
		*item = bufferItem[i];
		i = (i + 1) % BUFFER_SIZE;
		count--;
		// return 0 if successful, otherwise
		return 0;
	}
	// return -1 indicating an error condition
	return -1;
}

void *producer(void *param)
{
	buffer_item item;
	//lock.acquire();
	
	while (count == BUFFER_SIZE)
	{
		//wait(&space, &lock)
		// obtained the semaphore and wait until is not full
		sem_wait(&tempty);
		// make sure the mutex access to the critical section
		// lock.acquire()
		pthread_mutex_lock(&tmutex);

		// change between sleeping and producing
		// sleep for a random period of time
		usleep(rand()%1000000);
		// generate a random number
		item = rand();

		// critical section ...
		if (insert_item(item))
		{
			cout << "Error: cannot produce item" << endl;
			//fprintf("error: cannot produce item");
		} else {
			i = (i + 1) % BUFFER_SIZE;
			printf("producer produced %d\n", item);
		}
		// unlock the mutex
		pthread_mutex_unlock(&tmutex);
		// release the semaphore
		sem_post(&tfull);
		// increment the counter
		count++;
	}
}

void *consumer(void *param)
{
	buffer_item item;

	while (true) 
	{

		// obtained the semaphore and wait until is not full
		sem_wait(&tfull);

		// make sure the mutex access to the critical section
		pthread_mutex_lock(&tmutex);

		// sleep for a random period of time
		usleep(rand()%1000000);
		

		// critical section ...
		if (remove_item(&item))
		{
			cout << "Error: cannot consume an item" << endl;
			//fprintf("error: cannot consume");
		} else {
			printf("consumer consumed %d\n", item);
		}

		// unlock the mutex
		pthread_mutex_unlock(&tmutex);
		// release the semaphore
		// decrease until empty
		sem_post(&tempty);
	}
}

