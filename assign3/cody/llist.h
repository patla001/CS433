//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS

// =======================================================
// HW#: HW3P1 llist
// Your name: Ezer Patlan
// Compiler:  g++
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
//typedef char el_t;
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



  //special case: if this is going to be the very first node, you must create
  // a new node and make Front and Rear point to it. Put NewNum in the Elem field
  // of this new node. Count is updated.
  //
  // regular case: add a new node at the front and puts NewNum in the Elem field
  // of this new node. Count is updated.
  void addFront(PCB);

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

  //Error case: If I is an illegal value (i.e. > Count or < 1) throw an exception.
  //
  // Special case: this should simply call deleteFront (I=1) or deleteRear (I==Count)
  // for some cases.
  //
  // Regular case: will delete the Ith node (I starts out at 1). Count is updated.
  // Note that if you go to the I-1th node, and also place another pointer on
  // the I+1th node, you can bypass the Ith node. Draw pictures first.
  void deleteIth(int, PCB&);

  // Error cases: If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.
  //
  // Special cases: this should simply call addFront (I==1) or addRear (I==Count+1)
  // for some cases.
  //
  // Regular cases: will add right before the Ith node. Count is updated.
  // Note that if you go to the I-1th node, and also place another pointer on the
  // Ith node, you can place a new node between them.
  void insertIth(int, PCB);

  // sorts the linked list by changing next pointers (not data)
  Node* SortedMerge(Node* a, Node* b);

  void MergeSort(Node** headRef);
  
  void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);

  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);

  //Overloading of = for allowing the client to use = for linked list objects.
  llist& operator=(const llist&);

}; // end of llist class.
