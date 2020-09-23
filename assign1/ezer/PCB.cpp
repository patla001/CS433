#include "PCB.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
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
    countTable = 0; // indicate an empty count queue
    //string state = "";
	//for (int pid = 0; pid < MAX_SIZE; pid++){
    //      table.push_back(PCB(pid,ProcState::NEW,0));
 	//}


} // end of PCBTable constructor.

PCBTable::~PCBTable()
{
    //delete[] table;
    //PCB table[MAX_SIZE];
    // int sizeTemp = countTable;
    // for (int pid = 0; pid < sizeTemp; pid++){
    //     delete table[pid];
    //     countTable--;
 	// }
    //
    // if (countTable == 0)
    // {
    //     cout << "PCB Table Empty" << endl;
    // }
}


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



void PCBTable::MakeTable(int size)
{

    for (int pid = 0; pid < size; pid++){
        //table.push_back(PCB(pid,ProcState::NEW,pid));
        PCB newPCB = PCB(pid+1,ProcState::NEW,pid+1);
        table[pid] = newPCB;
        countTable++;
 	}


}


void PCBTable::MakeTableRandom(int size)
{

    std::random_device rd;
	std::mt19937 mt_rand(rd());


    for (int pid = 0; pid < size; pid++){
        //table.push_back(PCB(pid,ProcState::NEW,pid));


        PCB newPCB = PCB(pid+1,ProcState::NEW,mt_rand() % 50);
        table[pid] = newPCB;
        countTable++;


 	}


}

void PCBTable::displayPCBTable()
{
    cout <<  "--------------------------------------------------" << endl;
    cout <<  "------------------PCB Table-----------------------" << endl;
    cout <<  "--------------------------------------------------" << endl;
    cout <<  "Proc ID " << "\t" << "State" << "\t\t" << "Priority" << endl;
    cout <<  "--------------------------------------------------" << endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << table[i].id << "\t\t";
        switch (table[i].state)
        {
            case ProcState::NEW : std::cout << "New"; break;
            case ProcState::READY : std::cout << "Ready"; break;
            case ProcState::RUNNING : std::cout << "Running"; break;
            case ProcState::WAITING : std::cout << "Waiting"; break;
            case ProcState::TERMINATED : std::cout << "Terminated"; break;
        }

        cout << "\t\t" << table[i].priority << endl;

    } // end of for-loop
} // end of displayPCBTable function.

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
