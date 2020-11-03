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
		void displayAll();
		void addFront(PCB);
		void addRear(PCB);
		void deleteFront(PCB&);
		void deleteRear(PCB&);
		void moveTo(int, Node*&);
		void deleteIth(int, PCB&);
		void insertIth(int, PCB);
		void turnAroundTime();
		float avgTAT();
		void waitingTime();
		float avgWaitTime();
		/*void MergeSortByBurst(Node**);
		void FrontBackSplit(Node*, Node**, Node**);
		Node* SortByBurst(Node*, Node *);*/
		llist(const llist&);
		llist& operator=(const llist&);
};

