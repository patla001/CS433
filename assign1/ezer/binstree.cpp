// CS311 : This is the BST implementation file template by Rika Yoshii

// Each node has an Up link to make it easy to go up the tree.  It must be set as nodes are inserted.  Some deletion
// cases require Up link to be updated.
//
// INSTRUCTIONS:
// Look for ** comments to complete this file for HW4
// Try not to delete the ** comments
// Make sure all { } match. Doing Tab on each line helps.
// Draw pictures as you complete each **

// =========================================================
//HW#: HW4 BST
//Your name: Ezer Patlan
//Complier:  g++
//File type: implementation file binstree.cpp
//================================================================

using namespace std;
#include <iostream>
#include<bits/stdc++.h>
#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
  Root = NULL;   // This is an empty tree
} // end of BST function

// destructor must completely destroy the tree
BST::~BST()
{
  dtraverse(Root); // traverse to delete all vertices in post order
  Root = NULL;
} // end of ~BST destructor function
// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{
  if (V != NULL)
    {
      dtraverse(V->Left);         // destroy left sub tree of V
      dtraverse(V->Right);       //  destroy right sub tree of V
      delete V;                  //  delete V
  } // end of if statement
} // end of dtraverse function

// PURPOSE: Show vertices in IN order traversal from the Root
void BST::Display()
{
  cout << "----------------------------------------" << endl;
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
  cout << "----------------------------------------" << endl;
}
// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
// For non EC, the height and balance will always be 0
void BST::INorderTraversal(Vertex *V)
{
  if (V != NULL) // if current vertex is not null
    {

      INorderTraversal(V->Left); //  traverse left sub-tree of V recursively
      //  display V's element, height and balance and do endl;
      int elementV = V-> Elem;
      int heightV = V-> Height;
      int balanceV = V-> Balance;


      cout << elementV << "   Height: " << heightV << "   Balance: " << balanceV << endl;
      //Display();
      INorderTraversal(V->Right); //  traverse right sub-tree of V recursively
  } // end of if statement
} // end of INorderTraversal function

// PURPOSE: Searches for an element in PRE-order traversal
// This is the same as Depth First Traversal
bool BST::Search(elem_t K)
{
  PREorderSearch(Root, K);  // start pre-order traversal from the root
}
// PURPOSE: Does PRE order search from V recursively
// PARAM: V is the pointer to the vertex to be visited now
//        K is what we are looking for
bool BST::PREorderSearch(Vertex *V, elem_t K)
{
    if (V != NULL)
    {
        if (K == V->Elem){
            return true; // found the element in V
        } else if ( K < V-> Elem )
        {
		 // traverse left sub-tree of V recursively
         PREorderSearch(V->Left, K);

        } else {
    	    // traverse right sub-tree of V recursively
            PREorderSearch(V->Right, K);

        }
    } else {
        return false;
    } // end of if statement
} // end of PREorderSearch function.

// ------ The following are for adding and deleting vertices -----


