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
#include "llist.h"


using namespace std;

int main(int argc, char *argv[])
{
    std::cout << "CS 433 Programming assignment 3" << std::endl;
    std::cout << "Author: Ezer Patlan and Cody Chadler" << std::endl;
    std::cout << "Date: 11/04/2020" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : read a text file and apply FCFS method" << std::endl;
    std::cout << "=================================" << std::endl;
    
    int QUANTUM = 10;
    // Check that input file is provided at command line
    if(argc < 2 ) {
        cerr << "Usage: " << argv[0] << " <input_file> [<time_quantum>]" << endl;
        exit(1);
    }

    // Read the time quantum if provided.
    if(argc >= 3) {
        QUANTUM = atoi(argv[2]);
    }

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
        
        //cout << name << " " << priority << " " << burst << endl;
        // TODO: add the task to the scheduler's ready queue
        // You will need a data structure, i.e. PCB, to represent a task 
	// e.g., void add(char *name, int priority, int burst)
	//
	
	PCB X; // initialize object
	//X = PCB("P1", 4, 1, 3);
    	X = PCB(name,id,priority,burst,tt,wtime); 
    	
	Q1.addRear(X);
	id++;
    }
     string nameType = "burst";
     Q1.sort(nameType);
     Q1.turnaroundTime();
     float avgtt = Q1.avgturningTime();
     Q1.waitingTime();
     float avgwtime = Q1.avgwaitingTime();
     Q1.displayAll();
 
     cout << "Average Turnaround Time: " << avgtt << endl;
     cout << "Average Waiting Time: " << avgwtime << endl;
	
    // TODO: Add your code to run the scheduler and print out statistics

    return 0;
}
