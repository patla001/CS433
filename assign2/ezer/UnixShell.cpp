#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include <array>
#include <sstream>
#include "UnixShell.h"

using namespace std;


//PURPOSE: This function counts the total
// number of characters inside the array.
//PARAMETERS: buffer [] = the command.
//
int UnixShell::countChar(char buffer[])
{
    int i = 0;
    // buffer tokenized using loop.
    char * p = strtok(buffer, " ");
    // while loop and stops until is NULL.
    while (p != NULL) {
        // it nulls the pointer
        p = strtok(NULL, " ");
        i++;
    }
    // save the total number of characters.
    return i;
}
//PURPOSE: This function parses the buffer into arguments.
//PARAMETERS: buffer [] = the command.
//            args[] = the arguments in the command.
void UnixShell::parseline(char buffer[], char * args[])
{
    int i = 0;
    // buffer tokenized using loop.
    char * p = strtok(buffer, " ");

    while (p != NULL) {
        args[i] = p;
        //printf("%d %s\n", i, p);
        p = strtok(NULL, " ");
        i++;
    }

    // if command has ampersand at the end of arguments
    if (strcmp(args[i - 1], "&") == 0)
    {
        args[i - 1] = NULL;
        ampersand = true;
    } else {
        // terminated argmument list with null.
        args[i] = NULL;
        ampersand = false;
    }

}

void UnixShell::displayHistory()
{
    // The array will print empty if there is no history.
    if (history.empty())
    {
        cout << "history is empty" << endl;
    }
    else {

        int start = 0;
        // display history

        for (int i = start; i < history.size(); i++)
        {
            cout << " " << i + 1 << " " << history[i] << endl;
        }
    }
}

// the execUserCommand function uses command that does not belong to the
// Unix commands.
void UnixShell::execUserCommand(char * arg[])
{

    string command(arg[0]);

    if (command == "exit")
    {
        running = false;
    } else if (command == "history")
    {
        displayHistory();
    }

    else  {
        // intialize the variables
        char buffer[MAX];
        char * args[MAX / 2 + 1];
        int N;

        if (command == "!!")
        {
            // if the history is empty
            if (history.empty())
            {
                cout << "No commands in history" << endl;
                return;
            }
            // total number of commands
            N = history.size();
        } else {

            string temp = command.substr(1, command.length());
            N = atoi(temp.c_str());
            // it shows the last command
            int min = (history.size() < 10) ? 0 : history.size() - 10;

            if (N > history.size() || N < min + 1)
            {
                cout << " No such command in history" << endl;
                return;
            }
        }

        cout << history[N-1] << endl;


        // it copy another array to read the arguments correctly.
        strcpy(buffer, history[N-1].c_str());
        // saves the commands into array
        saveCommand(buffer);
        // convert the array vector into character vector.
        parseline(buffer, args);
        // execute the command under previous history.
        execShell(args,buffer);
    }



}
// execute history command or exit the program
bool UnixShell::isUserCommand(char * arg[])
{

    string command(arg[0]);

    if (command == "exit" || command == "history" )
    {
        return true;
    }
    // command is a shell command;
    return false;

}
// save the history from the user's terminal.
void UnixShell::saveCommand(char command[])
{
	string save(command);
    history.push_back(save);
}


// execShell implements the fork(), wait(), execvp() and dup2().
void UnixShell::execShell(char * args[], char buffer[] )
{

    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1); // it exits the program.
    } else if (rc == 0) {
        // this is the child if statement.
        int processID = getpid();
        printf("hello, I am child (pid:%d)\n", processID);
        // child: redirect standard output to a file



        // determines the correct size of the array characters.
        int i = countChar(buffer);

        // if the user executes output command greather than it will implement
        // true in the if statement.
        if (strcmp(args[i - 2], ">") == 0)
        {
            // it opens the output file.
            int fd = open(args[i-1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
            if (fd == -1 ) // if the file fails it exits.
            {
                // prints the error inside the file.
                perror(args[0]);
                exit(1);
            }
            dup2(fd, 1);   // make stdout go to file.

            close(fd);      // closes the open file.

            execvp(args[0], args); // executes the command inside the child
            // prints the error if the unix command does not exists.
            printf("command not found, please kill the process: PID is (%d)\n ", processID);
        } else {
            // else there is no input or output text
            execvp(args[0], args);
            // prints the error if the unix command does not exists.
            printf("command not found, please kill the process: PID is (%d)\n ", processID);
        }


    } else {
            // parent goes down this path
            // this is the wait function. It waits then it will exit the program.
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
        rc, rc_wait, (int) getpid());
    }

}

UnixShell::UnixShell()
{
    running = true;
    ampersand = false;
}
