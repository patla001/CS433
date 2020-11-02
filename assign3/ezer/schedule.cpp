

using namespace std;
#include <iostream>
#include <string>
#include <cstdlib>
#include "schedule.h"

schedule::schedule()
{
	PCB X;
}

schedule::~schedule()
{
	for (int i=0; i< TSIZE; i++){
		if (table[i].isEmpty()) {
		}else {
			PCB x;
			table[i].deleteRear(x);
		}
	}
}




