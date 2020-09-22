// Remember to add comments to your code
// ...

#pragma once

#include "PCB.h"


// tree element type is int for now
typedef PCB elem_t;   // elem_t is hidden from the client

// definition of what a Vertex is - also hidden from the client
struct Vertex
{
  Vertex *Up;  // points to the parent node
  Vertex *Left;
  elem_t  Elem;
  Vertex *Right;
  int Height;  // for EC
  int Balance;  // for EC
};

/**
 * ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue here uch that the process with the highest priority
 * can be selected next.
 */
class ReadyQueue : public PCB, public PCBTable {
//class ReadyQueue: public PCB {
//class ReadyQueue {
//private:
	//std::vector<PCB> table;

public:
	// TODO: Implement the required functions. Add necessary member fields and functions
	// You may use different parameter signatures from the example below

	int count;
	Vertex *Root; //  Root which is a pointer to the root vertex

	//const int TSIZE = 30;
	//PCBTable();

	PCB queueTable[MAX_SIZE];
	ReadyQueue();
	~ReadyQueue();
	//int hash(int); // hash function
	// add a PCB representing a process into the ready queue.

	void addArrayList(elem_t pcbPtr, int, int);

    void insertPCB(int, int);

	void dtraverse(Vertex *V);
	
    void displayElements(Vertex *V);
    void findMaxNode(Vertex *V);
    void findMaximum();
	void add(PCB E);
	void deleteElem(elem_t E);
	void remove(Vertex *V, Vertex *P);
	elem_t findMax(Vertex *V);
	int max(int a, int b);
	int height(Vertex *V);
	void climbUp(Vertex *V);
	void singleLeftRotate(Vertex *Parent);
	void singleRightRotate(Vertex *Parent);
	void doubleLeftRotate(Vertex *V);
	void doubleRightRotate(Vertex *V);
	void printTree(Vertex *V, string indent, bool last);
	void showTree();
	void fixIt(Vertex *V);

	//int partition(ReadyQueue* table, int, int);

	//void quicksort(ReadyQueue* table, int, int);

	// remove and return the PCB with the highest priority from the queue
	//PCB* removeHighest();

	// Returns the number of elements in the queue.
	int getSize();

	// Prints the queue contents to standard output.
	void displayQueue();
	//friend class PCB;
	//friend class PCBTable;

};
