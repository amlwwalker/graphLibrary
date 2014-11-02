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
	// Graph();
	vector <Node*> &getNodeReference() { return nodeReference;}
	vector <Edge*> &getEdgeReference() { return edgeReference;}
	void addNode(Node *n){nodeReference.push_back(n);}
	void addEdge(Edge *e){edgeReference.push_back(e);}
	vector <Edge*>getEdgesOnNode(Node *n);
	void printNodes();
	void printEdges();
	Node* findNodeWithId(string id);
	Edge* findEdgeWithId(string id);
	string printNodesToJson();
	string printNodeToJson(Node *n);
	string printEdgesToJson();
	string printEdgeToJson(Edge *n);
private:
	vector <Node*> &nodeReference = *new(vector<Node*>);
	vector <Edge*> &edgeReference = *new(vector<Edge*>);

};
#endif