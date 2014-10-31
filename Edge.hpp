// #include "Node.hpp"

#ifndef __EDGE_HPP_
#define __EDGE_HPP_

#include <vector>
#include <map>
#include <string.h>
#include "Node.hpp"

using namespace std;

class Node;

class Edge {

public:
	Node *getEnd1(){return end1;}
	Node *getEnd2(){return end2;}
	void setEnd1(Node *node) {end1 = node;}
	void setEnd2(Node *node) {end2 = node;}

	void addType(string typeName) { types.push_back(typeName); }
	void addProperty(string propertyKey, string propertyValue) { properties[propertyKey] = propertyValue; }

	vector<string> getTypes() { return types; }
	map<string, string> getProperties() { return properties; }
private:
	vector<string>	types;
	map<string, string>		properties;
	Node *end1;
	Node *end2;
};

#endif