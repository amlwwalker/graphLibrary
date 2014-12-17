// # 2014 Walking Software
#include "BaseGraph.hpp"

using namespace graphDB;

BaseGraph::BaseGraph(){
	nodeReference = new(std::vector<BaseNode*>);
	edgeReference = new(std::vector<BaseEdge*>);
}
std::vector <BaseEdge*>BaseGraph::getEdgesOnNode(BaseNode *n) {
	return n->getAllEdges();
}

void BaseGraph::getNeighbouringNodes(BaseNode *n, std::vector<BaseNode*> &nodes) {
	std::vector<BaseEdge*> edges = getEdgesOnNode(n);
	
	nodes.push_back(n);
	for(std::vector<BaseEdge*>::iterator it = edges.begin(); it !=edges.end(); ++it){
		//check which end n is of the edge
		if ((*it)->getFrom() != n) {
			nodes.push_back((*it)->getFrom());
		} else {
			nodes.push_back((*it)->getTo());
		}
	}
	for(std::vector<BaseNode*>::iterator it = nodes.begin(); it !=nodes.end(); ++it){
		std::cout << "Node ID: " << (*it)->getGroup() << std::endl;
	}
	//delete(nodes);
}

BaseNode* BaseGraph::findNodeWithId(std::string id){

	for(std::vector<BaseNode*>::iterator it = nodeReference->begin(); it != nodeReference->end(); ++it) {
		if ((*it)->getId() == id){
			return (*it);
		}
	}
	return NULL;
}

BaseEdge* BaseGraph::findEdgeWithId(std::string id){
	for(std::vector<BaseEdge*>::iterator it = edgeReference->begin(); it != edgeReference->end(); ++it) {
	
		if ((*it)->getId() == id){
			return (*it);
		}
	}
	return NULL;
}

void BaseGraph::printNodes() {
	for(std::vector<BaseNode*>::iterator it = nodeReference->begin(); it != nodeReference->end(); ++it) {
		(*it)->printNode();
	}
}

std::string BaseGraph::printNodeToJson(BaseNode *n) {
	std::string json = n->printNode();
	return json;
}

/* need a function that takes a list of Nodes and a list of Edges
It then reindexes them from 0.
It goes through the list of Edges checking for a match to the actual groul and replaces it with the new one.
If the group is exactly 1 after the previous (new) group then continue;
This is purely for D3. Groups are only used by D3.
*/
void BaseGraph::reorganise(std::vector<BaseNode*> nodes) {
	int count = -1;
	for(std::vector<BaseNode*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
		count++;
		(*it)->setGroup(count);
		
	}
}

std::string BaseGraph::printNodesToJson(std::vector<BaseNode*> nodes, int length) {
	std::string json = "{ \"nodes\":[";
		reorganise(nodes); //this must be called before graphing the data
	for(std::vector<BaseNode*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
    	json += (*it)->printNode();

		if (it-nodes.begin() != nodes.size()-1) {
			json += ",";
		}
    }
	json += "]}";
	return json;
}
std::string BaseGraph::printEverything(std::vector<BaseNode*> nodes, std::vector<BaseEdge*> edges, int length) {
	std::string json = "";
	//is it efficient to do it like this? I think it is but it's not that elegant
	std::cout << "print everything" << std::endl;
	json += printNodesToJson(nodes, length);
	json = json.substr(0, json.size()-1); //remove the last character as we are concatenating edges next
	json += ",";
	json += printEdgesToJson(edges, length).erase(0,1); //remove the first character as this is not the first thing in the json
	std::cout << "finished print everything" << std::endl;
	return json;
}

void BaseGraph::printEdges() {
	for(std::vector<BaseEdge*>::iterator it = edgeReference->begin(); it != edgeReference->end(); ++it) {
		(*it)->printEdge();
	}	
}

std::string BaseGraph::printEdgesToJson(std::vector<BaseEdge*> edges, int length) {
	std::string json = "{ \"links\":[";
	for(std::vector<BaseEdge*>::iterator it = edges.begin(); it != edges.end(); ++it) {
		json += (*it)->printEdge();
		if (it-edges.begin() != edges.size()-1) {
			json += ",";
		}
		std::cout << "printing edge: " << (*it)->getFrom()->getGroup() << " : " << (*it)->getTo()->getGroup() << std::endl;
	}
	json += "]}";
	return json;
}

std::string BaseGraph::printEdgeToJson(BaseEdge *e) {
	std::string json = e->printEdge();
	return json;
}