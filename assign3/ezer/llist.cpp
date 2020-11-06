//CS311 Yoshii Linked List class
//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  control-K cuts and control-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Ezer Patlan
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

//using namespace std;
#include<iostream>
#include"llist.h"
// constructor
// PURPOSE: initialize Front and Rear to be NULL and Count = 0.
//         This does not create any node.  The list is empty.
//   Please place a cout as the first line of this function. “calling the llist constructor”
//   We will need it in preparation for HW3P2.
llist::llist() {
    //cout << "calling the llist constructor" << endl;
    this-> Front = NULL;
    this-> Rear = NULL;
    this->Count = 0;

} // end of constructor function.
//destructor
// PURPOSE: while the list is not empty, call deleteFront repeatedly to delete all nodes.
//   Please place a cout as the first line of this function. “calling the llist destructor”
//   We will need it in preparation for HW3P2.
llist::~llist() {
    //cout << "calling the llist destructor" << endl;
    PCB x;
    while(! this-> isEmpty() ) { // make the list empty
        this-> deleteFront(x);
    } // end of while loop
// nothing
} // end of llist desctructor function.

// PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0.
// PARAMETER:
bool llist::isEmpty() {

    if (Count == 0 && Front == NULL && Rear == NULL)  {
        return true;
    } else {
        return false;
    } // end of if statement.
} // end of isEmpty function

// PURPOSE: display each element of the list starting from Front, enclosed in [] followed by endl.
// special case: if the list is empty, display [empty].
// PARAMETER: no parameters are need since is displaying the llist.
void llist::displayAll() {

    cout << "[Name]  [ID]  [Priority]     [Burst]  [Turnaround Time]  [Waiting Time]" << endl;
    cout << "----------------------------------------------------------------------"<< endl; 
    Node *temp = Front;
    if (this -> isEmpty()) { // if empty print empty
        cout << "[ empty ]" << endl;
    } else {// end of if statement.
        //cout << "[ ";
        while (temp!=NULL) // go through the llist
        {
            cout << temp -> Elem.name << "\t" << temp -> Elem.id << "\t  " << temp -> Elem.priority;
	    cout  << "\t\t" << temp -> Elem.burst << "\t\t"<< temp -> Elem.tatime << "\t\t" << temp -> Elem.wtime << endl;
            
            temp = temp -> Next;
        } // end of while loop
        cout << endl;
	//cout << " ]" << endl;
    }
} // end of displayAll function

// PURPOSE: 2 cases
//special case: if this is going to be the very first node, you must
// 	           create a new node and make Front and Rear point to it. Put NewNum in the Elem field
//    		 of this new node. Count is updated.
//regular case:  add a new node at the rear and puts NewNum in the Elem field
//    		 of this new node. Count is updated.

// PARAMETER: integer NewNum is needed to added to the llist.
void llist::addRear(PCB NewNum) {


    // Creates a temp node and sets
    Node *temp = new Node;
    temp -> Elem = NewNum;
    temp -> Next = NULL;
    if (Front == NULL) { // create the first node
        // Special
        Front = temp;
        Rear = temp;
        Count++;

    } else {
        // Regular
        // Uses temp to find the last node
       /* while ( temp -> Next != NULL ) {
            temp = temp -> Next;
        } // end of while loop
        // Appends the last node with last
        */
	Rear -> Next = temp;
        Rear = Rear -> Next;
        Count++;

    } // end of if statement.
} // end of addRear function.
// PURPOSE:
// special case: if this is going to be the very first node, you must
// 	           create a new node and make Front and Rear point to it. Put NewNum in the Elem field
//    	          of this new node. Count is updated.
// regular case:  add a new node at the front and puts NewNum in the Elem field
//    		 of this new node. Count is updated.
//
// PARAMETER: integer NewNum is needed to incorporated into the llist.
void llist::addFront(PCB NewNum) {

        Node *temp = new Node;
        temp -> Elem = NewNum;
        temp -> Next = NULL;
        if (Front  == NULL) { // if first node
            // Special
            Front = temp;
            Rear = temp;
            Front -> Next = NULL;
            Count++;
        } else if (Front!=NULL){
            // Regular
            Node *temp = new Node;
            temp -> Elem = NewNum;
            temp -> Next = Front;
            Front = temp;
            Count++;
        } // end of if statement.
} // end of addFront function.

