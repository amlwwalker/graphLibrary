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
		std::vector <BaseNode*> *getNodes() { return nodeReference;}
		std::vector <BaseEdge*> *getEdges() { return edgeReference;}
		BaseNode *addNode(){BaseNode *n; n = new BaseNode("1"); nodeReference->push_back(n); return n;}
		BaseEdge *addEdge(){BaseEdge *e; e = new BaseEdge("1"); edgeReference->push_back(e); return e;}
		std::vector <BaseEdge*>getEdgesOnNode(BaseNode *n);
		void printNodes();
		void printEdges();
		BaseNode* findNodeWithId(std::string id);
		BaseEdge* findEdgeWithId(std::string id);
		std::string printNodesToJson(std::vector<BaseNode*> nodes, int length = 0);
		std::string printNodeToJson(BaseNode *n);
		std::string printEdgesToJson(std::vector<BaseEdge*> edges, int length = 0);
		std::string printEdgeToJson(BaseEdge *n);
		std::string printEverything(std::vector<BaseNode*> nodes, std::vector<BaseEdge*> edges, int length = 0);
		void getNeighbouringNodes(BaseNode *n, std::vector<BaseNode*> &nodes);
		void reorganise(std::vector<BaseNode*> nodes);
	private:
		std::vector <BaseNode*> *nodeReference;
		std::vector <BaseEdge*> *edgeReference;
		//vector <int> nodesPrinted = new(vector<int>);

	};
}
#endif