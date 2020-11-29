#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#include "buffer.h"
#include <stdlib.h>
// required for rand() library

using namespace std;

// The buffer
// The buffer wil be manipulated with two functions,
// insert_item() and remove_item(), which are called by
// the producer and consumer threads.
pthread_mutex_t mutex;
sem_t full;
sem_t empty;

int main(int argc, char *argv[])
{
	std::cout << "CS 433 Programming assignment 3" << std::endl;
	std::cout << "Author: Ezer Patlan and Cody Chadler" << std::endl;
	std::cout << "Date: 11/30/2020" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : The Producer and Consumer Problem" << std::endl;
	std::cout << "=======================================================" << std::endl;

	// arguments handler
	if (argc < 4 || argc > 4) 
	{
		std:: cout << "Usage: prog4 <sleeptime> <pthreadc> <cthread>" << std::endl;
		exit(1);
	}


	// 1. Get command line arguments argv[1], argv[2], argv[3]
	// First argument is the sleep time
	int sleeptime = atoi(argv[1]);
	// Second argument is the number of producer threads
	int pthreadc = atoi(argv[2]);
	// Third argument is the number of consumer threads
	int cthreadc = atoi(argv[3]);
	
	// 2. Initialize buffer
	pthread_t producer_threads[pthreadc];
	pthread_t consumer_threads[cthreadc];
	pthread_mutex_init(&mutex, NULL);
	
	// empty is initialized to the buffer size
	sem_init(&empty, 0, BUFFER_SIZE);
	// full is initialized to zero
	sem_init(&full, 0, 0);

	// 3. Create producer thread(s)
	for (int i = 0; i < pthreadc; i++)
	{
		pthread_create(&producer_threads[i], NULL, producer, NULL);
	}

	// 4. Create consumer tread(s)
	
	for (int i=0; i < pthreadc; i++)
	{
		pthread_create(&consumer_threads[i], NULL, consumer, NULL);
	}

	// 5. Sleep
	usleep(sleeptime);
	
	cout << "Threads completed! done..." << endl;

	// 6. Exit
	exit(0);

}
