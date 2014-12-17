// # 2014 Walking Software
#ifndef __BASE_GRAPH_HPP_
#define __BASE_GRAPH_HPP_

#include <vector>
#include <map>
#include <string.h>
#include "BaseNode.hpp"
#include "BaseEdge.hpp"


namespace graphDB{
	class BaseGraph {

	public:
		BaseGraph();
		///Returns the vector of Nodes of the graph
		std::vector <BaseNode*> *getNodes() { return nodeReference;}
		///Returns the vector of Edges of the graph
		std::vector <BaseEdge*> *getEdges() { return edgeReference;}
		///Adds a Node to the graph (only the graph object is able to do this)
		BaseNode *addNode(){BaseNode *n; n = new BaseNode(std::to_string(nodeCounter++)); nodeReference->push_back(n); return n;}
		///Adds a Edge to the graph (only the graph object is able to do this)
		BaseEdge *addEdge(){BaseEdge *e; e = new BaseEdge(std::to_string(edgeCounter++)); edgeReference->push_back(e); return e;}
		///Returns the edges attached to a specific node
		std::vector <BaseEdge*>getEdgesOnNode(BaseNode *n);
		///Prints out all nodes
		void printNodes();
		///Prints out all the edges
		void printEdges();
		///Finds and returns an node with a specific ID
		BaseNode* findNodeWithId(std::string id);
		///Finds and returns an edge with a specific ID
		BaseEdge* findEdgeWithId(std::string id);
		///Prints all the nodes in JSON format
		std::string printNodesToJson(std::vector<BaseNode*> nodes, int length = 0);
		///Prints a specific node in JSON format
		std::string printNodeToJson(BaseNode *n);
		///Prints all the edges in JSON format
		std::string printEdgesToJson(std::vector<BaseEdge*> edges, int length = 0);
		///Prints a specific edge in JSON format
		std::string printEdgeToJson(BaseEdge *n);
		///Prints all nodes and edges in JSON format
		std::string printEverything(std::vector<BaseNode*> nodes, std::vector<BaseEdge*> edges, int length = 0);
		///Takes a vector as a parameter and populates it with nodes attached to a specific node
		void getNeighbouringNodes(BaseNode *n, std::vector<BaseNode*> &nodes);
		///D3 specific - to remove once D3 is fixed
		void reorganise(std::vector<BaseNode*> nodes);
	private:
		int nodeCounter = 0;
		int edgeCounter = 0;
		std::vector <BaseNode*> *nodeReference;
		std::vector <BaseEdge*> *edgeReference;
		//vector <int> nodesPrinted = new(vector<int>);

	};
}
#endif