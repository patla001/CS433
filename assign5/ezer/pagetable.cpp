#include <vector>
#include <string>
#include <array>
#include <iostream>

#include <fstream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <unordered_set>

#include "pagetable.h"


using namespace std;
// TODO: Add your implementation of PageTable
// PURPOSE: PageTable constructor
PageTable::PageTable()
{
    unsigned int page_size=0;
	//int page_size;
	// the physical memory in bits
	int phys_mem_bits=0;
	// the remainder of the number of page
	int page_offset_bits=0;
	// number of pages
	int num_pages=0;
	// number of frames
	int num_frames=0;
	// number of faults
	int totalFaults=0;
	// number of lines
	int totalReferences=0;
} // end of PageTable constructor.

// PURPOSE: PageEntry constructor
PageEntry::PageEntry()
{
	int address = 0;
	int page_number = 0;
	int frame_number = 0;
	int last = 0;
	int valid = false;
	int dirty = false;

} // end of PageEntry constructor.

// PURPOSE: Search Function allows the page number value
// to be search in the pgTable vector.
// if found it outputs the index number; however, if is not found
// it outputs -1 value.
// PARAMETER: the integer value represent the page number.
int PageTable::search(int value)
{

    for (int i = 0; i < pgTable.size(); i++)
    {

        if (pgTable[i].page_number == value)
        {
            return i;
        }
    }

    return -1;
} // end search function

// PURPOSE: Test1 Function runs the FIFO scheme
// to demonstrate how static page replacement algorithm works.
// We are using a small file containing 100 logical address.
// PARAMETER: numberFrames is size of frames integer given from the user input.
// number Frames size =
void PageTable::Test1(int numberFrames)
{
    unordered_set<int> s;

    // To store the pages in FIFO matter
    queue<int> indexes;
	int page_faults=0;
    int frame_number = 0;
	int totalReferences = 0;
    PageEntry pg;
    // read the text file
	ifstream file("small_refs.txt");
	string line;
    while (file >> line)
    {
        int value = stoi(line);
        int pageNumber = value/page_size;

        // check if the set can hold more pages

        if (s.size() < numberFrames)
        {

            if (s.find(pageNumber) == s.end())

            {
                // insert the current page into the set
                s.insert(pageNumber);

                // increment page fault
                page_faults++;

                // Push the current page into the queue
                indexes.push(pageNumber);
                // update the object with the page number, frame number,..etc.
                pg.address = value;
                pg.page_number = pageNumber;
                pg.frame_number = frame_number;
                pg.last = 0;
                pg.valid = true;
                pg.dirty = true;
                // store in the pgTable vector
                pgTable.push_back(pg);

                // print the information to the user
                cout << "Logical address: " << pg.address;
                cout << ", 	";
                cout << "page number: " << pg.page_number;
                cout << ", 	";
                cout << "frame number = " << pg.frame_number;
                cout << ", 	";
                cout << "is page fault? " << pg.dirty << endl;
                // increment the frame number
                frame_number++;

            } else {
                // search the page number and find the index number for the
                // pgTable vector
                int index = search(pageNumber);
                if (index != -1)
                {
                    // print the information to the user
                    // update the dirty
                    pgTable[index].dirty=0;
                    cout << "Logical address: " << pgTable[index].address;
                    cout << ", 	";
                    cout << "page number: " << pgTable[index].page_number;
                    cout << ", 	";
                    cout << "frame number = " << pgTable[index].frame_number;
                    cout << ", 	";
                    cout << "is page fault? " << pgTable[index].dirty << endl;
                }

            }
        } else {
            // Check if current page is not already
            // present in the set
            if (s.find(pageNumber) == s.end())
            {
                // Store the first page in the
                // queue to be used to find and
                // earse the page from the set
                int val = indexes.front();

                // Pop the first page from the queue
                indexes.pop();

                // Remove the indexes page from the set
                s.erase(val);

                // insert the current page in the set
                s.insert(pageNumber);

                // push the current page into
                // the queue
                indexes.push(pageNumber);
                // update the object with the page number, frame number,..etc.
                pg.address = value;
                pg.page_number = pageNumber;
                pg.frame_number = frame_number;
                pg.last = 0;
                pg.valid = true;
                pg.dirty = true;
                // store in the pgTable vector
                pgTable.push_back(pg);

                // print the information to the user
                cout << "Logical address: " << pg.address;
                cout << ", 	";
                cout << "page number: " << pg.page_number;
                cout << ", 	";
                cout <<  "frame number = " << pg.frame_number;
                cout << ", 	";
                cout << "is page fault? " << pg.dirty << endl;
                // increment the frame number
                frame_number++;
                // Increment page Faults
                page_faults++;
            }
        }
        // count the number of logical address lines from the text file.
        totalReferences++;
    }

    cout << "Number of references: " << totalReferences << endl;
    cout << "Number of page faults: " << page_faults << endl;
    cout << "Number of page replacements: " << 0 << endl;
} // end of Test1 Function using FIFO
