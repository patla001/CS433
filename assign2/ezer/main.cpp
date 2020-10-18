#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "UnixShell.h"

using namespace std;

int main(int argc, char* argv[]) {
	//Print basic information about the program
	std::cout << "CS 433 Programming assignment 1" << std::endl;
	std::cout << "Author: Ezer Patlan and Cody Chandler" << std::endl;
	std::cout << "Date: 10/14/2020" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : Program to Implement Unix Shell and History Feature" << std::endl;
	std::cout << "=================================" << std::endl;


	// TODO: Add your code for Test 1
	std::cout << "Performing Execution in Shell Commands" << std::endl;

    UnixShell osh;
	// infinative while loop
	while(osh.running)
	{
		// intitalize the variables
		char buffer[MAX];
		char bufferSave[MAX];
		char * args[MAX / 2 + 1];
		// Display in the terminal osh>>
		std:: cout << "osh>> ";
		std:: cout.flush();
		// character array
		std::cin.getline(buffer, MAX);
		strcpy(bufferSave, buffer);
		// parseline functions allows the user to
		// save the commands and arguments into an array
		osh.parseline(buffer, args);


		// save the commands to history array.
		osh.saveCommand(bufferSave);
		// if the the commands are non unix the if statement is true.
		if (osh.isUserCommand(args))
		{
			// execute the non unix commands.
			osh.execUserCommand(args);
		} else {

			// execute the unix commands.
			osh.execShell(args,bufferSave);
		}

	}// end of while loop.
};  // end of the main program.
