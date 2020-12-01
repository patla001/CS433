#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>

using namespace std;

// initialization of the mutex
pthread_mutex_t mutex;
// initialization of the semaphores
sem_t full;
sem_t empty;
// the count to track the number
// of interger inside the vector
int count = 0;
// the maximum range of the vector
const int BUFFER_SIZE = 5;
// the range of random values
int RAND_RANGE = 100 + 1;
// initialize the vector
vector<int> buffer;


// PURPOSE: Produces a random value on the item variable
// then,  performs a wait of 1 second using a semaphore and
// locks the signal using mutex lock. Inserts the item into the 
// vector, then unlocks the semaphore and the pthread.
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
      // the if statement insert the item
      // by adding the random value to the vector
	if (count != BUFFER_SIZE)
	{
	       // adding the random integer to the vector
		buffer.push_back(item);
		cout << "item " << item << " inserted by a producer." << endl;
		// increment the count
                count++;
                // display the vector to see the status of the inserted value
		cout << "The current buffer vector is [ ";
                for (unsigned int i = 0; i <buffer.size(); i++)
                {
		       // print the vector 
                        cout << buffer[i] << " ";
                }
                cout << "]" << endl;

	} // end of if statement 
      
	cout << endl;
      // unlock the mutex
      pthread_mutex_unlock(&mutex);
      // release the semaphore
      sem_post(&full);
  }// end of while loop

        
}// end of consumer function


// PURPOSE: Extracts the random value from the item vector                                                                  
// then,  performs a wait of 1 second using a semaphore and                                                                 
// locks the signal using mutex lock. Deletes the item from the                                                             
// vector, then unlocks the semaphore and the pthread.           
void *consumer(void *param)
{
  while (true)
  {
	
      // sleep for a random period of time
      // it sleeps less than a second.
      usleep(rand() % 1000000);
      // obtained the semaphore and wait until is not full                                                                  
      sem_wait(&full);
      // make sure the mutex access to the critical section                                                                 
      pthread_mutex_lock(&mutex);

      // critical section ...                                                                                                                                                               	
	if (count != 0)
	{
	        // extract the index value of the vector
		int back = buffer.size();
		// extract the item value of the vector
		int item = buffer[back-1];
		// delete the item from the vector
		buffer.erase(buffer.begin()+back-1);
		cout << "item " << item << " removed by a consumer." << endl;
		// decrement the counter
		count--;
		// display the status of the vector
		cout << "The current buffer vector is [ ";
		for (unsigned int i = 0; i <buffer.size(); i++)
		{
			cout << buffer[i] << " ";
		} // end of for loop
		cout << "]" << endl;
	} // end of if statement
      
      cout << endl;
      // unlock the mutex                                                                                                   
      pthread_mutex_unlock(&mutex);
      // release the semaphore                                                                                              
      sem_post(&empty);
  }// end of while loop
}// end of consumer function




int main(int argc, char *argv[])
{
	std::cout << "CS 433 Programming assignment 4" << std::endl;
	std::cout << "Author: Ezer Patlan and Cody Chadler" << std::endl;
	std::cout << "Date: 11/30/2020" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : The Producer and Consumer Problem" << std::endl;
	std::cout << "=======================================================" << std::endl;

	// arguments handler
	// only prints if the arguments is less or more then four inputs
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
	       // create the pthread for the producer 
		pthread_create(&producer_threads[i], NULL, producer, NULL);
	}

	// 4. Create consumer tread(s)
	
	for (int i=0; i < pthreadc; i++)
	{
	        // create the pthread for the consumer
		pthread_create(&consumer_threads[i], NULL, consumer, NULL);
	}

	// 5. Sleep
	usleep(sleeptime * 1000000);
	
	
	cout << "Threads completed! done..." << endl;

	// 6. Exit
	exit(0);

}
