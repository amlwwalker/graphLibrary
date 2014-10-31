#include "Node.hpp"

//a node can have a label and this is added with the function addLabel
void Node::addLabel(string labelName){
	labels.push_back(labelName);
}

//function to add properties to nodes
void Node::addProperty(string propertyName, string propertyValue){
	properties[propertyName] = propertyValue;
}

//whenever an edge is created between two nodes, those nodes need to know about it

//if the node is a starting point, then it sends an edge
void Node::sendEdge(string edgeName){
	sentEdges.push_back(edgeName);
}

//if the node receives an edge from another node, then it receives an edge.
void Node::receiveEdge(string edgeName){
	receivedEdges.push_back(edgeName);
}