/**
 * Driver program 
 * 
 * Add other data structures and .cpp and .h files as needed.
 * 
 * The input file is in the format:
 *
 *  [name], [priority], [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "llist.h"


using namespace std;

void runPriorityRR(string filename, int QUANTUM)
{
    std::cout << "///////////////Input Table/////////////////////////////" << std::endl;	
    string name;
    int id = 1;
    int priority;
    int burst;
    int tt = 0;
    int wtime = 0;
    llist Q1; // initalize linked list queue
    // open the input file
    std::ifstream infile(filename);
    string line;
    while(getline(infile, line) ) {
        std::istringstream ss (line);
        // Get the task name
        getline(ss, name, ',');
        
        // Get the task priority 
        string token;
        getline(ss, token, ',');
        priority = std::stoi(token);

        // Get the task burst length 
        getline(ss, token, ',');
        burst = std::stoi(token);
        
        cout << name << " " << priority << " " << burst << endl;
	
	PCB X; // initialize object
	// add the input to the object
    	X = PCB(name,id,priority,burst,tt,wtime,burst); 
    	// stores the object in the back of the linked list  
	Q1.addRear(X);
	// increments the number of linked list been added.
	id++;
    }
     std::cout << "/////////////////////////////////////////////////////" << std::endl;
     // initialize the vector
     std::vector<std::string> nameType = {"priority", "id"};
     // sort out the priority by the highest value
     Q1.sort(nameType[0]);
     // calculate the Round Robin waiting time algorithm
     Q1.rrWaitingTime(QUANTUM);
     // calculate the Round Robin turnaround time
     Q1.rrTurnAroundTime(); 
     // calculate the average and standard deviation for the turnaround time
     float avgtt = Q1.avgturningTime();
     float stdtt = Q1.stdturningTime();
     // calculate the average and standard deviation for the waiting time
     float avgwtime = Q1.avgwaitingTime();
     float stdwtime = Q1.stdwaitingTime();
     std::cout << "=======================================================" << std::endl;
     // display the table
     Q1.displayAll();
     // print the statistical analysis
     cout <<"--------------- Statistics -------------------------" << endl; 
     cout <<"----------------------------------------------------"<< endl;
     cout << "Average Turnaround Time for Priority-RR: " << avgtt << endl;
     cout << "Turnaround Time standard deviation: +/- " << stdtt << endl;
     cout <<"----------------------------------------------------"<< endl;
     cout << "Average Waiting Time for Priority-RR: " << avgwtime << endl;
     cout << "Waiting Time standard deviation: +/- " << stdwtime << endl;
}


int main(int argc, char *argv[])
{
    std::cout << "CS 433 Programming assignment 3" << std::endl;
    std::cout << "Author: Ezer Patlan and Cody Chadler" << std::endl;
    std::cout << "Date: 11/06/2020" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : read a text file and apply Priority - Round Robin (RR) method" << std::endl;
    std::cout << "=======================================================" << std::endl;    
    // default quantum value 
    int QUANTUM = 10;


    // Check that input file is provided at command line
    if(argc < 2 ) {
         cerr << "Usage: " << argv[0] << " <input_file> [<time_quantum>]" << endl;
         exit(1);
    }

    // if the user calls the name of the program and the input file
    // the program calculates Priority-RR using quantum 10, since the user did not
    // specify which value quantum it is needed to calculate Priority-RR method.	
    if (argc == 2) {
         cout << "------------Default Quantum is 10----------------" << endl;
         string filename = argv[1];
	 // calls for Priority-Round Robin Function
         runPriorityRR(filename, QUANTUM);
    }


    // Read the time quantum if provided.
    if(argc >= 3) {
	string filename = argv[1];
        QUANTUM = atoi(argv[2]);
	cout << "---------------Your Quantum is " << QUANTUM << "----------------" << endl;
	// calls for Priority-Round Robin Function
	runPriorityRR(filename, QUANTUM);
    }

    // Read task name, priority and burst length from the input file 
    // TODO: Add your code to run the scheduler and print out statistics

    return 0;
} // end of the Priority-RR main program
