#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include <array>
#include "UnixShell.h"

using namespace std;

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


// Cody's implement execUserCommand
// we need to provide a history command in order to cancel or terminate the
// processes. We need at least 10 previous history commands from the user.
// Please look over isaychris from Github as a reference
// to help you build the function.
// https://github.com/isaychris/CS433/blob/master/CS433_Lab2/Shell.cpp
void UnixShell::execUserCommand(char* arg[])
{
    // Cody's code
}
// execute history command or exit the program
bool UnixShell::isUserCommand(char * arg[])
{
    // Cody's code
}
// save the history from the user's terminal.
void UnixShell::saveCommand(char command[])
{
	string save(command);
	history.push_back(save);
}


// Ezer's work on the execPipe Function.
// PURPOSE: This function executes a shell command.
// PARAMETERS: args[] = the arguments in the command.
void UnixShell::execPipe(char * args[])
{

    // arguments for commands; your parser would be responsible for
    // setting up arrays like these

    //char  *cat_args[] = {"cat","Testing.txt", NULL};
    //char  *grep_args[] = {"grep","fork()", NULL};

    // make 1 pipe (cat to grep ); each has fds

    int pipes[2];
    // sets up 1st pipe
    pipe(pipes);

    // we now have 2 fds:
    // pipe[0] = read end of cat-> grep pipe (read by grep)
    // pipe[1] = write end of cat -> grep pipe (written by cat)

    // Note that the code in each if is basically identical, so you
    // could set up a loop to handle it. The differences are in the
    // indicies into pipes used for the dup2 system call
    // and that the 1st and last only deal with the end of one pipe.


    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
	    //int pipes[2];
        //pipe(pipes);
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        // replace cat's stdout with write part of 1st pipe
        dup2(pipes[1],1);
        // close all pipes (very important!); end we're using was safely copied
        close(pipes[0]);
        close(pipes[1]);

        //execvp(*cat_args, cat_args);
        execvp(args[0], args);

    } else if ( rc > 0 )
    {
        // parent goes down this path (main)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
            dup2(pipes[0],0);
            close(pipes[0]);
            close(pipes[1]);

            //execvp(*grep_args, grep_args);
            execvp(args[0], args);


        if (ampersand == false )
        {
            // only the parent gets here and waits for 3 children to finish
            close(pipes[0]);
            close(pipes[1]);
            printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
            rc, wait(NULL), (int) getpid());
        }


    }


}

// For the moment we are using the execShell to executive the commands without the pipe.
void UnixShell::execShell(char * args[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        // child: redirect standard output to a file
        //close(STDOUT_FILENO);
        //open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        // now exec "wc"...
        //char* myargs[3];
        //myargs[0] = strdup("wc");   // program: wc (word count)
        //myargs[1] = strdup("UnixShellTest.cpp"); // arg: file to count
        //myargs[2] = NULL;           // mark end of array
        execvp(args[0], args);  // runs word count
        printf("this shouldn’t print out");
    } else {
            // parent goes down this path (main
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
