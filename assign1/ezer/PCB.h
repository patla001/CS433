#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "ReadyQueue.h"

using namespace std;
// Remember to add comments to your code
// ...


//const int MAX_SIZE = 30;
//el_t Elem; // elem is the element stored
//typedef string el_t; // el_t is an alias for the data type
//const int TSIZE = 30; // this is the max number of elements

// enum class of process state
// A process (PCB) in ready queue should be in READY state
enum class ProcState {NEW, READY, RUNNING, WAITING, TERMINATED};
//enum class ProcState {NEW="NEW", READY="READY", RUNNING="RUNNING", WAITING="WAITING", TERMINATED="TERMINATED"};
// READY - adding values in the array
// RUNNING - removing values in the array
/*
Process control block(PCB) is a data structure representing a process in the system.
A process should have at least an ID and a state(i.e.NEW, READY, RUNNING, WAITING or TERMINATED).
It may also have other attributes, such as scheduling information (e.g. priority)
*/
class PCB   {
//private:
//	int key; // key is defined as the ID number and the counter.
//	string state; // state name: New, Ready, Running, Waiting, and Terminated
public:
    // The unique process ID
	unsigned int id;
    // The priority of a process valued between 1-50. Larger number represents higher priority
	unsigned int priority;
	// The current state of the process.
	// A process in the ReadyQueue should be in READY state
	ProcState state;
	//string state;

	// TODO: Add constructor and other necessary functions for the PCB class
	PCB();   // constructor to create a blank object.
	PCB(int, ProcState, int); // to create an initialized PCB object.
	//std::vector<PCB> table;
	friend ostream& operator<<(ostream&, const PCB&);
	//friend class ReadyQueue;
};

/*
An array(list) of all PCB elements in the system.
*/
//typedef vector<PCB> vt_pcb

const int MAX_SIZE = 30;
class PCBTable
{
private:
	//std::vector<PCB> table;
	//PCB table[MAX_SIZE];

public:
	PCB table[MAX_SIZE];
	PCBTable();
	//bool isEmpty();
	//bool isFull();
	//void add(PCB pcbPtr);
	void MakeTable(int);
	void displayPCBTable();
	friend class ReadyQueue;
};

// class PCBTable
// {
// public:
// 	vector<PCB> PCBTable_class_member;
//     vector<PCB>::iterator Iter;
// 	//PCBTable: PCBTable_class_member() {};
// 	PCBTable();
// 	void add_element(PCB);
// // private:
// // 	vector<PCB> vector_class_member;
// // 	vector<PCB>::iterator Iter;
// //
// // public:
// // 	PCBTable(): vector_class_member() {};
//
// };

// const int MAX_SIZE = 30;
//
// class PCBTable {
// 	// TODO: Add your implementation of the PCBTable
// //PCB table[TSIZE];
// // initialized the vector for the PCB Table
// //std::vector<PCB> table(TSIZE, PCB(-1,"NEW",-1));
// //private:
// 	//std::vector<PCB> table;
//
// public:
// 	std::vector<PCB> table;
// 	//PCB table[MAX_SIZE];
// 	// arraySize is the total size of the array.
// 	unsigned int arraySize;
// 	// constructor of PCBTable and the integer parameter assigns the total number of the array.
// 	PCBTable();
// 	//createTable();
// 	//PCB addTable(PCB element);
// 	//void displayTable();
// 	//PCBTable(int);
// 	//friend class ReadyQueue;
// };
