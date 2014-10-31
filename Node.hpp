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

using namespace std;


class Node {

public:

	//a node can have a label and this is added with the function addLabel
	void addLabel(string labelName){
		labels.push_back(labelName);
	}

	//function to add properties to nodes
	void addProperty(string propertyName, string propertyValue){
		properties[propertyName] = propertyValue;
	}

	//whenever an edge is created between two nodes, those nodes need to know about it

	//if the node is a starting point, then it sends an edge
	void sendEdge(string edgeName){
		sentEdges.push_back(edgeName);
	}

	//if the node receives an edge from another node, then it receives an edge.
	void receiveEdge(string edgeName){
		receivedEdges.push_back(edgeName);
	}

private:
	vector <string> labels;
	// vector <vector <string> > Properties;
	map <string, string> properties;

	vector <Edge> sentEdges;
	vector <Edge> receivedEdges;

};