// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//-----------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class PCB
{
 private:
  int key;      // key
  string firstName;  // customer first name
  string lastName; // customer last name
  string phone; // phone number
  string username; // username
  string password; // password
  string jobtitle; // jobtitle
  string jobtype; // jobtype


 public:

  PCB();  // to create a blank el_t object
  PCB(int, string, string, string, string, string, string, string); // to create an initialized el_t object

  bool operator==(PCB);  // overload == for search
  bool operator!=(PCB);  // overload != for search
  // In search == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?
  // operator != to the client refers that is not the same as the node element

  // this overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const PCB&);

  friend class htable;  // client of this class is htable which needs access to the key part of el_t

};
