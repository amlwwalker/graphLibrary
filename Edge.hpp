// #include "Node.hpp"

#ifndef __EDGE_HPP_
#define __EDGE_HPP_

#include <vector>
#include <map>
#include <string.h>

#include "Node.hpp"

using namespace std;

class Edge {

public:
		void printSomething(){ cout << "hello Denise" << endl;}
	  Node getEnd1(){return end1;}
	  Node getEnd2(){return end2;}
private:
	 vector<string>	types;
	map<string, string>		properties;
	 Node end1;
	 Node end2;
};

#endif