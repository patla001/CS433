#include "PCB.h"

//a list node is defined here as a struct Node for now
struct Node
{
  PCB Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{

protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

 public:

  // Exception handling classes
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object

  ~llist();     // destructor to destroy all nodes

  // return true if Front and Rear are both pointing to NULL and Count is 0.
  bool isEmpty();

  //display each element of the list starting from Front, enclosed in [] followed by endl.
  // special case: if the list is empty, display [empty].
  void displayAll();


  //special case: if this is going to be the very first node, you must create a
  // new node and make Front and Rear point to it. Put NewNum in the Elem field
  // of this new node. Count is updated.
  //
  // regular case: add a new node at the rear and puts NewNum in the Elem field
  // of this new node. Count is updated.
  void addRear(PCB);

  // error case: if the List is empty, throw an exception.
  //
  // special case: if this is going to make the list empty, give back the front
  // node element through OldNum (pass by reference) and also remove the front node.
  // Count is updated.
  //
  // regular case: give back the front node element through OldNum (pass by reference)
  // and also remove the front node. Count is updated.
  void deleteFront(PCB&);

  //error case: if empty, throw an exception.
  //
  // special case: if this is going to make the list empty,
  // give back the rear node element through OldNum (pass by reference)
  // and also remove the rear node. Count is updated.
  // Make sure both front and read become NULL.
  //
  // regular case: give back the rear node element through OldNum (pass by reference)
  // and also remove the rear node. Count is updated.
  void deleteRear(PCB&);


  // calculates the turn around time inside the linked list
  void turnaroundTime();
  
  // calculates the average of the turning around time and
  // output the average
  float avgturningTime();
  
  // calculates the standard deviation of the turning around time
  // and outputs the standard deviation
  float stdturningTime();
  
  // calculates the waiting time inside the linked list
  void waitingTime();
  
  // calculates the standard deviation of the waiting time
  // and outputs the standard deviation
  float stdwaitingTime();
  
  // calculates the average of the waiting time and outputs the 
  // average.
  float avgwaitingTime();
  
  // swap the nodes from the linked list
  Node* swap(Node *ptr1, Node *ptr2);
  
  // bubble sort technique sort the nodes by swapping them
  // until all values are descending or ascending
  void bubbleSort(Node **head, int count, string nameType);
  
  // sort function calls the bubble sort
  void sort(string nameType);
  
  // calculates the round robin waiting time
  void rrWaitingTime(int quantum);
  
  // calculates the round robin turning around time
  void rrTurnAroundTime();
  
  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);

  //Overloading of = for allowing the client to use = for linked list objects.
  llist& operator=(const llist&);
}; // end of llist class.
