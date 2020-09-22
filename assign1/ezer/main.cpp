// Remember to add comments to your code

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "ReadyQueue.h"

using namespace std;

int main(int argc, char* argv[]) {
	//Print basic information about the program
	std::cout << "CS 433 Programming assignment 1" << std::endl;
	std::cout << "Author: Ezer Patlan and Cody Chandler" << std::endl;
	std::cout << "Date: 09/23/2020" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : Program to implement a priority ready queue of processes" << std::endl;
	std::cout << "=================================" << std::endl;

	// TODO: Add your code for Test 1
	std::cout << "Performing Test 1" << std::endl;
	//Generating PCB Table with their PCB Object
	PCBTable p1;
	int numb_entries = 30;
	p1.MakeTable(numb_entries);

	ReadyQueue q1;

	cout << "add processes 15, 6, 23, 29, 8 to q1. Display the content of q1." << endl;
	int pid;
	int priority;

	int arrayInput1[5] = {15,6,23,29,8};
	for (int i=0; i < 5; i++)
	{
		PCB pcbPtr;
		pid = arrayInput1[i];
		priority = arrayInput1[i];
		pcbPtr = q1.insertPCB(pid, priority);
		p1.table[pcbPtr.id-1] = pcbPtr;
	}
	q1.displayQueue();


	for (int j=0; j < 2; j++)
	{
		cout << "remove the process with the hiighest priority from q1 and display q1." << endl;
		PCB pcbPtr;
		pcbPtr = q1.findMaximum();
		p1.table[pcbPtr.id - 1] = pcbPtr;
		q1.displayQueue();
	}


	cout << "Insert processes 3, 17, 22, 12, 19 to q1. Display the content of q1." << endl;

	int arrayInput2[5] = {3,17,22,12,19};
	for (int i=0; i < 5; i++)
	{
		PCB pcbPtr;
		pid = arrayInput2[i];
		priority = arrayInput2[i];
		pcbPtr = q1.insertPCB(pid, priority);
		p1.table[pcbPtr.id-1] = pcbPtr;
	}

	q1.displayQueue();

	cout << "One by one remove the process with the highest priority from the queue q1" << endl;

	int sizeQueueQ1 = q1.ReadyQueue::getSize();
	//cout << "size of queue: " << q1.ReadyQueue::getSize() - 1 << endl;
	for (int i=0; i<sizeQueueQ1; i++)
	{
		//cout << "size of queue: " << q1.ReadyQueue::getSize() - 1<< endl;
		int sizeQueue = q1.ReadyQueue::getSize() - 1;
		if (sizeQueue == 0)
		{
			cout << "q1 is Empty" << endl;
			break;

		} else {
			PCB pcbPtr;
			pcbPtr = q1.findMaximum();
			p1.table[pcbPtr.id - 1] = pcbPtr;
			q1.displayQueue();
		}


	}

	p1.displayPCBTable();
	// TODO: Add your code for Test 2
	std::cout << "Performing Test 2" << std::endl;

}
