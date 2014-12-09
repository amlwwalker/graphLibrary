# Copyright (c) 2014 Cesanta Software
# All rights reserved

PROG = main
CXX = g++
CC = gcc
CFLAGS = -W -Wall -I../.. -pthread -g -O0 $(CFLAGS_EXTRA)
CXXFLAGS = -std=c++11
CSOURCES = ./*.c
CXXSOURCES = ./*.cpp

$(PROG): $(CSOURCES)
	$(CC) -c $(CSOURCES) $(CFLAGS)
	$(CXX) -c $(CXXSOURCES) $(CXXFLAGS)
	$(CXX) -o $(PROG) ./*.o

clean:
	rm -rf $(PROG) *.exe *.dSYM *.obj *.exp *.o *.lib *.out
