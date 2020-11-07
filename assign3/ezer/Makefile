###################################
# OS COURSE - CS 433 example
# 
###################################
CC = g++			# use g++ for compiling c++ code or gcc for c code
CFLAGS = -g -Wall -std=c++11	# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lm			# linked libraries	
LDFLAGS = -L.			# link flags
PROG = fcfs sjf priority rr priorityRR  # target executables (output)
SRCS = schedule_fcfs.cpp schedule_sjf.cpp schedule_priority.cpp schedule_rr.cpp schedule_priorityRR.cpp PCB.cpp llist.cpp
OBJ = $(SRCS:.cpp=.o) 	# object files for the target. Add more to this and next lines if there are more than one source files.

all : $(PROG) depend

fcfs: schedule_fcfs.o PCB.o llist.o
	$(CC) -o fcfs schedule_fcfs.o PCB.o llist.o $(LDFLAGS) $(LIB)

rr: schedule_rr.o PCB.o llist.o
	$(CC) -o rr schedule_rr.o PCB.o llist.o $(LDFLAGS) $(LIB)

sjf: schedule_sjf.o PCB.o llist.o
	$(CC) -o sjf schedule_sjf.o PCB.o llist.o $(LDFLAGS) $(LIB)

priority: schedule_priority.o PCB.o llist.o
	$(CC) -o priority schedule_priority.o PCB.o llist.o $(LDFLAGS) $(LIB)

priorityRR: schedule_priorityRR.o PCB.o llist.o
	$(CC) -o priorityRR schedule_priorityRR.o PCB.o llist.o $(LDFLAGS) $(LIB)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
	
depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;

#include .depend

# cleanup
clean:
	/bin/rm -f *.o $(PROG) .depend

# DO NOT DELETE