// PURPOSE: Adds a vertex to the binary search tree for a new element
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
// to demonstrate the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::InsertVertex(elem_t E)
{
  // Set up a new vertex first
   Vertex *N;         // N will point to the new vertex to be inserted
   N = new Vertex;    // a new vertex is created
   N->Left  = NULL;   // make sure it does not
   N->Right = NULL;   // point to anything
   N->Elem  = E;      // put element E in it
   N->Height = 0;
   N->Balance = 0;
   N->Up = NULL;      // no parent for now
   cout << "Trying to insert " << E << endl;

   if (Root == NULL)  // Special case: we have a brand new empty tree
     {
       Root = N;      // the new vertex is added as the root
       cout << "...adding " << E << " as the root" << endl;
     }// end of the special case

   else  // the tree is not empty
     {
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will point to V's parent

        V = Root;        // start with the root as V

	// go down the tree until you cannot go any further
	while (V != NULL)
	  {
	    if (N->Elem == V->Elem) // the element already exists
              {	 cout << "...error: the element already exists" << endl;
		return;  }
	    else

	      if (N->Elem < V->Elem)  // what I have is smaller than V
		{  cout << "...going to the left " << endl;


          Parent = V; // change Parent to be V to go down

          V = V -> Left; // change V to be V's Left


		}
	      else // what I have is bigger than V
		{  cout << "...going to the right " << endl;

          Parent = V; // change Parent to be V to go down

          V = V -> Right; // change V to be V's Right


		}
	  }//end of while

   // reached NULL -- Must add N as the Parent's child

        if (N->Elem < Parent->Elem)
        {
	        // Parent's Left should point to the same place as N
            Parent -> Left = N;
            // N should point UP to the Parent
            N-> Up = Parent;
	        cout << "...adding " << E << " as the left child of "
		        << Parent->Elem << endl;
            // ** EC call here to adjust height and BF	}
            climbUp(N);

        }
        else
           {
	        // Parent's Right should point to the same place as N
            Parent -> Right = N;
            // N should point UP to the Parent
            N -> Up = Parent;
            cout << "...adding " << E << " as the right child of "
                  << Parent->Elem << endl;
	        // ** EC call here to adjust height and BF
            climbUp(N);

  	        }

      }// end of normal case

}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{
  cout << "Trying to delete " << E << endl;

  Vertex *V;              // the current vertex
  Vertex *Parent = NULL;

  // case 1: Lonely Root
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    { cout << "...deleting the lonely root" << endl;
      delete Root;
      Root = NULL;
      return; }  // only the Root was there and deleted it


  // Case 2: One Substree root
  if (Root == NULL) { // if what you want to delete is the root
      if( V-> Right == NULL) { //  and it has only the left subtree
          if ( V  == Root ) {
              Root = Root -> Left;
              delete Root; // delete Root in the Root with just one child case
              return;
          }
      }

      if (V -> Left == NULL ) { //  and it has only the right subtree
          if (V == Root ) {
              Root = Root -> Right;
              delete Root; // delete Root in the Root with just one child case
              return;
          }
      }
  }// end of deleting the root with one subtree

  // Otherwise deleting something else

  V = Root;  // start with the root to look for E

  // going down the tree looking for E
  while (V != NULL)
  {
    if ( E == V->Elem || Root == NULL)   // found it
	{  cout << "...removing " << V->Elem << endl;
      remove(V, Parent); // call remove here to remove V
	  return;
    } // end of if statement

     else if (E < V->Elem)
	 {  cout << "...going to the left" << endl;
	    // update Parent and V here to go down

        Parent = V; // update Parent
        V = V -> Left; //  V here to go down

	 } else
	  {  cout << "...going to the right" << endl;

        Parent = V; // update Parent
        V = V -> Right; // V here to go down

    } // end of if statement

    }// end of while

  // reached NULL  -- did not find it
  cout << "Did not find the key in the tree." << endl;

}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{

    if (V->Left == NULL && V->Right == NULL) //  if V is a leaf (case 1)

    {
	cout << "removing a leaf" << endl;

    if(V == P->Left) // if V is a left child of P
	{

      delete V; // delete V
      P->Left = NULL; //  make Parent's left NULL
          // ** EC call here from P to adjust height and BF
          climbUp(P);

	} else // V is a right child of the Parent
	  {

          delete V; // delete V
          P->Right = NULL; // make Parent's right NULL
          // ** EC call from P to adjust height and BF
          climbUp(P);

	  }
      }//end of leaf case

   else  if (V-> Left == NULL)  // if V has just the right child so bypass V (case 2)
	{
       if ( V == Root){
           cout << "...deleting root and making right child the root" << endl;
           Root = Root -> Right;
           return;
       } else {
           cout << "removing a vertex with just the right child" << endl;
           // You need if then else to determine Parent's left or right

           if (P-> Left == V) { //  and it has only the right subtree
               P -> Left = V -> Right; // should point to V's right child;
           } else { //  and it has only the left subtree
               P -> Right = V -> Right; // should point to V's right child;
           }

           //V = V-> Up; // Make the left child point UP to the parent;
           V -> Up = P;
           delete V; //  Be sure to delete V
           climbUp(P);

       } // end of if statement

          // ** EC call from P to adjust height and BF
	}// end of V with left child. End of if statement and case 1

   else if (V-> Right == NULL) //  if V has just the left child so bypass V (case 2)
	{

        if (V == Root) { // current vertex is same as root
            cout << "...deleting root and making left child the root" << endl;
            Root = Root -> Left;
            return;
        } else {
            cout << "removing a vertex with just the left child" << endl;
            //  You need if then else to determine Parent's left or right
            if (P-> Left == V) { //  and it has only the right subtree
                P-> Left = V-> Left; //  should point to V's left child;
            } else { //  and it has only the left subtree
                P-> Right = V-> Left; //  should point to V's left child;
            }

            //V = V-> Up; // Make the right child point UP to the parent;
            V -> Up = P;
            delete V; // Be sure to delete V
            climbUp(P);

        } // end of if statement

          // ** EC call from P to adjust height and BF
        }//end of V with right child

   else // V has two children (case 3)
	{ cout << "removing an internal vertex with children" << endl;
	  cout << "..find the MAX of its left sub-tree" << endl;
	  elem_t Melem;
	  // find MAX element in the left sub-tree of V
          Melem = findMax(V);
          cout << "..replacing " << V->Elem << " with " << Melem << endl;
          // Replace V's element with Melem here
          V->Elem = Melem;
        }//end of V with two children

}// end of remove function

