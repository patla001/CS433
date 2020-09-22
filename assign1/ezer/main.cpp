// Remember to add comments to your code

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "ReadyQueue.h"

using namespace std;

int main(int argc, char* argv[]) {
	//Print basic information about the program
	std::cout << "CS 433 Programming assignment 1" << std::endl;
	std::cout << "Author: Ezer Patlan and Kothandaraman Alliyalamangalam" << std::endl;
	std::cout << "Date: 09/23/2020" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : Program to implement a priority ready queue of processes" << std::endl;
	std::cout << "=================================" << std::endl;

	// TODO: Add your code for Test 1
	std::cout << "Performing Test 1" << std::endl;

	//int arraySize = 30;
	// // initialize PCBTable
	// std::vector<PCB> T;
	// T.reserve(arraySize);
	//
	// string state = "Ready";
	//
	// for (int i = 0; i < arraySize; i++){
	// 	T.push_back(PCB(i,state,1));
	// }
	// std::cout << "PID" << "   " << "ProcState" << "   " << "Priority" << std::endl;
	// for (int j = 0; j < arraySize; j++) {
	// 	std::cout << T[j].id << "\t" << T[j].state << "\t\t" << T[j].priority << std::endl;
	// }

	ReadyQueue q1;
	//-------------------------------------------
	//PCBTable q2;
	//ReadyQueue q1;
	//string state = "Ready";
	//PCB x;
	//std::vector<PCB> q2;

	//q2.push_back(x);
	//q2.resize(x,30);

	cout << "add processes 15, 6, 23, 29, 8 to q1. Display the content of q1." << endl;
	int pid;
	int priority;
	//int arrayInput[5];
	int arrayInput[5] = {15,6,23,29,8};
	for (int i=0; i < 5; i++)
	{
		pid = arrayInput[i];
		priority = arrayInput[i];
		q1.insertPCB(pid, priority);
	}
	q1.displayQueue();

	cout << "remove the process with the hiighest priority from q1 and display q1." << endl;

	q1.findMaximum();
	q1.displayQueue();

	cout << "remove the process with the hiighest priority from q1 and display q1." << endl;

	q1.findMaximum();
	q1.displayQueue();

	//cout << "Highest Priority: " << maxNumber->Elem.priority << endl;

	//q1.addArrayList(q1,15,15);
	//q1.addArrayList(q1,6,6);
	//q1.addArrayList(q1,23,23);
	//q1.addArrayList(q1,29,29);
	//q1.displayQueue();

	// std::cout << "Size: " << q1.getSize() << std::endl;
	//--------------------------------------------------
	//T.reserve(30);
	// T = PCBTable();
	// std::cout << "PID" << "   " << "ProcState" << "   " << "Priority" << std::endl;
	// for (int j = 0; j < arraySize; j++) {
	// 	std::cout << T[j].id << "\t" << T[j].state << "\t\t" << T[j].priority << std::endl;
	// }
	//std::cout << "PCBTable Size: " << X.front() << std::endl;
	// for (int i = 0; i < arraySize; i++)
	// {
	// 	X = PCB();
	// 	//T.add(X);
	// }



	// TODO: Add your code for Test 2
	std::cout << "Performing Test 2" << std::endl;
}
