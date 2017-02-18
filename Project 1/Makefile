# Project 1 Makefile
# ------------------
# Usage:
# - to build LQueue_driver: make LQueue_driver
# - to build runway: make runway
# - to clean up: make clean

# edit here if you need to change the C++ compiler flags
CXXFLAGS ?= -Wall -g --std=c++11
# this reminds make to link the C++ standard library
LDLIBS ?= -lstdc++

# by default, compile only the test driver
all: LQueue_driver

# compile the LQueue library
LQueue.o: LQueue.C LQueue.h

# compile the test driver
LQueue_driver: LQueue_driver.o LQueue.o

# compile the runway (runway.C has to exist)
runway: runway.o LQueue.o

clean:
	rm -f *.o LQueue_driver runway