// PURPOSE: Finds the Maximum element in the left sub-tree of V
// and also deletes that vertex
elem_t BST::findMax(Vertex *V)
{
    Vertex *Parent = V;
    V = V->Left;          // start with the left child of V
    if(V != NULL) {
          // while the right child of V is still available
        while (V-> Right != NULL)
        {
            Parent = V; // update Parent
            V = V-> Right; // V to go to the right
        } // end of while loop
    }   // end of if statement
  // reached NULL Right  -- V now has the MAX element
  elem_t X = V->Elem;
  cout << "...Max is " << X <<  " and we need to delete it" << endl;
  remove(V, Parent);    // remove the MAX vertex
  return X;             // return the MAX element

}// end of FindMax function

// get the max of two nodes
int BST::max(int a, int b) {
    return ((a > b) ? a : b);
} // end of max function


// A utility function to get the
// height of the tree
int BST::height(Vertex *V){
    if (V == NULL){ // Height is NULL equal to -1
        return -1;
    } else {
        // Height inside each node = Max of Height of Left and Height of Right
        return 1 + max(height(V-> Left), height(V-> Right));
    } // end of if statement
} // end of height function


// PURPOSE: Climbs up from the vertex to compute Height and Balance Factor
// of all ancestors and displays them as they are computed.
// This should be called whenever a vertex (N) is inserted
// This should be called whenever a vertex is deleted (i.e. delete V)
void BST::climbUp(Vertex *V)
{

    cout << "...Start climbing up to adjust heights ......" << endl;
    while (V != NULL)
    {

      // compute V->Height  based on the left/right children

      V -> Height = height(V);
      // compute V->Balance based on the left/right children

      V -> Balance = height(V-> Right) - height(V -> Left);
     //V -> Balance = height(V->Left) - height(V->Right);
      cout << "..." << V->Elem << "'s height: "
           << V->Height << " with balance: "
       	   << V->Balance << endl;
      // calling fixIt function to balance the tree.
      fixIt(V);



      //  go up to the parent
      V = V -> Up;

      //Display();
    } // end of while loop
} // end of climbUp function


// Purpose: rotate left at Vertex Parent
// Parameter: Vertex Parent refers as the parent node.
void BST::singleLeftRotate(Vertex *Parent)
{   // Display the rotation case.
    cout << "    case 1: right heavy so rotate to left" << endl;

    // Rotation
    Vertex *Pivot = Parent -> Right;
    Parent -> Right = Pivot -> Left;

    if (Pivot-> Left != NULL)
    {
        Pivot-> Left -> Up = Parent;
    } // end of if statement.

    Pivot->Up = Parent->Up;

    if (Parent -> Up == NULL)
    {
        this->Root = Pivot;
    } else if (Parent == Parent -> Up -> Left)
    {
        Parent -> Up -> Left = Pivot;
    } else {
        Parent -> Up -> Right = Pivot;
    } // end of if statement.

    // Update the Uplink of Parent and Pivot.
    Pivot -> Left = Parent;
    Parent -> Up = Pivot;

    // Update the Height and Balance Factor.
    Parent -> Height  = height(Parent);
    Parent -> Balance = height(Parent->Right) - height(Parent-> Left);

    Pivot -> Height = height(Pivot);
    Pivot -> Balance = height(Pivot->Right) - height(Pivot-> Left);

    // Display the Update rotation
    cout << " -- rotate left with pivot " << Pivot -> Elem << endl;
    cout << "   New root is: " << Pivot -> Elem << endl;
    cout << ">>>>Fixed" << endl;


} // end of singleLeftRotate function.

