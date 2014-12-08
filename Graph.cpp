
#include "Graph.hpp"


Graph::Graph(){
	nodeReference = new(vector<Node*>);
	edgeReference = new(vector<Edge*>);
}
vector <Edge*>Graph::getEdgesOnNode(Node *n) {
	return n->getAllEdges();
}

vector<Node*> *Graph::getNeighbouringNodes(Node *n) {
	vector<Edge*> edges = getEdgesOnNode(n);
	vector<Node*> *nodes;
	nodes = new(vector<Node*>);
	nodes->push_back(n);
	for(std::vector<Edge*>::iterator it = edges.begin(); it !=edges.end(); ++it){
		//check which end n is of the edge
		if ((*it)->getFrom() != n) {
			nodes->push_back((*it)->getFrom());
		} else {
			nodes->push_back((*it)->getTo());
		}
	}
	for(std::vector<Node*>::iterator it = nodes->begin(); it !=nodes->end(); ++it){
		cout << "Node ID: " << (*it)->getGroup() << endl;
	}
	//delete(nodes);
	return nodes;
}

Node* Graph::findNodeWithId(string id){

	for(std::vector<Node*>::iterator it = nodeReference->begin(); it != nodeReference->end(); ++it) {
		if ((*it)->getId() == id){
			return (*it);
		}
	}
	return NULL;
}

Edge* Graph::findEdgeWithId(string id){
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

string Graph::printNodeToJson(Node *n) {
	string json = n->printNode();
	return json;
}

/* need a function that takes a list of Nodes and a list of Edges
It then reindexes them from 0.
It goes through the list of Edges checking for a match to the actual groul and replaces it with the new one.
If the group is exactly 1 after the previous (new) group then continue;
This is purely for D3. Groups are only used by D3.
*/
void Graph::reorganise(vector<Node*> nodes) {
	int count = -1;
	for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
		count++;
		(*it)->setGroup(count);
		
	}
}

string Graph::printNodesToJson(vector<Node*> nodes, int length) {
	string json = "{ \"nodes\":[";
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
string Graph::printEverything(vector<Node*> nodes, vector<Edge*> edges, int length) {
	string json = "";
	//is it efficient to do it like this? I think it is but it's not that elegant
	cout << "print everything" << endl;
	json += printNodesToJson(nodes, length);
	json = json.substr(0, json.size()-1); //remove the last character as we are concatenating edges next
	json += ",";
	json += printEdgesToJson(edges, length).erase(0,1); //remove the first character as this is not the first thing in the json
	cout << "finished print everything" << endl;
	return json;
}

void Graph::printEdges() {
	for(std::vector<Edge*>::iterator it = edgeReference->begin(); it != edgeReference->end(); ++it) {
		(*it)->printEdge();
	}	
}

string Graph::printEdgesToJson(vector<Edge*> edges, int length) {
	string json = "{ \"links\":[";
	for(std::vector<Edge*>::iterator it = edges.begin(); it != edges.end(); ++it) {
		json += (*it)->printEdge();
		if (it-edges.begin() != edges.size()-1) {
			json += ",";
		}
		cout << "printing edge: " << (*it)->getFrom()->getGroup() << " : " << (*it)->getTo()->getGroup() << endl;
	}
	json += "]}";
	return json;
}

string Graph::printEdgeToJson(Edge *e) {
	string json = e->printEdge();
	return json;
}