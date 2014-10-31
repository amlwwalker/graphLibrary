#include "Node.hpp"



//a node can have a label and this is added with the function addLabel
void Node::addLabel(string labelName){
	labels.push_back(labelName);
}

//function to add properties to nodes
void Node::addProperty(string propertyName, string propertyValue){
	properties[propertyName] = propertyValue;
}

// void Node::addEdge(Edge the_edge){
// 	cout<<"test"<<endl;
// }

// void Node::addEdge(Edge the_edge){

// 	if (name == the_edge.end1){
// 		sentEdges.push_back(the_edge);
// 	}else{
// 		receivedEdges.push_back(the_edge);
// 	}

// 	allEdges.push_back(the_edge);

// }

// //whenever an edge is created between two nodes, those nodes need to know about it

// //if the node is a starting point, then it sends an edge
// void Node::sendEdge(string edgeName){
// 	//sentEdges.push_back(edgeName);
// }

// //if the node receives an edge from another node, then it receives an edge.
// void Node::receiveEdge(string edgeName){
// 	//receivedEdges.push_back(edgeName);
// }

vector <Edge> Node::getOutgoingEdges(){
	return sentEdges;
}

vector <Edge> Node::getIncomingEdges(){
	return receivedEdges;
}

vector <Edge> Node::getAllEdges(){
	return allEdges;
}


// vector <Edge> Node::getAllEdges(){

// 	vector <Edge> AB;
// 	// AB.reserve( receivedEdges.size() + sentEdges.size() ); // preallocate memory
// 	// AB.insert( AB.end(), receivedEdges.begin(), receivedEdges.end() );
// 	// AB.insert( AB.end(), sentEdges.begin(), sentEdges.end() );
// 	return AB;
// }

map <string, string> Node::getProperties(){
	return properties;
}
vector <string> Node::getLabels(){
	return labels;
}

void Node::printNode(){

	cout<<"Details for Node :"<<id<<endl;

	cout<<"\tLabels: "<<endl; //COUT(getLabels());
		vector <string> labs = getLabels();
		cout<<"\t\t";
		for (int i=0; i<labs.size(); i++){ 
			cout<<labs[i]; if (i<labs.size()-1){ cout<<", ";  }
		}cout<<endl;
	cout<<"\tProperties: "<<endl; //mapCOUT(getProperties());
		map <string, string> Props = getProperties();
		cout<<"\t\t";
		for (map<string,string>::iterator it=Props.begin(); it!=Props.end(); ++it)
	    std::cout << it->first << " => " << it->second << '\n';
	// cout<<"Incoming Edges: "<<endl; COUT(N.getIncomingEdges());
	// cout<<"Outgoing Edges: "<<endl; COUT(N.getOutgoingEdges());

}
