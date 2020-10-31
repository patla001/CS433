// CS311 Yoshii - complete ** for Project client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: Project Hash
// Name: Ezer Patlan
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include "htable.h"


// This tester gets input data interactively but
// for a useful client, input should come from a file.
// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{

    htable T; // initialize hash thable
    el_t X; // initialize object
    int n = 0; // initialize key

    fstream fin; // initialize fin

    fin.open("profile2.txt", ios::in); // open csv file
    string id, firstName, lastName, phone, userName, line; // initialize the variables
    string password,jobTitle,jobType; // initialize the variables
    while (getline(fin, line)) {
        stringstream ss(line);
        getline(ss,id,',');
        getline(ss,firstName, ',');
        getline(ss,lastName, ',');
        getline(ss,phone,',');
        getline(ss,userName,',');
        getline(ss,password,',');
        getline(ss,jobTitle,',');
        getline(ss,jobType,',');

        // calling object
        X = el_t(n, firstName, lastName, phone, userName, password, jobTitle, jobType);
        // add the object into the hash table
        T.add(X);

    }
    // close csv file
    fin.close();

    // display the hash table
    T.displayTable();


    // find the correct key + name
    cout << "Find 6 members if our in our hash table: " << endl;
    int result[] = {7950, 7953, 9057, 98291, 29432, 83212};

    // Loop through KeyArray and find the
    for (int i = 0; i< 6; i++) {
        T.findKey(result[i]); // calling findKey function
    }



} // end of main projectclient program.
