#pragma once
#include "PCB.h"

struct Node
{
	PCB Elem;
	Node *Next;
};

class llist
{
	protected:
		Node *Front;
		Node *Rear;
		int Count;

	public:
		class Underflow {};
		class OutOfRange {};

		llist();
		~llist();
		bool isEmpty();
		void importData(llist&);
		void displayAll();
		void addFront(PCB);
		void addRear(PCB);
		void deleteFront(PCB&);
		void deleteRear(PCB&);
		void moveTo(int, Node*&);
		void deleteIth(int, PCB&);
		void insertIth(int, PCB);
		void turnAroundTime();
		void sortB();
		void bubbleSortB(Node**, int);
		void sortPrio();
		void bubbleSortPrio(Node**, int);
		int numNodes();
		float avgTAT();
		void waitingTime();
		float avgWaitTime();
		Node* swap(Node*, Node*);
		llist(const llist&);
		llist& operator=(const llist&);
};