// PURPOSE: error case: if the List is empty, throw an exception.
//
// special case: if this is going to make the list empty, give back the
// front node element through OldNum
// (pass by reference) and also remove the front node. Count is updated.
//            Make sure both Front and Rear both become NULL.
//
//
// regular case: give back the front node element through OldNum (pass by reference)
// and also remove the front node. Count is updated.
// PARAMETER: integer OldNum is needed to delete the value from the llist.
void llist::deleteFront(PCB& OldNum) {

    if (this -> isEmpty()) throw Underflow(); // if empty throw exception
    else {

        if (Count == 1) { // make the llist empty
            // Special
            OldNum = Front -> Elem;
            Node *Second;
            Second = Front -> Next;
            delete Front;
            Front = Second;
            Front = NULL;
            Rear = NULL;
            Count--;

        } else { // delete the last value in the llist.
            // Regular
            OldNum = Front -> Elem;
            Node *Second;
            Second = Front -> Next;
            delete Front;
            Front = Second;
            Count--;

        } // end of if statement.
    } // end of if statement.
} // end of deleteFront function.

// PURPOSE: error case: if empty, throw an exception.
//
// special case: if this is going to make the list empty,
// give back the rear node element through OldNum (pass by reference)
// and also remove the rear node. Count is updated.
// Make sure both front and rear become NULL.
//
// regular case: give back the rear node element through OldNum (pass by reference)
// and also remove the rear node. Count is updated.
// PARAMETER: integer OldNum is needed to delete from the llist.
void llist::deleteRear(PCB& OldNum) {

    Node *current = new Node;
    current = Front;

    if (this->isEmpty()) throw Underflow(); // if empty throw exception
    else {

        if ( Count == 1 ){ // if one value in the llist. It will make it empty

            OldNum = Front -> Elem;
            Node *Second;
            Second = Front -> Next;
            delete Front;
            Front = Second;
            Front = NULL;
            Rear = NULL;
            Count--;

         } else {

            while(current -> Next  && current -> Next -> Next != NULL) { // go through the llist
                current = current -> Next;
            } // end of while loop
            // delete the last value of the llist.
            OldNum = Rear -> Elem;
            delete Rear -> Next;
            Rear = current;
            Rear -> Next = NULL;
            Count--;

        } // end of if statement.
    }// end of if statement
} // end of deleteRear function.




// PURPOSE: Error case: If I is an illegal value (i.e. > Count or < 1) throw an exception.
//
// Special case: this should simply call deleteFront (I=1) or deleteRear (I==Count)
// for some cases.
//
// Regular case: will delete the Ith node (I starts out at 1). Count is updated.
// Note that if you go to the I-1th node, and also place another pointer on
// the I+1th node, you can bypass the Ith node. Draw pictures first.
// PARAMETER: int I represents the numerical index node and OldNum is integer represents
// the previous node index.
void llist::deleteIth(int I, PCB& OldNum) {

    Node *temp = new Node;
    temp -> Elem = OldNum;

    Node *previous = new Node;
    Node *current = new Node;

    current = Front;
    if (Front != NULL) {
        int i = 1;
        while (current -> Next != NULL && i <= I-1) { // go through the llist

            previous = current; // store the node
            current = current -> Next;
            i++;
        } // end of while loop
        if (I == 1) { // delete the first llist
            this-> deleteFront(OldNum);
        } else if (current -> Next == NULL && I == Count ) { // delete the last llist
            this -> deleteRear(OldNum);
        }
        else if (I > Count || I < 1){ // out of range from the llist
            throw OutOfRange();
        } else {

            OldNum = current -> Elem;
            previous -> Next = current -> Next;
            delete current;
            current = previous;

            Count--;
        } // end of if statement
    } else { // if Front is NULL

        if( I > Count || I < 1 ){ // out of range from the llist
            throw OutOfRange();
        } else if( I == 1) { // delete the beginning of llist
            this -> deleteFront(OldNum);
        } else if( current -> Next == NULL && I == Count) {
            this -> deleteRear(OldNum); // delete the last of llist
        } else { // make the list empty
            OldNum = Front -> Elem;
            Node *Second;
            Second = Front -> Next;
            delete Front;
            Front = Second;
            Front = NULL;
            Rear = NULL;
            Count--;
        } // end of if statement


    } // end of if statement



} // end of deleteIth function

