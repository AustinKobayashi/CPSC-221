# Project 2 Makefile
# ------------------
# Usage:
# - to build tests: make tests
# - to build main: make main
# - to clean up: make clean

# edit here if you need to change the C++ compiler flags
CXXFLAGS ?= -Wall -g --std=c++11 -I.

# this reminds make to link the C++ standard library
LDLIBS ?= -lstdc++

COMMON_OBJECTS = string_bst.o max_heap.o text_item.o util.o

all: main

# compile the tests
#tests: ${COMMON_OBJECTS} tests.o test/test_counting_bst.o test/test_freq_heap.o test/test_tokenizer.o

# compile the main program
main: ${COMMON_OBJECTS} main.o

clean:
	rm -f *.o main