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
		/// Returns a pointer to a vector of pointers to all the nodes in the graph
		std::vector <Node*> *getNodes() { return nodeReference;}

		/// Returns a pointer to a vector of pointers to all the edges in the graph
		std::vector <Edge*> *getEdges() { return edgeReference;}

		/// Adds a node to the graph
		void addNode(Node *n){nodeReference->push_back(n);}

		/// Adds many nodes to the graph
		void addNodes(std::vector <Node*> *Nodes);

		/// Adds an edge to the graph
		void addEdge(Edge *e){edgeReference->push_back(e);}

		/// Returns a vector with pointers to all the edges associated with this node
		std::vector <Edge*>getEdgesOnNode(Node *n);

		
		/// Returns a vector with pointers to all the edges leaving this node
		std::vector <Edge*>getOutgoingEdgesOnNode(Node *n);

		/// Returns a vector with pointers to all the edges coming into this node
		std::vector <Edge*>getIncomingEdgesOnNode(Node *n);

		/// prints info on each node in json format
		void printNodes();

		/// prints info on each edge in json format	
		void printEdges();

		/// Return pointer to the node with a certain id
		Node* findNodeWithId(std::string id);

		/// Return pointer to the edge with a certain id
		Edge* findEdgeWithId(std::string id);

		/// Return pointer to the node with a certain name (remember names are assumed unique);
		Node* findNodeWithName(std::string name);

		/// creates json with node info for d3
		std::string printNodesToJson(std::vector<Node*> nodes, int length = 0);

		/// creates json with single node info for d3
		std::string printNodeToJson(Node *n);

		/// creates json with edges info for d3
		std::string printEdgesToJson(std::vector<Edge*> edges, int length = 0);

		/// creates json with single edge info for d3
		std::string printEdgeToJson(Edge *n);

		/// creates json with all info
		std::string printEverything(std::vector<Node*> nodes, std::vector<Edge*> edges, int length = 0);

		/// Returns vector with pointers to all nodes associated with the node;
		void getNeighbouringNodes(Node *n, std::vector<Node*> &nodes);

		/// Returns vector with pointers to all nodes associated with the node, as well as the type of node that this happens with
		void getFullNeighbouringNodes(Node *n, std::vector<Node*> &nodes, std::vector <Edge*> &joined_by);

		/// Returns vector with pointers to all nodes to which current node has outgoing edges 
		void getNodesFromNode(Node *n, std::vector<Node*> &nodes);

		/// Returns vector with pointers to all nodes from which we can get to current code via incoming edges 
		void getNodesToNode(Node *n, std::vector<Node*> &nodes);

		/// a d3-related function that deals with the 'group' parameter
		void reorganise(std::vector<Node*> nodes);

		// function for us

		/// Get vector with pointers to all Nodes that have a certain property value
		std::vector <Node*> findNodesWithProperty(std::string key, std::string value);

		/// count the names of nodes //SOS add by reference -- the c++11 fails in compilation
		void printNodeNames(std::vector <Node*> Nodes);

		// Node * copyNodeForUser(Node *fromNode) {

		// 	Node *copyNode;
		// 	copyNode = new(Node);
		// 	copyNode->setName( fromNode->getName() );
		// 	copyNode->setCopyPointer( fromNode ); 
		// }

	private:
		std::vector <Node*> *nodeReference;
		std::vector <Edge*> *edgeReference;
		//vector <int> nodesPrinted = new(vector<int>);

	};
}
#endif