#include "llist.h"
#include <iostream>
#include <iomanip>
using namespace std;


llist::llist()
{
	Front = NULL;
	Rear = NULL;
	Count = 0;
}


llist::~llist()
{ 
	PCB x;
	while (!isEmpty())
	{
		deleteFront(x);
	}
}

bool llist::isEmpty()
{
	if (Count == 0 && Front == NULL && Rear == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
} 

void llist::displayAll()
{
	cout << "[Name]" << setw(6) << "[ID]" << setw(14) << "[Priority]" << setw(10) << "[Burst]" << setw(20) << "[Turnaround Time]\t" << "[Wait Time]" << endl;
	cout << "-------------------------------------------------------------------" << endl; 

	if (isEmpty())
	{
		cout << "There are no processes to display!" << endl; 
	}
	else
	{ 
		Node *nodePtr;
		nodePtr = Front;
		for (int i = 0; i < Count; i++)
		{
			cout << nodePtr->Elem.name << setw(8) << nodePtr->Elem.id << setw(11) << nodePtr->Elem.priority << setw(13) << nodePtr->Elem.burst;
			cout << setw(12) << nodePtr->Elem.TA_Time << setw(16) << nodePtr->Elem.W_Time << endl;
			nodePtr = nodePtr->Next;
		}
		
		
	}
} 

void llist::addRear(PCB NewNum)
{
	Node *NN;
	NN = new Node;
	NN->Elem = NewNum;
	NN->Next = NULL;
	if (Front == NULL) //special case for 0 items in the list
	{
		Front = NN;
		Rear = NN;
		Count++;
	}
	else
	{ 
		Rear->Next = NN;
		Rear = Rear->Next;
		Count++;
	}
}

void llist::addFront(PCB NewNum)
{
	Node *NN;
	NN = new Node;
	NN->Elem = NewNum;

	if (Front == NULL)
	{
		Front = NN;
		Rear = NN;
		Count++;
	}
	else
	{
		NN->Next = Front;
		Front = NN;
		Count++;
	}
} 

void llist::deleteFront(PCB& OldNum)
{
	if (isEmpty())
	{
		throw Underflow();
	}
	else if (Count == 1)
	{
		OldNum = Front->Elem;
		delete Front;
		Front = Rear = NULL;
		Count--;
	}
	else
	{
		OldNum = Front->Elem;
		Node *tempNode;
		tempNode = Front->Next;
		delete Front;
		Front = tempNode;
		Count--;
	}
}

void llist::deleteRear(PCB& OldNum)
{
	Node *P;
	if (isEmpty())
	{
		throw Underflow();
	}
	else if (Count == 1)
	{
		OldNum = Rear->Elem;
		delete Rear;
		Front = Rear = NULL;
		Count--;
	}
	else
	{
		P = Front;
		OldNum = Rear->Elem;
		while (P->Next != Rear)
		{
			P = P->Next;
		}
		delete Rear;
		Rear = P;
		Rear->Next = NULL;
		Count--;
	}
} 

void llist::moveTo(int J, Node*& temp)
{
	temp = Front;
	for (int i = 1; i <= J-1; i++)
	{
		temp = temp->Next;
	}
} 

void llist::deleteIth(int I, PCB& OldNum)
{
	Node *P;
	Node *Q;

	if (I > Count || I < 1)
	{
		throw OutOfRange();
	}
	else if (I == 1)
	{
		deleteFront(OldNum);
	}
	else if (I == Count)
	{
		deleteRear(OldNum);
	}
	else
	{
		moveTo(I, P);
		moveTo(I - 1, Q);
		Q->Next = P->Next;
		OldNum = P->Elem;
		delete P;
		Count--;
	}
}

void llist::insertIth(int I, PCB newNum)
{
	Node *P;
	Node *Q;

	if (I > Count + 1 || I < 1)
	{
		throw OutOfRange();
	}
	else if (I == 1)
	{
		addFront(newNum);
	}
	else if (I == Count+1)
	{
		addRear(newNum);
	}
	else
	{
		Node *NN;
		NN = new Node;
		NN->Elem = newNum;

		moveTo(I, P);
		moveTo(I - 1, Q);

		NN->Next = P;
		Q->Next = NN;
		Count++;
	}
}  

void llist::turnAroundTime()
{
	Node *P;
	int tatCurr = 0;
	int tatPrev = 0;
	int time = 0;
	P = Front;

	if (isEmpty())
	{ 
		cout << "error";
		//throw Underflow();
	}
	else
	{
		while (P != NULL)
		{
			if (P->Elem.id == 1)
			{
				tatCurr = P->Elem.burst;
				tatPrev = tatCurr;
				P->Elem.TA_Time = tatCurr;
			}
			else
			{
				tatCurr = P->Elem.burst;
				time = tatCurr + tatPrev;
				tatPrev = time;
				P->Elem.TA_Time = time;
			}
			P = P->Next;
		}
	}
} 

float llist::avgTAT()
{
	Node *P;
	P = Front;
	int timeCounter = 0;
	float avg = 0;
	int sum = 0;

	if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		while (P != NULL)
		{
			sum += P->Elem.TA_Time;
			timeCounter++;
			P = P->Next;
		}
	}
	avg = (double)sum / timeCounter;
	return avg;
} 

