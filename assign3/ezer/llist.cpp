#include<iostream>
#include<cmath>
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
llist::~llist() {
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
	Rear -> Next = temp;
        Rear = Rear -> Next;
        Count++;

    } // end of if statement.
} // end of addRear function.

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





// PURPOSE: It calculates the summation from the previous value
// PARAMETER: No parameters
void llist::turnaroundTime()
{
	// initialize a node
      Node *temp = new Node;
      int sum = 0;
      temp = Front;
     
      if (this -> isEmpty()) { // if empty print empty
          cout << "[ empty ]" << endl;
      } else {// end of if statement.
          
	  while (temp!=NULL) // go through the llist
          {
	      // sum up every previous value
	      sum += temp -> Elem.burst;
	      // store the summation value into the object
    	      temp -> Elem.tatime = sum;	      
	      // goes to the next linked list
              temp = temp -> Next;
	      
          } // end of while loop
      }// end of if statement
  
} // end of turnaroundTime function


// PURPOSE: It calculates the average from the object turning time
// PARAMETER: No parameters
float llist::avgturningTime()
{
	// intialize the variables
	Node *temp = new Node;
       temp = Front;
       int countTime = 0;
       float avg=0;
       int sum = 0;
       if (this -> isEmpty()) { // if empty print empty
           cout << "[ empty ]" << endl;
       } else {// end of if statement.
           while (temp!=NULL) // go through the llist
           {
		// sum up every previous value	   
               sum += temp -> Elem.tatime;
	       // counts the number of times
               countTime++;
 		// goes to the next linked list
               temp = temp -> Next;
 
           } // end of while loop
       } // end of if statement
	// calculates the averages
       avg = (double)sum /countTime;
       // returns the average value
       return avg;

} // end of avgturningTime function

// PURPORSE: It calculates the turning time standard deviation from the object
// PARAMETER: No parameters
float llist::stdturningTime()
{
	// initialize the variables
  	Node *temp = new Node;
        float sum = 0;
        int countTime = 0;
        float mean;
        float stDeviation=0;
        temp = Front;
        if (this -> isEmpty()) { // if empty print empty
            cout << "[ empty ]" << endl;
        } else {// end of if statement.
           while (temp!=NULL) // go through the llist
           {
		   // sum up every previous value
                sum += temp -> Elem.tatime;
		// counts the number of times
                countTime++;
		// goes to the next linked list
                temp = temp -> Next;

            } // end of while loop

        } // end of if statement

	// calculates the mean
        mean = (double)sum/(countTime+1);
	// goes over again to calculate the standard deviation
        for (Node *temp=Front; temp!= NULL; temp = temp-> Next)
        {
		// calculates power raise by two and mines the mean
                stDeviation += pow(temp -> Elem.tatime - mean, 2);
        }
	// returns the square root and divided by the total number of data points.
        return sqrt(stDeviation/(countTime+1));

}


// PURPOSE: Calculates the waiting time subtracting the tt - burst time
// PARAMETER: No parameters
void llist::waitingTime()
{
	// Initialize the variables
       Node *temp = new Node;
       int turntime, waittime, tburst;
       temp = Front;
       if (this -> isEmpty()) { // if empty print empty
           cout << "[ empty ]" << endl;
       } else {// end of if statement.
           while (temp!=NULL) // go through the llist
           {
	       // store the burst time into integer variable	    
	       tburst = temp -> Elem.burst;
	       // store the turn around time into integer variable
	       turntime = temp -> Elem.tatime;
	       // calculate the waiting time
	       waittime = turntime - tburst;
	       // store the waiting time into the object
	       temp -> Elem.wtime = waittime;
	       // go to the next linked list
               temp = temp -> Next;

           } // end of while loop
       
       } // end of if statement
} // end of waiting time function


