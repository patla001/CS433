#pragma once
#include <vector>
#include <queue>
#include <iostream>
// Remember to add comments to your code
using namespace std;
// A page table entry
class PageEntry
{
public:

	// the logical address from the input text file
	int address;

	// page number represent the calculation from logical address / memory size
	int page_number;
	// Physical frame number for a given page
	int frame_number;

	int last;
	// valid bit represents whether a page is in the physical memory
	bool valid;
	// dirty bit represents whether a page is changed
	bool dirty;
	// constructor to create page entry
	PageEntry();

};



/**
 * \brief A page table is like an array of page entries. The size of the page table should equal to the number of pages in logical memory
 */
class PageTable
{
public:
	// TODO: Add your implementation of the page table here

	//queue<int> indexes;
	vector<PageEntry> pgTable;
	// the size of a page
	unsigned int page_size;
	//int page_size;
	// the physical memory in bits
	int phys_mem_bits;
	// the remainder of the number of page
	int page_offset_bits;
	// number of pages
	int num_pages;
	// number of frames
	int num_frames;
	// number of faults
	int totalFaults;
	// number of lines
	int totalReferences;

	PageTable();
	// Search for the frame numbers on teh PageEntry

	int search(int value);
	// FIFO Algorithm
	void Test1(int numberFrames);
};
