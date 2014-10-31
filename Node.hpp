
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



using namespace std;

class Edge;

class Node {

public:
	void addLabel(string labelName);
	void addProperty(string propertyName, string propertyValue);
	void sendEdge(string edgeName);
	void receiveEdge(string edgeName);

private:
	vector <string> labels;
	// vector <vector <string> > Properties;
	map <string, string> properties;
	vector <Edge> sentEdges;
	vector <Edge> receivedEdges;

};

#endif