// PURPOSE: Error cases: If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
//
// Special cases: this should simply call addFront (I==1) or addRear (I==Count+1)
// for some cases.
//
// Regular cases: will add right before the Ith node. Count is updated.
// Note that if you go to the I-1th node, and also place another pointer on the
// Ith node, you can place a new node between them.
// PARAMETER: int I represents the index of the I node and el_t newNum is the index
// of the new value inside the node.
void llist::insertIth(int I, PCB newNum) {

    Node *temp = new Node;
    temp -> Elem = newNum;

    Node *previous = new Node;
    Node *current = new Node;

    current = Front;
    if (Front != NULL) {
        int i = 1;
        while (current -> Next != NULL && i <= I-1) { // go through the llist

            previous = current; // store the node
            current = current -> Next;
            i++;
        } // end of while loop
        if (I == 1) { // add begin of llist
            this-> addFront(newNum);
        } else if (current -> Next == NULL && I == Count + 1) { // add last value llist
            this -> addRear(newNum);
        }
        else if (I > Count+1 || I < 1){ // this is Out of range
            throw OutOfRange();
        } else {
            previous -> Next = temp;
            temp -> Next = current;
            Count++;
        } // end of if statement
    } else { // if the Front is NULL
        if (I > Count+1 || I < 1){ // this is Out of range
            throw OutOfRange();
        } else if ( I == 1){ // add value in the beginning
            this -> addFront(newNum);
        } else if (current -> Next == NULL && Count + 1) {
            this -> addRear(newNum); // add value in the last of the llist
        } else {
            Front = temp;
            temp -> Next = NULL;
            Count++;
        } // end of if statement
    } // end of if statement

} // end of insertIth function



void llist::turnaroundTime()
{
      Node *temp = new Node;
      //int ttcurr, ttprev, time;
      int sum = 0;
      temp = Front;
      if (this -> isEmpty()) { // if empty print empty
          cout << "[ empty ]" << endl;
      } else {// end of if statement.
          //cout << "[ ";
          while (temp!=NULL) // go through the llist
          {
	     /* if (temp-> Elem.id == 1)
	      {
		      ttcurr = temp -> Elem.burst;
		      ttprev = ttcurr;
		      temp -> Elem.tatime = ttcurr;
	      } else {
		      ttcurr = temp -> Elem.burst;
		      time = ttcurr + ttprev;
		      ttprev = time;
		      temp -> Elem.tatime = time;
	      }	*/

	      sum += temp -> Elem.burst;
    	      temp -> Elem.tatime = sum;	      

              temp = temp -> Next;
	      
          } // end of while loop
      }
  
}

float llist::avgturningTime()
{
	Node *temp = new Node;
       temp = Front;
       int countTime = 0;
       float avg=0;
       int sum = 0;
       if (this -> isEmpty()) { // if empty print empty
           cout << "[ empty ]" << endl;
       } else {// end of if statement.
           //cout << "[ ";
           while (temp!=NULL) // go through the llist
           {
               sum += temp -> Elem.tatime;
               countTime++;
 
               temp = temp -> Next;
 
           } // end of while loop
       }

       avg = (double)sum /countTime;
       return avg;

}


