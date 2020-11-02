// CS311 Yoshii - complete ** for Project client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: Project Hash
// Name: Ezer Patlan
// File type: client hw8client.cpp (tester)
//===========================================

//using namespace std;
#include <iostream>
#include <cstdlib>
//#include<bits/stdc++.h>
#include "llist.h"

//using namespace std;
// This tester gets input data interactively but
// for a useful client, input should come from a file.
// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{

    PCB X; // initialize object
    llist Q1; // initalize linked list queue
    X = PCB("P1", 4, 1, 3);
    
    Q1.addRear(X);



} // end of main projectclient program.
