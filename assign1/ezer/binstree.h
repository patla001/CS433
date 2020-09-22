// CS311: BST header file for HW4 - by Yoshii - DO NOT CHANGE!!
// This BST has an Up link to make it easy to go up the tree later
//------------------------------------------------------------

// tree element type is int for now
typedef int elem_t;   // elem_t is hidden from the client

// definition of what a Vertex is - also hidden from the client
struct Vertex
{
  Vertex *Up;  // points to the parent node
  Vertex *Left;
  elem_t  Elem;
  Vertex *Right;
  int Height;  // for EC
  int Balance;  // for EC
};

// this is set up to be inherited by another class
class BST
{

 public:

  BST();  // intializes Root
  ~BST();  // destructor calls dtraverse to destroy the dynamic tree

  // PURPOSE: these will show the vertices in IN order
  // TO CALL: No parameter  but provide a pointer to
  //          the root vertex in calling INorderTraversal
  void Display();
  void INorderTraversal(Vertex*); // recursive

  // Purpose: returns a map of the tree containg the direction of the tree right or left
  // and the balance factor values of each element in the node.
  // Parameters: Vertex V refers as the node of the tree. String indent is the
  // branches of the tree. bool last gives the orientation whether is right or left.
  void printTree(Vertex*, string, bool);
  void showTree();

  // PURPOSE: these will search in PRE order - same as Depth First
  // TO CALL: provide the element to search for; provide a pointer to
  //          the root vertex in calling PREorderSearch
  bool Search(elem_t);
  bool PREorderSearch(Vertex*, elem_t); // recursive

  // PURPOSE: This adds a new vertex into the BST
  // TO CALL: provide the element to be added to the tree
  void InsertVertex(elem_t);

  // PURPOSE: This deletes a vertex with the given element
  //     - calls remove and  findMax (see below)
  // TO CALL: provide the element to be removed from the tree
  void DeleteVertex(elem_t);


  // PURPOSE:  Climbs up from the vertex to compute Height and Balance Factor
  // TO CALL: provide each pointer to the current Vertex
  void climbUp(Vertex*);

  // the following can be inherited but not available to the client
 protected:

  Vertex *Root; //  Root which is a pointer to the root vertex

  // utility functions follow - these are not for the clients to use
  // These were created to implement the public methods

  void dtraverse(Vertex*);
  // traverse and delete all vertices in post order

  void remove(Vertex*, Vertex*);
  // removes the vertex knowing its parent

  elem_t findMax(Vertex*);  // finds the MAX element in the
  // left sub-tree of the vertex and also deletes it

  // PURPOSE: gets the maximum of two nodes
  // TO CALL: provides the left and right integer node
  int max(int, int);

  // PURPOSE: Calculates the height inside each node
  // TO CALL: provide each pointer to the current Vertex
  int height(Vertex*);


  // Purpose: rotate left at Vertex Parent
  // Parameter: Vertex Parent refers as the parent node.
  void singleLeftRotate(Vertex*);

  // Purpose: rotate right at Vertex Parent
  // Parameter: Vertex Parent refers to the node parent.
  void singleRightRotate(Vertex*);

  // Purpose: first rotate right at Vertex Parent, then rotate left at Vertex Parent.
  // Parameter: Vertex V refers as the parent node.
  void doubleLeftRotate(Vertex*);

  // Purpose: first rotate left at Vertex Parent, then rotate right at Vertex Parent
  // Parameter: Vertex V refers as the parent node.
  void doubleRightRotate(Vertex*);

  // PURPOSE: FixIt Identifies which case it is and call the correct rotation
  // function.
  // Parameter: Vertex V refers as the node that contains a balance factor -2 or 2 that
  // needs to be corrected in order to be balance tree.
  void fixIt(Vertex*);

}; // end of BST class
