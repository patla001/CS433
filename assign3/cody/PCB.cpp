// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "PCB.h"

// blank element
PCB::PCB()
{
  char name = "";
  tid = -1;
  priority = -1;
  burst = -1;
}

// initializing constructor to create an el_t object
PCB::PCB(char tname, int tid, int tpriority, int tburst)
{
  name = tname;
  id = tid;
  priority = tpriority;
  burst = tburst;

}

// overload == for search based on the key part only
bool PCB::operator==(PCB OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

// overload != for search based on the key part only
bool PCB::operator!=(PCB OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout
ostream& operator<<(ostream& os, const PCB& E)
{
  os << E.key << "+" << E.firstName;
  return os;
}
