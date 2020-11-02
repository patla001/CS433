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

    cout << "[Name]  [ID]  [Priority]  [Burst]" << endl;
    cout << "-------------------------------"<< endl; 
    Node *temp = new Node;
    temp = Front;
    if (this -> isEmpty()) { // if empty print empty
        cout << "[ empty ]" << endl;
    } else {// end of if statement.
        //cout << "[ ";
        while (temp!=NULL) // go through the llist
        {
            cout << temp -> Elem.name << "\t" << temp -> Elem.id << "\t" << temp -> Elem.priority << "\t" << temp -> Elem.burst << "\t"<< endl;
            
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
        while ( temp -> Next != NULL ) {
            temp = temp -> Next;
        } // end of while loop
        // Appends the last node with last
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


void llist::Sorting()
{

	Node *temp = new Node;
        temp = Front;
	this -> insertionSort(&temp);
}



void llist::insertionSort(Node **head)
{
	Node *sorted = NULL;
	Node *current = *head;

	while (current != NULL)
	{
		Node *temp = current -> Next;

		this-> sortedInsert(&sorted, current);

		current = temp;
	}
	*head = sorted;
}

void llist::sortedInsert(Node **head, Node *newTemp)
{
	Node *current = new Node;

	if (*head == NULL || (*head)-> Elem.priority >= newTemp -> Elem.priority)
	{
		newTemp -> Next = *head;
		*head = newTemp;
	} else {
		current = *head;
		while (current -> Next != NULL && current -> Next -> Elem.priority < newTemp -> Elem.priority)
		{
			current = current -> Next;
		}
		newTemp -> Next = current -> Next;
		current -> Next = newTemp;
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