// PURPOSE: Calculates the average waiting time from the object
// PARAMETERS: No parameters
float llist::avgwaitingTime()
{
	// initialize the variables
        Node *temp = new Node;
	float sum = 0;
	float avg;
	int countTime = 0;
        temp = Front;
        if (this -> isEmpty()) { // if empty print empty
            cout << "[ empty ]" << endl;
        } else {// end of if statement.
            while (temp!=NULL) // go through the llist
            {
		// sum up all the waiting time values
		sum += temp -> Elem.wtime;
                // increments the number of times inside the loop
		countTime++;
		// go to the next linked list
                temp = temp -> Next;
 
            } // end of while loop
 
        } // end of if statement
	// calculates the average 
	avg = (double)sum /countTime;
	// returns the final solution
	return avg;
}
// PURPOSE: Standard Deviation for the waiting time function
// PARAMETERS: No parameters
float llist::stdwaitingTime()
{
	// Initialize the variables
         Node *temp = new Node;
         float sum = 0;
         int countTime = 0;
	 float mean;
	 float stDeviation=0;
         temp = Front;
         if (this -> isEmpty()) { // if empty print empty
             cout << "[ empty ]" << endl;
         } else {// end of if statement.
            while (temp!=NULL) // go through the llist
            {
		 // sum up all the waiting time values
                 sum += temp -> Elem.wtime;
                 // increments the number of times inside the loop
		 countTime++;
                 // go to the next linked list
		 temp = temp -> Next;
 
             } // end of while loop
 
         } // end of if statement

	 // calculate the mean from waiting time
	 mean = (double)sum/(countTime+1);
	 // for loop loops to the linked list and calculates the
	 // standard deviation
	 for (Node *temp=Front; temp!= NULL; temp = temp-> Next)
	 {
		 // calculates the standard deviation
		 stDeviation += pow(temp -> Elem.wtime - mean, 2);
	 }
	 // returns the final solution for the standard deviation
         return sqrt(stDeviation/(countTime+1));
} // end of standard deviation waiting time function



// PURPOSE: Swap the Nodes of the linked list
// PARAMETERS: ptr node is the first node we want to swap to 
// prt2 node.
Node* llist::swap(Node *ptr1, Node *ptr2)
{
	// store second node into tmp node
	Node *tmp = ptr2 -> Next;
	// overwrite ptr2 to prt1
	ptr2 -> Next = ptr1;
	// store tmp into ptr1 and 
	// completes the swap node.
	ptr1 -> Next = tmp;
	// return the second node.
	return ptr2;
} // end of swap function

// PURPOSE: sort function for linked list
// PARAMETERS: string is refer which parameter from the object needs
// to be sort.
void llist::sort(string nameType)
{
	// initialize the variables
	Node *temp = Front;

	int countList=0;	
	if (this -> isEmpty()) { // if empty print empty
             cout << "[ empty ]" << endl;
         } else {// end of if statement.
             while (temp!=NULL) // go through the llist
             {
		 // increment the number of list
		 countList++;    
                 // go to the next linked list
		 temp = temp -> Next;
 
             } // end of while loop
 
         }// end of if statement.
	// intialize the front of the linked list
	Node *tmp = Front;
	// call the bubble sort function
	bubbleSort(&tmp, countList, nameType);
	  // this is example on how the bubble sort works
	  // e.g.,
	  //Front(5) 3 4 1 8 7 2 6
          //1 2 3 4 Front(5) 6 7 8

	// we need to saved the tmp node in the beginning 
	// of the linked list saved "Front(5) 6 7 8"
	Front = tmp;
	// if tmp is not saved under Front it only sort half
	// of the linked list.
} // end of sort function


