#include "Node.hpp"



//a node can have a label and this is added with the function addLabel
void Node::addLabel(string labelName){
	labels.push_back(labelName);
}

//function to add properties to nodes
void Node::addProperty(string propertyName, string propertyValue){
	properties[propertyName].push_back( propertyValue );
}

// //whenever an edge is created between two nodes, those nodes need to know about it

// vector <*Edge> Node::getOutgoingEdges(){
// 	return sentEdges;
// }

// vector <*Edge> Node::getIncomingEdges(){
// 	return receivedEdges;
// }

vector <Edge*> Node::getAllEdges(){
	return allEdges;
}

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

map <string, vector <string> > Node::getProperties(){
	return properties;
}
vector <string> Node::getLabels(){
	return labels;
}

void Node::printNode(){

	cout<<"------------------------------------------------------------------------------------------"<<endl;
	string the_name = getProperty("name")[0];
	cout<<"Details for Node :"<<getProperty("name")[0]<<endl;

	cout<<"\tLabels: "<<endl; //COUT(getLabels());
		vector <string> labs = getLabels();
		cout<<"\t\t";
		for (int i=0; i<labs.size(); i++){ 
			cout<<labs[i]; if (i<labs.size()-1){ cout<<", ";  }
		}cout<<endl;

	cout<<"\tProperties: "<<endl; //mapCOUT(getProperties());
		map <string, vector<string> > Props = getProperties();
		// cout<<"\t\t";

		int ccount = -1;
		for ( const auto &myPair : Props ) {
        	std::cout <<"\t\t"<<myPair.first<<": ";
        	ccount += 1;
        	for (int i=0; i<myPair.second.size(); i++){
        		cout<<myPair.second[i]<<" ";
        	}
        	cout<<endl;
        } cout<<endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<" Edges: "<<endl;
    for (int i=0; i<allEdges.size(); i++){
    	Edge *curr_edge = allEdges[i];
    	string curr_type = curr_edge -> getTypes()[0];
    	Node node1 = *(curr_edge -> getEnd1());
    	Node node2 = *(curr_edge -> getEnd2());
    	cout<<"\t\t"<<node1.getProperty("name")[0]<< " "<<curr_type<<" "<<node2.getProperty("name")[0]<<endl;    
    } cout<<endl;



     cout<<"------------------------------------------------------------------------------------------"<<endl;

}