void llist::waitingTime()
{
	Node *P;
	P = Front; 
	int TATime, WTime, Tburst;

	if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		while (P != NULL)
		{
			Tburst = P->Elem.burst;
			TATime = P->Elem.TA_Time;
			WTime = TATime - Tburst;
			P->Elem.W_Time = WTime;
			P = P->Next;
		}
	}
} 

float llist::avgWaitTime()
{
	Node *P;
	P = Front;
	float sum = 0;
	float avg;
	int countTime = 0;

	if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		while (P != NULL)
		{
			sum += P->Elem.W_Time;
			countTime++;
			P = P->Next;
		}
	}
	avg = (double)sum / countTime;
	return avg;
}

//void llist::MergeSortByBurst(Node** frontRef)
//{
//	Node *front = *frontRef;
//	Node *P;
//	Node *Q;
//
//	if ((front == NULL) || (front->Next == NULL))
//	{
//		return;
//	}
//	FrontBackSplit(front, &P, &Q);
//	MergeSortByBurst(&P);
//	MergeSortByBurst(&Q);
//
//	*frontRef = SortByBurst(P, Q);
//}
//
//void llist::FrontBackSplit(Node* Original, Node** frontRef, Node** rearRef)
//{
//	Node *fast;
//	Node *slow;
//	slow = Original;
//	fast = Original->Next; 
//
//	while (fast != NULL)
//	{
//		fast = fast->Next;
//		if (fast != NULL)
//		{
//			slow = slow->Next;
//			fast = fast->Next;
//		}
//	}
//	*frontRef = Original;
//	*rearRef = slow->Next;
//	slow->Next = NULL;
//}
//
//Node* llist::SortByBurst(Node* P, Node* Q)
//{
//	Node *result = NULL;
//	if (P == NULL)	
//	{
//		return (Q);
//	}
//	else if (Q == NULL)
//	{
//		return (P); 
//	}
//
//	if (P->Elem.burst <= Q->Elem.burst)
//	{
//		result = P;
//		result->Next = SortByBurst(P->Next, Q);
//	}
//	else
//	{
//		result = Q;
//		result->Next = SortByBurst(P, Q->Next);
//	}
//	return(result);
//}


llist::llist(const llist& Original)
{
	Front = Rear = NULL;
	Count = 0;
	
	Node *P;
	P = Original.Front;
	while (P != NULL)
	{
		this->addRear(P->Elem);
		P = P->Next;
	}
}

llist& llist::operator=(const llist& OtherOne)
{
	PCB x;
	if (&OtherOne != this)
	{
		while (!this->isEmpty())
		{
			this->deleteRear(x);
		}
		Node *P;
		P = OtherOne.Front;
		while (P != NULL)
		{
			this->addRear(P->Elem);
			P = P->Next;
		}
	}
	return *this;
} 
