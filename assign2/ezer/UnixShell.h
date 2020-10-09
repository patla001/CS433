#pragma once
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class UnixShell {
public:
    bool running;
    bool ampersand;
    
    // executing Shell commands

    void execShell(char * args[]);
    void parseline(char buffer[], char * args[]);
    void execPipe(char * args[]);
    void execUserCommand(char* arg[]);
    void saveCommand(char command[]);
    bool isUserCommand(char * arg[]);
    UnixShell();


};
