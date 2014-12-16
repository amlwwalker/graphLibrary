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

std::vector <Edge*>Graph::getOutgoingEdgesOnNode(Node *n) {
	return n->getAllOutgoingEdges();
}

std::vector <Edge*>Graph::getIncomingEdgesOnNode(Node *n) {
	return n->getAllIncomingEdges();
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
	// for(std::vector<Node*>::iterator it = nodes.begin(); it !=nodes.end(); ++it){
	// 	std::cout << "Node ID: " << (*it)->getGroup() << std::endl;
	// }
	//delete(nodes);
}

void Graph::getFullNeighbouringNodes(Node *n, std::vector<Node*> &nodes, std::vector <Edge*> &joined_by) {
	std::vector<Edge*> edges = getEdgesOnNode(n);
	
	nodes.push_back(n);
	for(std::vector<Edge*>::iterator it = edges.begin(); it !=edges.end(); ++it){
		//check which end n is of the edge
		if ((*it)->getFrom() != n) {
			nodes.push_back((*it)->getFrom());
			joined_by.push_back(*it);
		} else {
			nodes.push_back((*it)->getTo());
			// joined_by.push_back((*it)->getType());
			joined_by.push_back(*it);
		}
	}
	// for(std::vector<Node*>::iterator it = nodes.begin(); it !=nodes.end(); ++it){
	// 	std::cout << "Node ID: " << (*it)->getGroup() << std::endl;
	// }
	//delete(nodes);
}

void Graph::getNodesFromNode(Node *n, std::vector<Node*> &nodes) {
	std::vector<Edge*> edges = getOutgoingEdgesOnNode(n);
	
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

void Graph::getNodesToNode(Node *n, std::vector<Node*> &nodes) {
	std::vector<Edge*> edges = getIncomingEdgesOnNode(n);
	
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

Node* Graph::findNodeWithName(std::string name){

	for(std::vector<Node*>::iterator it = nodeReference->begin(); it != nodeReference->end(); ++it) {
		if ((*it)->getName() == name){
			return (*it);
		}
	}
	return NULL;
}

void Graph::addNodes(std::vector <Node*> *Nodes){
	// int oldsize = *nodeReference.size();
	int oldsize = nodeReference->size();
	nodeReference -> resize(oldsize + Nodes->size());
	copy(Nodes->begin(), Nodes->end(),nodeReference->begin()+oldsize);
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
		std::string tmpjson = (*it)->printNode();
		std::cout << tmpjson<< std::endl;
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

//Print nodes to json. I'm not sure why we need the length parameter **
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

//Print everything to json. I'm not sure why we need the length parameter **

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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


std::vector <Node*> Graph::findNodesWithProperty(std::string key, std::string value){

	std::vector <Node*> OutputNodes;

	// std::string * p;
	std::map <std::string, std::vector <std::string> > NodeProperties;

	for(std::vector<Node*>::iterator it = nodeReference->begin(); it != nodeReference->end(); ++it) {

		NodeProperties = (*it)->getProperties();
		// p = find(NodeProperties[key].begin(), NodeProperties[key].end(), value);
		if (find(NodeProperties[key].begin(), NodeProperties[key].end(), value) != NodeProperties[key].end()){
			// return (*it);
			OutputNodes.push_back(*it);
		}
	}
	return OutputNodes;
}


void printNodeNames(std::vector <Node*> Nodes){
	for (int i=0; i<Nodes.size(); i++){
	// for(std::vector<Node*>::iterator it = Nodes.begin(); it != Nodes.end(); ++it) {
		std::cout<<Nodes[i]->getName()<<std::endl;
	}
}
