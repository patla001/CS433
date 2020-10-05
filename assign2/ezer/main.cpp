#include <iostream>
#include <cstdlib>
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
	osh.execShell();
}
