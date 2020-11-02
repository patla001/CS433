// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//-----------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class PCB
{
 //private:
 public:
  string name;      // name process
  int id; // id process
  int priority; // priority process
  int burst; // burst time


 public:

  PCB();  // to create a blank PCB object
  PCB(string name, int tid, int priority, int burst); // to create an initialized PCB object

  bool operator==(PCB);  // overload == for search
  bool operator!=(PCB);  // overload != for search
  // In search == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?
  // operator != to the client refers that is not the same as the node element

  // this overloads cout for the el_t object
  // This is a friend function since the receiver object is not PCB
  friend ostream& operator<<(ostream&, const PCB&);

  friend class schedule;  // client of this class is htable which needs access to the key part of PCB

};