// Purpose: rotate right at Vertex Parent
// Parameter: Vertex Parent refers to the node parent.
void BST::singleRightRotate(Vertex *Parent)
{   // Display the rotation case.
    cout << "    case 2: left heavy so rotate to right" << endl;

    // Rotating
    Vertex *Pivot = Parent -> Left;
    Parent -> Left = Pivot -> Right;

    if (Pivot -> Right != NULL)
    {
        Pivot -> Right -> Up = Parent;
    } // end of if statement.
    Pivot -> Up = Parent -> Up;

    if (Parent -> Up == NULL)
    {
        this->Root = Pivot;
    } else if (Parent == Parent-> Up -> Right)
    {
        Parent-> Up -> Right = Pivot;
    } else {
        Parent -> Up -> Left = Pivot;
    } // end of if statement.

    // Update the Uplink Parent and Pivot
    Pivot -> Right = Parent;
    Parent -> Up = Pivot;

    // Update the Height and Balance Factor
    Parent->Height = height(Parent);
    Parent->Balance = height(Parent->Right) - height(Parent->Left);

    Pivot->Height = height(Pivot);
    Pivot->Balance = height(Pivot->Right) - height(Pivot->Left);

    // Display the update rotation
    cout << " -- rotate right with pivot " << Pivot -> Elem << endl;
    cout << "   New root is: " << Pivot -> Elem << endl;
    cout << ">>>>Fixed" << endl;

} // end of singleRightRotate function

// Purpose: first rotate right at Vertex Parent, then rotate left at Vertex Parent.
// Parameter: Vertex V refers as the parent node.
void BST::doubleLeftRotate(Vertex *V)
{   // Display the rotation case.
    cout << "    case 3: right heavy with left heavy sub-tree" << endl;
    singleRightRotate(V -> Right); // calling singleRightRotate function.
    singleLeftRotate(V); // calling singleLeftRotate function


} // end of doubleRightRotate function.

// Purpose: first rotate left at Vertex Parent, then rotate right at Vertex Parent
// Parameter: Vertex V refers as the parent node.
void BST::doubleRightRotate(Vertex *V)
{   // Display the rotation case.
    cout << "    case 4: left heavy with right heavy sub-tree" << endl;
    singleLeftRotate(V -> Left); // calling singleLeftRotate function.
    singleRightRotate(V); // calling singleRightRotate function

} // end of doubleLeftRotate function.

// Purpose: returns a map of the tree containg the direction of the tree right or left
// and the balance factor values of each element in the node.
// Parameters: Vertex V refers as the node of the tree. String indent is the
// branches of the tree. bool last gives the orientation whether is right or left.
void BST::printTree(Vertex *V, string indent, bool last) {
    // print the tree structure on the screen
    if (V != NULL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "     ";
        } else {
            cout <<"L----";
            indent += "|    ";
        } // end of if statement
        // display the values of the node
        cout << V->Elem <<" BF = "<< V -> Balance<<")"<<endl;

        printTree(V->Left,indent,false); // calling printTree for the left node
        printTree(V->Right,indent,true); // calling printTree for the right node
    } // end of if statement
} // end of printTree function

// Purpose: print the tree structure on the screen
void BST::showTree() {
    printTree(this->Root, "", true); // calling printTree function
} // end of showTree function.

// PURPOSE: FixIt Identifies which case it is and call the correct rotation
// function
// Parameter: Vertex V refers as the node that contains a balance factor -2 or 2 that
// needs to be corrected in order to be balance tree.
void BST::fixIt(Vertex *V)
{
    if (V-> Balance > 1)
    {   // display balance factor and element
        cout << ">>>>Balance Factor " << V-> Balance << endl;
        cout << ">>>>Fixing an unbalanced node at " << V-> Elem << endl;

        if (V-> Right -> Balance > 0)
        {
            // display balance factor right node
            cout << "SLR-Parent-Right: " << V-> Right -> Balance << endl;

            // case 1: right right case
            singleLeftRotate(V);

            Display(); // display the table tree
            showTree(); // display the map tree

        } else if (V-> Right -> Balance < 0 ){
            // display the balance factor right node
            cout << "DLR-Parent-Right: " << V-> Right -> Balance << endl;
            // case 3: right left case
            doubleLeftRotate(V);

            Display(); // display the table tree
            showTree(); // display the map tree
        }
    }

    if (V-> Balance < -1  )
    {   // display balance factor and element
        cout << ">>>>Balance Factor " << V-> Balance << endl;
        cout << ">>>>Fixing an unbalanced node at " << V-> Elem<< endl;


         if ( V -> Left -> Balance < 0)
         {
             // display the balance factor left node.
             cout << "SRR-Parent-Left: " << V-> Left -> Balance << endl;
             // case 2: left left cases
            singleRightRotate(V);

            Display(); // display the table tree
            showTree(); // display the map tree

         } else if (V-> Left -> Balance > 0 ) {
             // display the balance factor left node.
             cout << "DRR-Parent-Left: " << V-> Left -> Balance << endl;
             // case 4: left right case
            doubleRightRotate(V);

             Display(); // display the table tree
             showTree(); // display the map tree
         } // end of if statement.
    } // end of if statement.

} // end of fixIt function.
