// # 2014 Walking Software
#ifndef __NODE_HPP_
#define __NODE_HPP_

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm> 
#include <iterator>
#include <string.h>
#include <stdio.h>
#include <numeric>
#include <map>
#include "Edge.hpp"
using namespace std;

class Edge;

class Node {

public:

	void setId(string id){ this->id = id; }
	string getId(){ return id;}
	void addLabel(string labelName);
	void addProperty(string propertyName, string propertyValue);
	void addProperty(string propertyName, vector<string> propertyValue);
	void addEdge (Edge *the_edge){ allEdges.push_back(the_edge); }
	void setGroup(uint64_t group) { this->group = group;}
	uint64_t getGroup() { return group;}
	// void addOutgoingEdge(Edge *the_edge);
	// void addReceivingEdge(Edge *the_edge);

	// vector <*Edge> getOutgoingEdges();
	// vector <*Edge> getIncomingEdges();
	vector <Edge*> getAllEdges();
	vector <Edge*> *getEdgesWithType(string type);

	// map <string, vector <*Edge> > getOutgoingMap(){ return sentEdges_map; }
	// map <string, vector <*Edge> > getIncomingMap(){ return receivedEdges_map; }

	map <string, vector <string> > getProperties();
	vector <string> getLabels();
	vector <string> getProperty(string PropertyName){ 
		map <string, vector <string> > all_properties = getProperties();
		vector <string> property = all_properties[PropertyName];
		return property;
	}

	string printNode();

	
private:
	string id;
	uint64_t group;
	vector <string> labels;
	map <string, vector <string> > properties;
	vector <Edge*> allEdges;

};

#endif