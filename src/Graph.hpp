// # 2014 Walking Software
#ifndef __GRAPH_HPP_
#define __GRAPH_HPP_

#include <vector>
#include <map>
#include <string.h>
#include "GraphObjects/Node.hpp"
#include "GraphObjects/Edge.hpp"


using namespace std;

class Graph {

public:
	Graph();
	vector <Node*> *getNodes() { return nodeReference;}
	vector <Edge*> *getEdges() { return edgeReference;}
	void addNode(Node *n){nodeReference->push_back(n);}
	void addEdge(Edge *e){edgeReference->push_back(e);}
	vector <Edge*>getEdgesOnNode(Node *n);
	void printNodes();
	void printEdges();
	Node* findNodeWithId(string id);
	Edge* findEdgeWithId(string id);
	string printNodesToJson(vector<Node*> nodes, int length = 0);
	string printNodeToJson(Node *n);
	string printEdgesToJson(vector<Edge*> edges, int length = 0);
	string printEdgeToJson(Edge *n);
	string printEverything(vector<Node*> nodes, vector<Edge*> edges, int length = 0);
	vector<Node*> *getNeighbouringNodes(Node *n);
	void reorganise(vector<Node*> nodes);
private:
	vector <Node*> *nodeReference;
	vector <Edge*> *edgeReference;
	//vector <int> nodesPrinted = new(vector<int>);

};
#endif