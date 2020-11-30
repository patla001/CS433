#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
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
int in = 0;
int out = 0;
// pthread attribute
//pthread_attr_t attr;
const int BUFFER_SIZE = 5;
int RAND_RANGE = 100 + 1;
int bufferItem[BUFFER_SIZE];
void display();	

void *producer(void *param)
{       
  //buffer_item item;
  //int item;
	//lock.acquire();
        
  //while (count == BUFFER_SIZE)
  while (true)
  {
      //sleep(rand() % 3); 	   
      usleep(rand() % 1000000);
      int item = rand() % RAND_RANGE + 1;    
      //wait(&space, &lock)
      // obtained the semaphore and wait until is not full
      sem_wait(&empty);
      // make sure the mutex access to the critical section
      // lock.acquire()
      pthread_mutex_lock(&mutex);
                
      // change between sleeping and producing
      // sleep for a random period of time
      //usleep(rand()%1000000);
      // generate a random number
      //item = rand();
        
	
       cout << "producer random: " << item << endl;

	bufferItem[in] = item;
	printf("Producer %d: Insert Item %d at %d\n", in,bufferItem[in],in);
	in = ( in + 1) % BUFFER_SIZE; 

	cout << "The current content of the buffer is [ ";
	for (int i = 0; i < in; i++)
	{
		cout << bufferItem[i] << " ";
		
	}
	cout << "]" << endl;
      // critical section ...
/*       if (insert_item(item) == 0)
	{       
	  cout << "Error: cannot produce item" << endl;
	  //fprintf("error: cannot produce item");
	  } else {
		std::cout << "item " << item << " inserted by a producer." << std::endl;
		display();
	} 
*/
/*        if (insert_item(item) == 0  ) 
	{
	    std::cout << "item " << item << " inserted by a producer." << std::endl;
	     //printf("producer produced %d\n", item);
	     display();
	} else {
	    cout << "Error: cannot produce item" << endl;
	}*/
	cout << endl;
      // unlock the mutex
      pthread_mutex_unlock(&mutex);
      // release the semaphore
      sem_post(&full);
      // increment the counter
      //      count++;
    }

        
  //return 0;
}

void *consumer(void *param)
{
  //buffer_item item;
	//int item;
  while (true)
  {
      //sleep(rand() % 3);
      usleep(rand() % 1000000);
      // obtained the semaphore and wait until is not full                                                                                                                                  
      sem_wait(&full);

      // make sure the mutex access to the critical section                                                                                                                                 
      pthread_mutex_lock(&mutex);

      // sleep for a random period of time                                                                                                                                                  
      //usleep(rand()%1000000);


      // critical section ...                                                                                                                                                               	
     	 
      //cout << "consumer random: " << item << endl;

	int item = bufferItem[out];
	cout << "consumer random: " << item << endl;
	printf("Consumer %d: Remove Item %d from %d\n",out, item, out);
	out = (out + 1) % BUFFER_SIZE;	
	cout << "The current content of the buffer is [ ";
        for (int i = 0; i < out; i++)
        {
                cout << bufferItem[i] << " ";

        }
        cout << "]" << endl;
													     
 /*     if (remove_item(&item) == 0  ) 
      {
	     //printf("consumer consumed %d\n", item);
	     std::cout << "item " << item << " removed by a consumer.  " << std::endl;
	     display();
      } else {
	     cout << "Error: cannot consume an item" << endl;
      }
*/
      cout << endl;
      // unlock the mutex                                                                                                                                                                   
      pthread_mutex_unlock(&mutex);
      // release the semaphore                                                                                                                                                              
      // decrease until empty                                                                                                                                                               
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
        
	// pthread attribute variable
	//pthread_attr_init(&attr);
	
	
	// empty is initialized to the buffer size
	sem_init(&empty, 0, BUFFER_SIZE);
	// full is initialized to zero
	sem_init(&full, 0, 0);

	// 3. Create producer thread(s)
	for (int i = 0; i < pthreadc; i++)
	{
		//pthread_create(&producer_threads[i], NULL, producer, &bufferItem[i]);
		pthread_create(&producer_threads[i], NULL, producer, NULL);
	}

	// 4. Create consumer tread(s)
	
	for (int i=0; i < pthreadc; i++)
	{
		//pthread_create(&consumer_threads[i], NULL, consumer, &bufferItem[i]);
		pthread_create(&consumer_threads[i], NULL, consumer, NULL);
	}

	// 5. Sleep
	sleep(sleeptime);
	//usleep(sleeptime*300000);
	//usleep(sleeptime % 5000000);
	
	cout << "Threads completed! done..." << endl;

	// 6. Exit
	exit(0);

}
