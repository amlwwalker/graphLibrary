#ifndef __GRAPH_HPP_
#define __GRAPH_HPP_

#include <vector>
#include <map>
#include <string.h>
#include "Node.hpp"
#include "Edge.hpp"


using namespace std;

class Graph {

public:

	void printNodes(vector<Node*> nodeList);
	void printEdges(vector<Edge*> edgeList);
private:
	vector <Node*> nodeList; 
	vector <Edge*> edgeList;
};
#endif