#include "llist.h"
#include <iostream>
#include <iomanip>
#include <fstream> 

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

void llist::importData(llist &List1)
{ 
	string inputFile;
	ifstream fin;
	string name;
	string line;
	int id = 1;
	int priority = 0;
	int burst = 0;
	int tat = 0;
	int wt = 0;
	//llist L1;

	cout << "Please enter file name: ";
	getline(cin, inputFile);
	fin.open(inputFile.data());
	if (fin)
	{
		while (fin >> name >> priority >> burst)
		{
			PCB X(name, id, priority, burst, tat, wt);
			List1.addRear(X);
			id++;
		}
	}
	else
	{
		cout << "file not found" << endl;
	}
	fin.close();
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
			tatCurr = P->Elem.burst; 
			tatCurr = tatPrev + tatCurr;
			tatPrev = tatCurr;
			P->Elem.TA_Time = tatCurr;
			/*if (P->Elem.id == 1)
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
			}*/
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
	int TATime, Tburst;
	int WTime = 0;

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
			//WTime += Tburst;
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

int llist::numNodes()
{
	int length = 0;
	Node *P = Front; 

	while (P != NULL)
	{
		length++;
		P = P->Next;
	}
	return length;
} 

Node* llist::swap(Node*A, Node*B)
{
	Node* temp = B->Next;
	B->Next = A;
	A->Next = temp;
	return B;
}

void llist::sortB()
{ 
	Node* Temp = Front;
	int length = numNodes(); 
	bubbleSortB(&Temp, length);
	Front = Temp;
	/*int length = numNodes();
	if (length > 1)
	{
		for (int i = 0; i < length-1; i++)
		{
			Node* current = Front;
			Node* next = Front->Next;
			for (int j = 0; j < length-1; j++)
			{
				if (current->Elem.burst > next->Elem.burst)
				{
					int temp = current->Elem.burst;
					current->Elem.burst = next->Elem.burst;
					next->Elem.burst = temp;
				}
				current = next;
				next = next->Next;
			}
		}
	}*/
} 

void llist::bubbleSortB(Node** top, int numNodes)
{
	Node **F;
	int swapped;

	for (int i = 0; i <= numNodes; i++)
	{
		F = top;
		swapped = 0;

		for (int j = 0; j < numNodes-1; j++)
		{
			Node *Ptr1 = *F;
			Node *Ptr2 = Ptr1->Next;
			if (Ptr1->Elem.burst > Ptr2->Elem.burst)
			{
				*F = swap(Ptr1, Ptr2);
				swapped = 1;
			}
			F = &(*F)->Next;
		}
		if (swapped == 0)
		{
			break;
		}
	}
} 

void llist::sortPrio()
{
	Node* Temp = Front;
	int length = numNodes();
	bubbleSortPrio(&Temp, length);
	Front = Temp;
	
}

void llist::bubbleSortPrio(Node** top, int numNodes)
{
	Node **F;
	int swapped;

	for (int i = 0; i <= numNodes; i++)
	{
		F = top;
		swapped = 0;

		for (int j = 0; j < numNodes - 1; j++)
		{
			Node *Ptr1 = *F;
			Node *Ptr2 = Ptr1->Next;
			if (Ptr1->Elem.priority > Ptr2->Elem.priority)
			{
				*F = swap(Ptr1, Ptr2);
				swapped = 1;
			}
			F = &(*F)->Next;
		}
		if (swapped == 0)
		{
			break;
		}
	}
}