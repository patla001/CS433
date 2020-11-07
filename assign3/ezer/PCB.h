//-----------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class PCB
{
 public:
  string name;      // name process
  int id; // id process
  int priority; // priority process
  int burst; // burst time
  int tatime; // turnaround time
  int wtime; // waiting time
  int remainder; // remainder time


  PCB();  // to create a blank PCB object
  PCB(string name, int id, int priority, int burst, int tatime, int wtime, int remainder); // to create an initialized PCB object

  bool operator==(PCB);  // overload == for search
  bool operator!=(PCB);  // overload != for search
  bool operator>=(PCB);  // overload >= for sorting
  bool operator>(PCB);   // overload <= for sorting
  bool operator<(PCB);   // overload < for sorting 
  bool operator<=(PCB); // overload <= for sorting


};
