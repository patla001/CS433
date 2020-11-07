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

int main(int argc, char *argv[])
{
    std::cout << "CS 433 Programming assignment 3" << std::endl;
    std::cout << "Author: Ezer Patlan and Cody Chadler" << std::endl;
    std::cout << "Date: 11/06/2020" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : read a text file and apply Priority method" << std::endl;
    std::cout << "=======================================================" << std::endl; 
    // Check that input file is provided at command line
    if(argc < 2 ) {
        cerr << "Usage: " << argv[0] << " <input_file> [<time_quantum>]" << endl;
        exit(1);
    }

    std::cout << "///////////////Input Table/////////////////////////////" << std::endl;	
    // Read task name, priority and burst length from the input file 
    string name;
    int id = 1;
    int priority;
    int burst;
    int tt = 0;
    int wtime = 0;
    llist Q1; // initalize linked list queue
    // open the input file
    std::ifstream infile(argv[1]);
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
	X = PCB(name,id,priority,burst,tt,wtime,-1); 
    	
	// stores the object in the back of the linked list
	Q1.addRear(X);
	// increments the number of linked list been added.
	id++;
    }
     std::cout << "/////////////////////////////////////////////////////" << std::endl;
     // initialize the vector 
     std::vector<std::string> nameType = {"priority", "id"};
     // sort the priority parameter in the linked list object
     Q1.sort(nameType[0]);
     // calculate the turnaround time
     Q1.turnaroundTime();
     // sort the id parameter from the linked list in the descending order 
     Q1.sort(nameType[1]);
     // calculate the standard deviation and average for the turnaround time
     float stdtt = Q1.stdturningTime();	
     float avgtt = Q1.avgturningTime();
     // calculate the waiting time
     Q1.waitingTime();
     // calculate the standard deviation and average waiting time
     float avgwtime = Q1.avgwaitingTime();
     float stdwtime = Q1.stdwaitingTime();
     std::cout << "=======================================================" << std::endl;
     // display the table
     Q1.displayAll();
     
     // print the statistical analysis
     cout <<"--------------- Statistics -------------------------" << endl;
     cout <<"----------------------------------------------------"<< endl;
     cout << "Average Turnaround Time for Priority: " << avgtt << endl;
     cout << "Turnaround Time standard deviation: +/- " << stdtt << endl;
     cout <<"----------------------------------------------------"<< endl;
     cout << "Average Waiting Time for Priority: " << avgwtime << endl;
     cout << "Waiting Time standard deviation: +/- " << stdwtime << endl;

    return 0;
}
