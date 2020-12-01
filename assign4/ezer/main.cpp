#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>
//#include "buffer.h"

// required for rand() library

using namespace std;

// The buffer
// The buffer wil be manipulated with two functions,
// insert_item() and remove_item(), which are called by
// the producer and consumer threads.
pthread_mutex_t mutex;
sem_t full;
sem_t empty;
int count = 0;
const int BUFFER_SIZE = 5;
int RAND_RANGE = 100 + 1;
vector<int> buffer;

void *producer(void *param)
{       
  while (true)
  {
      // sleep for a random period of time	   	
      usleep(rand() % 1000000);
      // generate a random number between 1 - 100
      int item = rand() % RAND_RANGE + 1;    
      // obtained the semaphore and wait until is not full
      sem_wait(&empty);
      // make sure the mutex access to the critical section
      pthread_mutex_lock(&mutex);
	
	if (count != BUFFER_SIZE)
	{
		buffer.push_back(item);
		cout << "item " << item << " inserted by a producer." << endl;
		count++;

		cout << "The current buffer vector is [ ";
                for (unsigned int i = 0; i <buffer.size(); i++)
                {
                        cout << buffer[i] << " ";
                }
                cout << "]" << endl;

	}
      // critical section ...
	cout << endl;
      // unlock the mutex
      pthread_mutex_unlock(&mutex);
      // release the semaphore
      sem_post(&full);
    }

        
}

void *consumer(void *param)
{
  while (true)
  {
	
      // sleep for a random period of time
      usleep(rand() % 1000000);
      // obtained the semaphore and wait until is not full                                                                                                                                  
      sem_wait(&full);
      // make sure the mutex access to the critical section                                                                                                                                 
      pthread_mutex_lock(&mutex);

      // critical section ...                                                                                                                                                               	
	if (count != 0)
	{
		int back = buffer.size();
		int item = buffer[back-1];
		buffer.erase(buffer.begin()+back-1);
		cout << "item " << item << " removed by a consumer." << endl;
		count--;

		cout << "The current buffer vector is [ ";
		for (unsigned int i = 0; i <buffer.size(); i++)
		{
			cout << buffer[i] << " ";
		}
		cout << "]" << endl;
	}											     
      
      cout << endl;
      // unlock the mutex                                                                                                                                                                   
      pthread_mutex_unlock(&mutex);
      // release the semaphore                                                                                                                                                              
      sem_post(&empty);
    }
}




int main(int argc, char *argv[])
{
	std::cout << "CS 433 Programming assignment 4" << std::endl;
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
       

        srand(time(NULL));

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
	usleep(sleeptime*1000000);
	//usleep(sleeptime*300000);
	//usleep(sleeptime % 5000000);
	
	cout << "Threads completed! done..." << endl;

	// 6. Exit
	exit(0);

}
