// # 2014 Walking Software
#include "BaseNode.hpp"

using namespace graphDB;

BaseNode::BaseNode(std::string id){
	this->id = id;
}
//a node can have a label and this is added with the function addLabel
void BaseNode::addLabel(std::string labelName){
	labels.push_back(labelName);
}

//function to add properties to nodes
void BaseNode::addProperty(std::string propertyName, std::string propertyValue){
	properties[propertyName].push_back( propertyValue );
}
//function to add array as a property to nodes
void BaseNode::addProperty(std::string propertyName, std::vector<std::string> &propertyValue){
	for (int i = 0; i < propertyValue.size(); i++) {
		properties[propertyName].push_back( propertyValue[i] );	
	}
	
}
// //whenever an edge is created between two nodes, those nodes need to know about it

// vector <*Edge> Node::getOutgoingEdges(){
// 	return sentEdges;
// }

// vector <*Edge> Node::getIncomingEdges(){
// 	return receivedEdges;
// }

std::vector <BaseEdge*> * BaseNode::getAllEdges(){
	return &edges;
}

std::vector <BaseEdge*> *BaseNode::getEdgesWithType(std::string type) {

	std::vector <BaseEdge*> *tempList;
	tempList = new(std::vector <BaseEdge*>);
	for (int i = 0; i < edges.size(); i++) {

		BaseEdge *tempEdge = edges[i];
		// for (int j = 0; j < tempEdge->getTypes().size(); j++) {
			// if (tempEdge->getTypes()[j] == type) {
			if (tempEdge->getType() == type) {
				tempList->push_back(tempEdge);
			}
		// }	
	}
	return tempList;
}

// vector <Edge*> *Node::getEdgesWithProperty(string propertyKey) {

// //going to return a vector from the edge because a property is an array.
// // Need to therefore add all the Edges with that property to the vector.	
// 	vector <Edge*> *tempList;
// 	tempList = new(vector <Edge*>);
// 	for (int i = 0; i < allEdges.size(); i++) {

// 		Edge *tempEdge = allEdges[i];
// 		for (int j = 0; j < tempEdge->getProperties.size(); j++) {
// 			if (tempEdge->getTypes()[j] == type) {
// 				tempList->push_back(tempEdge);
// 			}
// 		}	
// 	}
// 	return tempList;
// }

// void Node::addOutgoingEdge(Edge *the_edge) { 

// 	cout<<"added outgoing edge"<<endl;
	
// 	sentEdges.push_back(the_edge);
// 	allEdges.push_back(the_edge); 
// 	//if ( sentEdges_map.find("f") == sentEdges_map.end() ) {
// 	vector <string> edge_types = the_edge->getTypes();
// 	string to_node = the_edge->getEnd2();
// 	for (int i = 0; i < edge_types.size(); i++){
// 		string current_type = edge_types[i];
// 		sentEdges_map[current_type].push_back(to_node); //regardless of whether type i already exists in the map;
// 	}
// }

// void Node::addReceivingEdge(Edge *the_edge) { 

// 	cout<<"added incoming edge"<<endl;

// 	receivedEdges.push_back(the_edge); allEdges.push_back(the_edge); 
// 	//if ( receivedEdges_map.find("f") == receivedEdges_map.end() ) {
// 	vector <string> edge_types = the_edge->getTypes();
// 	string from_node = the_edge->getEnd2();
// 	vector <string> edge_types = the_edge.getTypes();
// 	for (int i = 0; i < edge_types.size(); i++){
// 		string current_type = edge_types[i];
// 		receivedEdges_map[current_type].push_back(from_node); //regardless of whether type i already exists in the map;
// 	}
// }

std::map <std::string, std::vector <std::string> > * BaseNode::getProperties(){
	return &properties;
}
std::vector <std::string> BaseNode::getLabels(){
	return labels;
}

std::string BaseNode::printNode(){

		std::vector <std::string> tempLabels = getLabels();

		std::string jsonLabels = "[";
		// cout << "Labels:" << endl << "\t\t";
		for (int j = 0; j < tempLabels.size(); j++){
			// cout << "[" << j << "] : " << tempLabels[j] << ", ";
			jsonLabels += "\""+tempLabels[j]+"\"";
			if (j != tempLabels.size()-1) {
				jsonLabels += ",";
			}
		}
		jsonLabels += "]";

		std::string jsonProperties = "{";
		//print the properies
		std::map<std::string, std::vector<std::string> > tempProperties = *getProperties();
		int position = 0; //to check if we have gone over all but one.
		 for (std::map<std::string, std::vector<std::string> >::iterator it=tempProperties.begin(); it!=tempProperties.end(); ++it) {
		 		//we now have the vector. Now loop over that....

		 	jsonProperties += "\""+it->first+"\":[";
		 	// cout << "\t\t" << it->first << " : ";
	 			for (int j = 0; j < it->second.size(); j++){
	 				jsonProperties += "\""+it->second[j]+"\"";
					// cout << it->second[j] << ", ";
					if (j != it->second.size()-1) {
						jsonProperties += ",";
					}

				}
			jsonProperties += "]";

			if (position < tempProperties.size()-1) {
				jsonProperties += ",";
			}

			position++;
		 }
		 jsonProperties += "}";
		 std::string jsonEdges = "[";
		 std::vector <BaseEdge*> listOfEdges = *getAllEdges();
		 for (int j = 0; j < listOfEdges.size(); j++) {
		 	jsonEdges += "\""+listOfEdges[j]->getId()+"\"";
			if (j != listOfEdges.size()-1) {
				jsonEdges += ",";
			}
		 }
		 jsonEdges += "]";

     std::string json = "{\"name\":\"" + getName() + "\",\" id \":\""+getId()+"\",\" group \":"+std::to_string(getGroup())+", \"labels\": "+ jsonLabels + ", \"properties\":" + jsonProperties + ", \"edges\":" + jsonEdges +"}";
     return json;
}
