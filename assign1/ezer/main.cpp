// Remember to add comments to your code

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <chrono>
#include <random>
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

	}



	q1.displayQueue();


	for (int j=0; j < 2; j++)
	{
		cout << "remove the process with the highest priority from q1 and display q1." << endl;
		PCB pcbPtr;
		pcbPtr = q1.findMaximum();
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

	}

	q1.displayQueue();


	cout << "One by one remove the process with the highest priority from the queue q1" << endl;

	int sizeQueueQ1 = q1.rootSize();

	for (int i=0; i<sizeQueueQ1; i++)
	{


		int sizeQueue = q1.rootSize();

		if (sizeQueue == 1)
		{
			// deleting the last object and pointers.
			q1.~ReadyQueue();
			cout << "q1 is Empty: " <<  endl;
			break;

		} else {
			PCB pcbPtr;
			pcbPtr = q1.findMaximum();
			cout << "size queue: " << sizeQueue << endl;
			q1.displayQueue();

		}

	}
	q1.displayQueue();


	// TODO: Add your code for Test 2
	std::cout << "Performing Test 2" << std::endl;

	std::random_device rd;
	std::mt19937 mt_rand(rd());
	int totalIterations = 50;
	//int totalIterations = 30;

	// Create array containing 50 percent probability as index value e.g., 1 or 0
	int fiftyPercent[totalIterations];
	for (int i=0; i< totalIterations; i++)
	{

		fiftyPercent[i] = rand() % 2;

	}


	// randomly select 15 process from the PCB Table.
	numb_entries = 15;


	for (int i = 0; i < numb_entries; i++ )
	{
		PCB pcbPtr;
		pid = p1.table[i].id;
		priority = mt_rand() % 50;
		//cout << "PID: " << pid << ", Priority: " << priority << endl;
		q1.insertPCB(pid, priority);
		p1.table[i].priority=rand() % 50;
		p1.table[i].added = 0;
		p1.table[i].removed = 0;

	}
	PCBTable p2;

	p2 = p1;



	q1.displayQueue();
	p1.displayPCBTable();



	cout << "size Q: " << q1.rootSize() << endl;

	auto begin = std::chrono::high_resolution_clock::now();
	//int sizeQ = q1.rootSize();
	int countAdd = 0;
	int countDelete = 0;
	//int sizeQ = q1.rootSize();
	for (int i = 0; i < totalIterations; i++)
	{
		switch (fiftyPercent[i]) {
			case 0:
			{
				int sizeQ = q1.ReadyQueue::getSize();
				cout << "sizeQ+: " << sizeQ << endl;
				if (sizeQ !=0 )
				{
					countDelete++;
					//q1.displayQueue();
					PCB pcbPtr1;
					pcbPtr1 = q1.maxPriority();
					cout << "==============================" << endl;
					cout << "PCB ID = "<< pcbPtr1.id << ", Priority = " << pcbPtr1.priority;
					cout << ", removed " << countDelete << " times" << endl;
					cout << "==============================" << endl;
					if ( p1.table[pcbPtr1.id-1].priority == pcbPtr1.priority )
	 				{
						q1.displayQueue();
						PCB pcbPtr = q1.findMaximum();
	 					//p1.table[pcbPtr.id-1].state = ProcState::RUNNING;
	 					//p1.table[pcbPtr.id-1].removed = countDelete++;

						pcbPtr.state = ProcState::RUNNING;
						pcbPtr.removed = countDelete;


						p2.table[pcbPtr.id-1].id=pcbPtr.id;
						p2.table[pcbPtr.id-1].priority=pcbPtr.priority;
						p2.table[pcbPtr.id-1].state=ProcState::RUNNING;
						p2.table[pcbPtr.id-1].removed = countDelete;

						cout << "==============================" << endl;
						cout << "PCB ID = "<< pcbPtr.id << ", Priority = " << pcbPtr.priority;
						cout << ", removed " << countDelete << " times" << endl;
						cout << "==============================" << endl;
						//p1.table.push_back(pcbPtr);
						p1.table[pcbPtr.id-1] = pcbPtr;

						break;
	 				}
				}
			}
			case 1 :
			{
				//int sizeQ = q1.ReadyQueue::getSize();
				if (!p1.table.empty())
				{

					countAdd++;
					PCB pcbPtr;
					q1.displayQueue();
					int sizeQ = q1.rootSize();
					cout << "sizeQ-: " << sizeQ << endl;
					pcbPtr = p1.table.back();
					pcbPtr.priority = rand() % 50;
					pcbPtr.state = ProcState::READY;
					pcbPtr.removed = countAdd;
					q1.insertPCB(pcbPtr.id,pcbPtr.priority);
					cout << "==============================" << endl;
					cout << "PCB ID = "<< pcbPtr.id << ", Priority = " << pcbPtr.priority;
					cout << ", added " << countAdd << " times" << endl;
					cout << "==============================" << endl;


					p2.table[pcbPtr.id-1].id=pcbPtr.id;
					p2.table[pcbPtr.id-1].priority=pcbPtr.priority;
					p2.table[pcbPtr.id-1].state=ProcState::READY;
					p2.table[pcbPtr.id-1].added = countAdd;


					p1.table.pop_back();

					break;
				}
			}
		}
	}


	p1.displayPCBTable();
	p2.displayPCBTable();


	auto end = std::chrono::high_resolution_clock::now();
	double elapsedTime = std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count();

	std::cout << "Test 2 time: " << elapsedTime / 1000 << " ms.\n";


}
