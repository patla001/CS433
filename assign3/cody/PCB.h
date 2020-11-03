#pragma once
#include <iostream>
#include <string> 

using namespace std; 

class PCB
{
	public:
		string name;
		int id;
		int priority;
		int burst;
		int TA_Time;
		int W_Time;

		PCB();
		PCB(string, int, int, int, int, int);
		bool operator==(PCB);
		bool operator!=(PCB);
		bool operator>=(PCB);  // overload <= for sorting
		bool operator>(PCB);   // overload <= for sorting
		bool operator<(PCB);
		bool operator<=(PCB);
		friend ostream& operator<<(ostream&, const PCB&);
};