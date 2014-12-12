// # 2014 Walking Software
#include "Graph.hpp"

using namespace graphDB;

Graph::Graph(){
	nodeReference = new(std::vector<Node*>);
	edgeReference = new(std::vector<Edge*>);
}
std::vector <Edge*>Graph::getEdgesOnNode(Node *n) {
	return n->getAllEdges();
}

void Graph::getNeighbouringNodes(Node *n, std::vector<Node*> &nodes) {
	std::vector<Edge*> edges = getEdgesOnNode(n);
	
	nodes.push_back(n);
	for(std::vector<Edge*>::iterator it = edges.begin(); it !=edges.end(); ++it){
		//check which end n is of the edge
		if ((*it)->getFrom() != n) {
			nodes.push_back((*it)->getFrom());
		} else {
			nodes.push_back((*it)->getTo());
		}
	}
	for(std::vector<Node*>::iterator it = nodes.begin(); it !=nodes.end(); ++it){
		std::cout << "Node ID: " << (*it)->getGroup() << std::endl;
	}
	//delete(nodes);
}

Node* Graph::findNodeWithId(std::string id){

	for(std::vector<Node*>::iterator it = nodeReference->begin(); it != nodeReference->end(); ++it) {
		if ((*it)->getId() == id){
			return (*it);
		}
	}
	return NULL;
}

Edge* Graph::findEdgeWithId(std::string id){
	for(std::vector<Edge*>::iterator it = edgeReference->begin(); it != edgeReference->end(); ++it) {
	
		if ((*it)->getId() == id){
			return (*it);
		}
	}
	return NULL;
}

void Graph::printNodes() {
	for(std::vector<Node*>::iterator it = nodeReference->begin(); it != nodeReference->end(); ++it) {
		(*it)->printNode();
	}
}

std::string Graph::printNodeToJson(Node *n) {
	std::string json = n->printNode();
	return json;
}

/* need a function that takes a list of Nodes and a list of Edges
It then reindexes them from 0.
It goes through the list of Edges checking for a match to the actual groul and replaces it with the new one.
If the group is exactly 1 after the previous (new) group then continue;
This is purely for D3. Groups are only used by D3.
*/
void Graph::reorganise(std::vector<Node*> nodes) {
	int count = -1;
	for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
		count++;
		(*it)->setGroup(count);
		
	}
}

std::string Graph::printNodesToJson(std::vector<Node*> nodes, int length) {
	std::string json = "{ \"nodes\":[";
		reorganise(nodes); //this must be called before graphing the data
	for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
    	json += (*it)->printNode();

		if (it-nodes.begin() != nodes.size()-1) {
			json += ",";
		}
    }
	json += "]}";
	return json;
}
std::string Graph::printEverything(std::vector<Node*> nodes, std::vector<Edge*> edges, int length) {
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

void Graph::printEdges() {
	for(std::vector<Edge*>::iterator it = edgeReference->begin(); it != edgeReference->end(); ++it) {
		(*it)->printEdge();
	}	
}

std::string Graph::printEdgesToJson(std::vector<Edge*> edges, int length) {
	std::string json = "{ \"links\":[";
	for(std::vector<Edge*>::iterator it = edges.begin(); it != edges.end(); ++it) {
		json += (*it)->printEdge();
		if (it-edges.begin() != edges.size()-1) {
			json += ",";
		}
		std::cout << "printing edge: " << (*it)->getFrom()->getGroup() << " : " << (*it)->getTo()->getGroup() << std::endl;
	}
	json += "]}";
	return json;
}

std::string Graph::printEdgeToJson(Edge *e) {
	std::string json = e->printEdge();
	return json;
}