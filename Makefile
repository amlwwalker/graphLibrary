# 2014 Walking Software

PROG = graphdb
CXX = g++
CC = gcc
CFLAGS = -W -Wall -I../.. -pthread -g -O0 $(CFLAGS_EXTRA)
CXXFLAGS = -std=c++11

# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CSOURCES = $(call rwildcard,./src/,*.c)
CXXSOURCES = $(call rwildcard,./src/,*.cpp) $(call rwildcard,./src/*/,*.cpp)

$(PROG): $(CSOURCES)
	$(CC) -c $(CSOURCES) $(CFLAGS)
	$(CXX) -c $(CXXSOURCES) $(CXXFLAGS)
	$(CXX) -o $(PROG) ./*.o

clean:
	rm -rf $(PROG) *.exe *.dSYM *.obj *.exp *.o *.lib *.out
