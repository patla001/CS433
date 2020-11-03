#include "PCB.h"
#include <iostream>
#include <string>
using namespace std; 

PCB::PCB()
{
	name = "";
	id = -1;
	priority = -1;
	burst = -1;
	TA_Time = -1;
	W_Time = -1;
} 

PCB::PCB(string procName, int procID, int procPriority, int CPUburst, int tat, int wt)
{
	name = procName;
	id = procID;
	priority = procPriority;
	burst = CPUburst;
	TA_Time = tat;
	W_Time = wt;
} 

bool PCB::operator==(PCB OtherOne)
{
	if (id == OtherOne.id) return true;
	else return false;
} 

bool PCB::operator!=(PCB OtherOne)
{
	if (id != OtherOne.id) return true;
	else return false;
} 

bool PCB::operator>=(PCB OtherOne)
{
	if (priority >= OtherOne.priority) return true; else return false;
	//	return priority >= OtherOne.priority;
}

bool PCB::operator>(PCB OtherOne)
{
	if (priority > OtherOne.priority) return true; else return false;
	//return priority < OtherOne.priority;
}

bool PCB::operator<=(PCB OtherOne)
{
	if (priority <= OtherOne.priority) return true; else return false;
}

bool PCB::operator<(PCB OtherOne)
{
	if (priority < OtherOne.priority) return true; else return false;
}

ostream& operator<<(ostream& os, const PCB& E)
{
	os << E.name << "+" << E.id << "+" << E.priority << "+" << E.burst;
	return os;
}