void llist::waitingTime()
{
       Node *temp = new Node;
       int turntime, waittime, tburst;
       temp = Front;
       if (this -> isEmpty()) { // if empty print empty
           cout << "[ empty ]" << endl;
       } else {// end of if statement.
           //cout << "[ ";
           while (temp!=NULL) // go through the llist
           {
	       tburst = temp -> Elem.burst;
	       turntime = temp -> Elem.tatime;
	       waittime = turntime - tburst;
	       temp -> Elem.wtime = waittime;
               temp = temp -> Next;

           } // end of while loop
       
       }
}

float llist::avgwaitingTime()
{
        Node *temp = new Node;
	float sum = 0;
	float avg;
	int countTime = 0;
        temp = Front;
        if (this -> isEmpty()) { // if empty print empty
            cout << "[ empty ]" << endl;
        } else {// end of if statement.
            //cout << "[ ";
            while (temp!=NULL) // go through the llist
            {
		sum += temp -> Elem.wtime;
                countTime++;
                temp = temp -> Next;
 
            } // end of while loop
 
        }
	avg = (double)sum /countTime;
	return avg;
}


// Swap the Nodes
Node* llist::swap(Node *ptr1, Node *ptr2)
{
	Node *tmp = ptr2 -> Next;
	ptr2 -> Next = ptr1;
	ptr1 -> Next = tmp;
	return ptr2;
}


void llist::sort(string nameType)
{
	Node *temp = Front;

	int countList=0;	
	if (this -> isEmpty()) { // if empty print empty
             cout << "[ empty ]" << endl;
         } else {// end of if statement.
             //cout << "[ ";
             while (temp!=NULL) // go through the llist
             {
		 countList++;    
                 temp = temp -> Next;
 
             } // end of while loop
 
         }
	
	Node *tmp = Front;
	bubbleSort(&tmp, countList, nameType);
	 //Front(5) 3 4 1 8 7 2 6
         //1 2 3 4 Front(5) 6 7 8
	Front = tmp;
}


// Bubble Sort
void llist::bubbleSort(Node **head, int count, string nameType)
{

	Node **h;
	int i, j, swapped;
	for (i = 0; i<= count; i++)
	{
		h = head;
		swapped = 0;

		for (j = 0; j < count -i - 1; j++)
		{
				
			Node *p1 = *h;
			Node *p2 = p1 -> Next;
			if (nameType == "burst")
			{
				if (p1 -> Elem.burst > p2 -> Elem.burst)
				{
					*h = swap(p1, p2);
					swapped = 1;
				}
			} else if (nameType == "priority")
			{
				if (p1 -> Elem.priority < p2 -> Elem.priority)
				{
					*h = swap(p1,p2);
					swapped = 1;
				}
			} else if (nameType == "id")
			{
				if (p1 -> Elem.id > p2 -> Elem.id)
				{
					*h = swap(p1,p2);
					swapped = 1;
				}
			}

			h = &(*h) -> Next;
		}

		if (swapped == 0)
		{
			break;
		}
	}
}


void llist::rrWaitingTime(int quantum)
{
	// Current time
	int t = 0; 
	Node *temp = Front;
        //int burst = 0;
	int count = 0;	
	//while (true)
	//{
	//	bool done = true;
		//for (Node *temp=Front; temp!=NULL; temp=temp-> Next)
		while(temp!=NULL)
		{
			bool done = true;
			if ( temp -> Elem.burst > 0)
			{
				done = false;

				if ( temp -> Elem.burst > quantum)
				{
					t += quantum;
					//int remain_burst = temp -> Elem.burst; 
					//temp -> Elem.remainder = remain_burst - quantum;
					temp -> Elem.remainder -= quantum;
				} else {
					t = t + temp -> Elem.remainder;
				
					//burst = temp -> Elem.burst;
					//temp -> Elem.wtime = t -  burst;
					temp -> Elem.wtime = t - temp -> Elem.burst;
					temp -> Elem.remainder = 0;

				}
			}
			temp = temp -> Next;

			if (done == true)
			{
				break;
			}
		}
		temp -> Next = Front;
		count++;
		cout << "count infity: " << count << endl;
		
		//if (done == true)
	//	{
	//		break;
	//	}
	//}


}