// PURPOSE: Bubble Sort linked list function
// PARAMETERS: node represent the first linked list, second parameter
// represent the total number of the linked list, and last parameter
// refers which parameter from the object you wish to sort.
void llist::bubbleSort(Node **head, int count, string nameType)
{
	// intialize the variables
	Node **h;
	int i, j, swapped;
	// intialize the first for loop
	for (i = 0; i<= count; i++)
	{
		// save the first node from the linked list
		h = head;
		swapped = 0;

		// initialize the second for loop
		for (j = 0; j < count -i - 1; j++)
		{
			// initialize the nodes	
			Node *p1 = *h;
			Node *p2 = p1 -> Next;
			// if burst parameter is true
			// then sort the burst parameters from the object
			if (nameType == "burst")
			{
				// if the burst time in the first node
				// is greater than the burst time for the second node
				if (p1 -> Elem.burst > p2 -> Elem.burst)
				{
					// swap the nodes
					*h = swap(p1, p2);
					// flag them that they were swap.
					swapped = 1;
				} // end of if statement
			} else if (nameType == "priority")
			{
				// if priority is selected 
				// the first node priority is less than the second node
				// this means sorts the highest value from the priority object
				if (p1 -> Elem.priority < p2 -> Elem.priority)
				{
					// swap the priority values inside the nodes.
					*h = swap(p1,p2);
					// flag them that they were swap.
					swapped = 1;
				} // end of if statement
			} else if (nameType == "id")
			{
				// if number of id is selected
				// the first node id is greater than the second node
				// this means sort the lowest value from the id object
				if (p1 -> Elem.id > p2 -> Elem.id)
				{
					// swap the id values inside the nodes.
					*h = swap(p1,p2);
					// flag them that they were swap.
					swapped = 1;
				} // end of if statement
			} // end of if statement

			// go to the next linked list node

			h = &(*h) -> Next;
		} // end of second for loop

		// if swapped is false then break the loop
		if (swapped == 0)
		{
			break;
		} // end of if statement
	}  // end of first for loop
} // end of bubble sort function.

// PURPOSE: Round Robin (RR) waiting time function
// PARAMETERS: passed integer quantum value
void llist::rrWaitingTime(int quantum)
{
         // initialize variable
         int t = 0;
	 // infinitely while loop
         while (true)
	 {
		 // flag when it is done the process
                 bool done = true;
		 // for loop for linked list
                 for (Node *temp=Front; temp!=NULL; temp=temp-> Next)
                 {
			 // if the remainder is greater than zero
                         if ( temp -> Elem.remainder > 0)
                         {
				 // process is pending
                                 done = false;

				 // if the remainder is greater than the quantum
				 // please continue inside the loop
                                 if ( temp -> Elem.remainder > quantum)
                                 {
					 // increment the number of time by quantum value.
					 t += quantum;
					 // decrease the value of the remainder by the number of quantum.
                                         temp -> Elem.remainder -= quantum;
                                 } else {
					 // increment the number of time by the remainder
                                         t = t + temp -> Elem.remainder;
					 // calculate the waiting time
                                         temp -> Elem.wtime = t - temp -> Elem.burst;
					 // define the remainder as zero
					 temp -> Elem.remainder = 0;

                                 }// end of if statement
                         } // end of if statement.
                 } // end of for loop.

		 // if the done is true
		 // the process is completed and
		 // breaks the while loop.
                 if (done == true)
                 {
                         break;
                 } // end of if statement
         } // end of infinitely while loop


} // end of round robin waiting time function 


// PURPOSE: Round Robin Turn Around Time function
// Parameters: No parameters
void llist::rrTurnAroundTime()
{
	// initialize the variables
	Node *temp = Front;

	if (this -> isEmpty()) { // if empty print empty
              cout << "[ empty ]" << endl;
        } else {// end of if statement.
              while (temp!=NULL) // go through the llist
              {
		      // calculate the turnaround time
		      temp -> Elem.tatime = temp-> Elem.burst + temp -> Elem.wtime;
		      // go to the next linked list
		      temp = temp -> Next;

              } // end of while loop

        } // end of if statement



}// end of rrTurnAroundTime function.


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
