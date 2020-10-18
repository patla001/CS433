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

    string command;
    int countChar(char buffer[]);

    vector<string> history;

    
    // executing Shell commands

    void execShell(char * args[], char buffer[]);
    void parseline(char buffer[], char * args[]);

    void displayHistory();
    void execPipe(char * args[]);
    void execUserCommand(char * arg[]);
    void saveCommand(char command[]);
    bool isUserCommand(char * args[]);
    UnixShell();


};