void llist::rrTurnAroundTime()
{
	Node *temp = Front;

	if (this -> isEmpty()) { // if empty print empty
              cout << "[ empty ]" << endl;
        } else {// end of if statement.
              while (temp!=NULL) // go through the llist
              {
		      temp -> Elem.tatime = temp-> Elem.burst + temp -> Elem.wtime;
		      temp = temp -> Next;

              } // end of while loop

        }



}



Node* llist::findTail()
{
	Node *temp = Front;
	while (temp -> Next != NULL)
	{
		temp = temp -> Next;
	}

	return temp;
}


void llist::makeDoublyLinkedList()
{
	//Node *tail = findTail();
	//*tail - > Next = Front;
	
	Node *temp = Front;
	while (temp -> Next != NULL)
	{
		temp = temp -> Next;
	}

	temp -> Next = Front;
	
	
}


int llist::nodeCount() 
{
	int nodeCount;
	Node *current = Front;
	if (Front != NULL)
	{
		nodeCount = 1;
	} else {
		nodeCount = 0;
	}

	while(current -> Next != Front)	
	{
		nodeCount += 1;
		current = current -> Next;
	} // end while
	return nodeCount;
} // end nodeCount



int llist::checkForZeros()
{
	int nodeCount;

	Node *temp = Front;

	if (Front != NULL)
	{
		nodeCount = 1;
	} else {
		nodeCount = 0;
	}

	while (temp -> Next != Front)
	{
		nodeCount += 1;
		temp=temp -> Next;
	}


	int zeroCount = 0;
	int iterationCount = 0;
	bool isRunning = true;
	Node *current = Front;


	while(isRunning)
	{
		if (current ->  Elem.burst == 0) 
		{
			zeroCount += 1;
		} // end of if
		iterationCount += 1;
		if (zeroCount == nodeCount || iterationCount == nodeCount) 
		{
			isRunning = false;
		} // end if
		current = current -> Next;
	} // end while
	return zeroCount;
} // end checkForZeros




void llist::rrImplementation()
{
	Node *current = Front;
	int timeQuantum = 10;
	int numOfZeros = 0;
	int numOfProcesses = nodeCount();
	while (numOfZeros < numOfProcesses) 
	{
		numOfZeros = 0;
		if (current -> Elem.burst <= timeQuantum )
		{
			current -> Elem.burst = 0;
		} else if (current ->  Elem.burst > timeQuantum) 
		{
			current -> Elem.burst -= timeQuantum;

		}
		numOfZeros = checkForZeros();
		current = current -> Next;
	}
}




// PURPOSE: Copy Constructor to allow pass by value and return by value
// Note that the Original is being passed to the constructor by reference
// to create a new object this-> as a copy of the Original

// PARAMETER: llist Original is needed to make the copy llist
llist::llist(const llist& Original) {
    //  this->'s data members need to be initialized here first
    Front = NULL; Rear = NULL; Count = 0;
    // this-> object has to be built up by allocating new cells with OtherOne elements (**)
    //this->operator=(Original);
    Node* P;  // local pointer for OtherOne
    P = Original.Front;
    while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
    {
       this->addRear(P->Elem);  //P’s element is added to this->
       P = P->Next;             // Go to the next node in OtherOne
    }

} // end of copy constructor function.



// PURPOSE: Overloading of = for allowing the client to use = for linked list objects.
// PARAMETER: constant llist OtherOne is needed to linked into the list object.
llist& llist::operator=(const llist& OtherOne) {
    PCB x;
    // First make sure this-> and OtherOne are not the same object.
    // To do this, compare the pointers to the objects .
    if (&OtherOne != this)  // if not the same
    {
        // this-> object has to be emptied first.
        while (! this->isEmpty() )
                this->deleteRear(x);
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
        {
           this->addRear(P->Elem);  //P’s element is added to this->
           P = P->Next;             // Go to the next node in OtherOne
        }
    } // end of if
    return *this;   // return the result unconditionally.
                    // Note that the result is returned by reference.
} // end of llist operator=
