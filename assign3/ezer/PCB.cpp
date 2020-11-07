// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "PCB.h"

// blank element
PCB::PCB()
{
  string name;
  id = -1;
  priority = -1;
  burst = -1;
  tatime = -1;
  wtime = -1;
  remainder = -1;
}

// initializing constructor to create an PCB object
PCB::PCB(string tname, int tid, int tpriority, int tburst, int ttatime, int twtime, int tremainder)
{
  name = tname;
  id = tid;
  priority = tpriority;
  burst = tburst;
  tatime = ttatime;
  wtime = twtime;
  remainder = tremainder;

}

// overload == for search based on the key part only
bool PCB::operator==(PCB OtherOne)
{
  if (id == OtherOne.id) return true; else return false;
}

// overload != for search based on the key part only
bool PCB::operator!=(PCB OtherOne)
{
  if (id != OtherOne.id) return true; else return false;
}
// overload >= for the algorithm
bool PCB::operator>=(PCB OtherOne)
{
   if (priority >= OtherOne.priority) return true; else return false;
}

// overload > for the algorithm
bool PCB::operator>(PCB OtherOne)
{
   if (priority > OtherOne.priority) return true; else return false;	
}

// overload <= for the algorithm
bool PCB::operator<=(PCB OtherOne)
{
	 if (priority <= OtherOne.priority) return true; else return false;
}

// overload < for the algorithm
bool PCB::operator<(PCB OtherOne)
{
	if (priority < OtherOne.priority) return true; else return false;
}

