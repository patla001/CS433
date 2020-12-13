// Remember to add comments to your code

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <chrono>
#include <unordered_set>
#include "pagetable.h"
using namespace std;

// Check if an integer is power of 2
bool isPowerOfTwo(unsigned int x)
{
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x & (x - 1)));
}

int main(int argc, char* argv[]) {
	//Print basic information about the program
	std::cout << "=================================================================" << std::endl;
	std::cout << "CS 433 Programming assignment 5" << std::endl;
	std::cout << "Author: Ezer Patlan and Cody Chalder" << std::endl;
	std::cout << "Date: 12/11/2020" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : Program to simulate different page replacement algorithms" << std::endl;
	std::cout << "=================================================================\n" << std::endl;

	if (argc < 3) {
		// user does not enter enough parameters
		std::cout << "You have entered too few parameters to run the program.  You must enter" << std::endl
			<< "two command-line arguments:" << std::endl
			<< " - page size (in bytes): between 256 and 8192, inclusive" << std::endl
			<< " - physical memory size (in megabytes): between 4 and 64, inclusive" << std::endl;
		exit(1);
	}

	// Page size and Physical memory size
	// Their values should be read from command-line arguments,
	// and always a power of 2
	unsigned int page_size = atoi(argv[1]);
	if(!isPowerOfTwo(page_size))
	{
		std::cout << "You have entered an invalid parameter for page size (bytes)" << std::endl
			<< "  (must be an power of 2 between 256 and 8192, inclusive)." << std::endl;
		return 1;
	}
	// convert from MB to bytes
	unsigned int phys_mem_size = atoi(argv[2]) << 20;
	if(!isPowerOfTwo(phys_mem_size))
	{
		std::cout << "You have entered an invalid parameter for physical memory size (MB)" << std::endl
			<< "  (must be an even integer between 4 and 64, inclusive)." << std::endl;
		return 1;
	}

	// calculate number of pages and frames;
	// 27-bit logical memory
	// (128 MB logical memory assumed by the assignment)
	int logic_mem_bits = 27;
	// Num of bits for physical memory addresses,
	// calculated from physical memory size,
	// e.g. 24 bits for 16 MB memory
	int phys_mem_bits = std::log2(phys_mem_size);
	// Num of bits for page offset, calculated from page size,
	// e.g. 12 bits for 4096 byte page
	int page_offset_bits = std::log2(page_size);
	// Number of pages in
	// logical memory = 2^(logic_mem_bits - page_bit)
	int num_pages = 1 << (logic_mem_bits - page_offset_bits);
	// Number of free frames in
	// physical memory = 2^(phys_mem_bits - page_offset_bits)
	int num_frames = 1 << (phys_mem_bits - page_offset_bits);

	std::cout << "Page size = " << page_size << " bytes" << std::endl;
	std::cout << "Physical Memory size = " << phys_mem_size << " bytes" << std::endl;
	std::cout << "Number of pages = " << num_pages << std::endl;
	std::cout << "Number of physical frames = " << num_frames << std::endl;

	// Intialize the Page Table Class
	PageTable assign5;
	assign5.phys_mem_bits = phys_mem_bits;
	assign5.page_size = page_size;
	assign5.num_frames = num_frames;
	assign5.selection = 3;

	auto begin = std::chrono::high_resolution_clock::now();
	switch (assign5.selection)
	{
		case 0:
				// Test 1: Read and simulate the small list of logical addresses from the input file "small_refs.txt"
				std::cout <<"\n================================Test 1==================================================\n";
				// TODO: Add your code here for test 1 that prints out logical page #, frame # and whether page fault for each logical address

				assign5.Test1(num_frames);
				break;
		case 1:

				// Test 2: Read and simulate the large list of logical addresses from the input file "large_refs.txt"
				std::cout <<"\n================================Test 2==================================================\n";

				std::cout << "****************Simulate FIFO replacement****************************" << std::endl;
				// TODO: Add your code to calculate number of page faults using FIFO replacement algorithm
				// TODO: print the statistics and run-time
				//auto begin = std::chrono::high_resolution_clock::now();
				assign5.FIFO(num_frames);
				//auto end = std::chrono::high_resolution_clock::now();
				//assign5.elapsed = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
				//cout << "elapsed time: " << assign5.elapsed << " ms" << endl;
				break;
		case 2:

				std::cout << "****************Simulate Random replacement****************************" << std::endl;
				// TODO: Add your code to calculate number of page faults using Random replacement algorithm
				// TODO: print the statistics and run-time
				break;
		case 3:

				std::cout << "****************Simulate LRU replacement****************************" << std::endl;
				// TODO: Add your code to calculate number of page faults using LRU replacement algorithm
				// TODO: print the statistics and run-time
				//auto begin = std::chrono::high_resolution_clock::now();
				assign5.LRU(num_frames);
				//auto end = std::chrono::high_resolution_clock::now();
				//assign5.elapsed = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
				//cout << "elapsed time: " << assign5.elapsed << " ms" << endl;
				break;
	}
	auto end = std::chrono::high_resolution_clock::now();
	assign5.elapsed = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	cout << "elapsed time: " << assign5.elapsed << " ms" << endl;
}
