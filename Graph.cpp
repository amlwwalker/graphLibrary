
#include "Graph.hpp"

vector <Edge*>Graph::getEdgesOnNode(Node *n) {
	return n->getAllEdges();
}

Node* Graph::findNodeWithId(string id){
	for (int i = 0; i < nodeReference.size(); i++){
		if (nodeReference[i]->getId() == id){
			return nodeReference[i];
		}
	}
	return NULL;
}

Edge* Graph::findEdgeWithId(string id){
	for (int i = 0; i < edgeReference.size(); i++){
		if (edgeReference[i]->getId() == id){
			return edgeReference[i];
		}
	}
	return NULL;
}

void Graph::printNodes() {
	string json = ""; 
	for (int i=0; i < nodeReference.size(); i++){
		nodeReference[i]->printNode();
	}
}

string Graph::printNodeToJson(Node *n) {
	string json = "{"+n->printNode()+"}";
	return json;
}
string Graph::printNodesToJson() {
	string json = "{ \"nodes\":{";
	for (int i=0; i < nodeReference.size(); i++){
		json += nodeReference[i]->printNode();
		if (i != nodeReference.size()-1) {
			json += ",";
		}
	}
	json += "}}";
	return json;
}

void Graph::printEdges() {
	for (int i = 0; i < edgeReference.size(); i++) {
		edgeReference[i]->printEdge();
	}	
}

string Graph::printEdgesToJson() {
	string json = "{ \"edges\":[";
	for (int i=0; i < edgeReference.size(); i++){
		json += edgeReference[i]->printEdge();
		if (i != edgeReference.size()-1) {
			json += ",";
		}
	}
	json += "]}";
	return json;
}

string Graph::printEdgeToJson(Edge *e) {
	string json = e->printEdge();
	return json;
}