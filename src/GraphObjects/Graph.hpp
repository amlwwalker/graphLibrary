// # 2014 Walking Software
#ifndef __GRAPH_HPP_
#define __GRAPH_HPP_

#include <vector>
#include <map>
#include <string.h>
#include "Node.hpp"
#include "Edge.hpp"


namespace graphDB{
	class Graph {

	public:
		Graph();
		std::vector <Node*> *getNodes() { return nodeReference;}
		std::vector <Edge*> *getEdges() { return edgeReference;}
		void addNode(Node *n){nodeReference->push_back(n);}
		void addEdge(Edge *e){edgeReference->push_back(e);}
		std::vector <Edge*>getEdgesOnNode(Node *n);
		void printNodes();
		void printEdges();
		Node* findNodeWithId(std::string id);
		Edge* findEdgeWithId(std::string id);
		std::string printNodesToJson(std::vector<Node*> nodes, int length = 0);
		std::string printNodeToJson(Node *n);
		std::string printEdgesToJson(std::vector<Edge*> edges, int length = 0);
		std::string printEdgeToJson(Edge *n);
		std::string printEverything(std::vector<Node*> nodes, std::vector<Edge*> edges, int length = 0);
		void getNeighbouringNodes(Node *n, std::vector<Node*> &nodes);
		void reorganise(std::vector<Node*> nodes);
	private:
		std::vector <Node*> *nodeReference;
		std::vector <Edge*> *edgeReference;
		//vector <int> nodesPrinted = new(vector<int>);

	};
}
#endif