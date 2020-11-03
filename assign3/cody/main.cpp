//linked list where each node is a PCB and the PCB contains the process ID/burst/arrival/priority/tat/wt
#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "CS 433 Programming assignment 3" << std::endl;
	cout << "Author: Ezer Patlan and Cody Chandler" << std::endl;
	cout << "Date: 11/04/2020" << std::endl;
	cout << "Course: CS433 (Operating Systems)" << std::endl;
	cout << "Description : read a text file and apply FCFS method" << std::endl;
	cout << "====================================================" << std::endl;

	/*string inputFile;
	ifstream fin; 
	string name;
	string line;
	int id = 1;
	int priority = 0;
	int burst = 0;
	int tat = 0;
	int wt = 0;*/
	llist L1;
	
	/*cout << "Please enter file name: ";
	getline(cin, inputFile);
	fin.open(inputFile.data());
	if (fin)
	{
		while (fin >> name >> priority >> burst)
		{ 
			PCB X(name,id,priority,burst, tat, wt);
			L1.addRear(X); 
			id++;
		}
	} 
	else
	{
		cout << "file not found" << endl;
	}*/
	
	L1.importData(L1); 
	
	L1.turnAroundTime();
	float fcfsavgtat = L1.avgTAT();
	L1.waitingTime();
	float fcfsavgwait = L1.avgWaitTime();
	L1.displayAll();
	cout << "Average Turnaround Time for FCFS is: " << fcfsavgtat << endl;
	cout << "Average Wait Time for FCFS is: " << fcfsavgwait << endl << endl;
	
	L1.sortB();
	L1.turnAroundTime();
	float SJFavgtat = L1.avgTAT();
	L1.waitingTime();
	float SJFavgwait = L1.avgWaitTime();
	L1.displayAll();
	cout << "Average Turnaround Time for SJF is: " << SJFavgtat << endl;
	cout << "Average Wait Time for SJF is: " << SJFavgwait << endl << endl;

	L1.sortPrio();
	L1.turnAroundTime();
	float PrioAvgTAT = L1.avgTAT();
	L1.waitingTime();
	float PrioAvgWait = L1.avgWaitTime();
	L1.displayAll();
	cout << "Average Turnaround Time for priority scheduling  is: " << PrioAvgTAT << endl;
	cout << "Average Wait Time for priority scheduling is: " << PrioAvgWait << endl << endl;

	//fin.close(); 
	return 0;
}