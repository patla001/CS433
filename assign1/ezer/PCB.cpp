#include "PCB.h"
#include <iostream>
#include <vector>
using namespace std;
// TODO: Add your implementation here

// blank element
PCB::PCB()
{
    //id = -1;
    //state = "";
    //priority = -1;
}

// initializing constructor to create an PCB object
//PCB::PCB(int aid, const ProcState &state, int priority)
PCB::PCB(int aid, ProcState astate, int apriority)
{
    id = aid;
    state = astate;
    priority = apriority;
}




//PCBTable::PCBTable(int tableSize, string state)
PCBTable::PCBTable()
{
    //front = 0; // indicate an empty front queue
    //rear = -1; // indicate an empty rear queue
    //count = 0; // indicate an empty count queue
    //string state = "";
	//for (int pid = 0; pid < MAX_SIZE; pid++){
    //      table.push_back(PCB(pid,ProcState::NEW,0));
 	//}


} // end of PCBTable constructor.


// void PCBTable::add(PCB pcbPtr)
// {
//         //int MAX_SIZE = 30;
//         //rear=(rear+1) % MAX_SIZE;
//         //table[rear]=pcbPtr;
//         table.push_back(pcbPtr);
//         count++;
//
// } // end of add function.

// bool PCBTable::isEmpty()
// {
//     if (count == 0) {
//         return true;
//     } else {
//         return false;
//     } // end of if statement.
//
// } // end of isEmpty function.
//
// bool PCBTable::isFull()
// {
//     if (count == MAX_SIZE)
//     {
//         return true;
//     } else {
//         false;
//     } // end of if statement.
// } // end of isFull statement.



//void PCBTable::MakeTable()
//{
    // string state = "Ready";
	// for (int pid = 0; pid < 30; pid++){
	//  	table.add(PCB(pid,state,pid));
    //     //table.push_back(PCB(pid,state,pid));
 	// }
    //return table;
    //for (int pid = 0; pid < MAX_SIZE; pid++){
    //     table.push_back(PCB(pid,ProcState::NEW,0));
 	//}


//}

// PCBTable::PCBTable()
// {
//     cout << "call PCBTable constructor" << endl;
//     //PCB X; // blank element is created
//     //vector<PCB> PCBTable_class_member;
//     //vector<PCB>::iterator Iter;
//     //PCBTable: PCBTable_class_member() {};
//
//     void PCBTable::add_element(PCB a)
//     {
//         PCBTable.push_back(a);
//     }
// }

// PCBTable::PCBTable()
// {
//     public:
//         PCB obj;
//         // Mutator
//         void setObj(PCB i)
//         {
//             obj = i;
//         }
//         // Accessor
//         PCB getObj() const
//         {
//             return obj;
//         }
// };


//PCBTable::PCBTable()
//{
        //
        // int arraySize = 30;
        // std::vector<PCB> T;
    	// T.reserve(arraySize);
        // string state = "Ready";
        // for (int i = 0; i < arraySize; i++){
    	// 	T.push_back(PCB(i,state,1));
    	// }
        //
        // std::cout << "PID" << "   " << "ProcState" << "   " << "Priority" << std::endl;
    	// for (int j = 0; j < arraySize; j++) {
    	// 	std::cout << T[j].id << "\t" << T[j].state << "\t\t" << T[j].priority << std::endl;
    	// }
        //
        // return T;

//};// end of constructor

// PCBTable::createTable()
// {
// //public:
//      int arraySize = 30;
//      table.reserve(arraySize);
//      return table;
//     //table.addFront(element);
// };
//
// void PCBTable::displayTable()
// {
//     std::cout << "PID" << "   " << "ProcState" << "   " << "Priority" << std::endl;
//     for (int j = 0; j < 30; j++) {
//     	std::cout << table[j].id << "\t" << table[j].state << "\t\t" << table[j].priority << std::endl;
//     }
// }
