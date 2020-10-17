#pragma once
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 100;

class UnixShell {
public:
    bool running;
    bool ampersand;
    bool saveHistory;
    //int pid;
    string command;
    //int processID;
    vector <UnixShell> history2;
    vector<string> history;
    vector<string> helper;
    string tempHistory;
    // executing Shell commands

    void execShell(char * args[], bool saveHistory, char buffer[]);
    void parseline(char buffer[], char * args[]);
    //UnixShell(string command, int pid);
    void displayHistory();
    void execPipe(char * args[]);
    void execUserCommand(char * arg[]);
    void saveCommand(char command[]);
    bool isUserCommand(char * args[]);
    UnixShell();


};
