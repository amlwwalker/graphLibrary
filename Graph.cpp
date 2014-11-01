
#include "Graph.hpp"

void Graph::printNodes(){
	for (int i = 0; i < nodeReference.size(); i++) {
		cout << "\nNode; ID: " << nodeReference[i]->getId() << endl;

		vector <string> tempLabels = nodeReference[i]->getLabels();

		for (int j = 0; j < tempLabels.size(); j++){
			cout << "\tLabel: " << j << " : " << tempLabels[j] << endl;
		}
		
		cout << "Properties:" << endl;
		//print the properies
		map<string, vector<string>> tempProperties = nodeReference[i]->getProperties();
		 for (map<string, vector<string>>::iterator it=tempProperties.begin(); it!=tempProperties.end(); ++it) {
		 		//we now have the vector. Now loop over that....
		 			for (int j = 0; j < it->second.size(); j++){
						cout << "\t\t"<< it->first << " : " << it->second[j] << endl;
					}
		 }

		 cout << "Edges:" << endl;
		 vector <Edge*> listOfEdges = nodeReference[i]->getAllEdges();
		 for (int j = 0; j < listOfEdges.size(); j++) {
		 	//need a property of an edge

		 	cout << "ID: " << listOfEdges[j]->getId() << endl;
		 }
	}
}

void Graph::printEdges() {
	for (int i = 0; i < edgeReference.size(); i++) {
		//print out its types
		vector <string> tempTypes = edgeReference[i]->getTypes();
		for (int j = 0; j < tempTypes.size(); j++){
			cout << "\nEdge:\nType: " << tempTypes[j] << endl;
		}
		cout << "Properties:" << endl;
		//print out its properties
		map<string, vector<string>> tempProperties = edgeReference[i]->getProperties();
		 for (map<string, vector<string>>::iterator it=tempProperties.begin(); it!=tempProperties.end(); ++it) {
		 		//now have the vector. Now loop over that....
		 			for (int j = 0; j < it->second.size(); j++){
						cout << "\t\t"<< it->first << " : " << it->second[j] << endl;
					}
		 }
		//print out where it comes from
    	cout << "FROM: " << edgeReference[i]->getFrom()->getId();
    	//print out where it goes to
    	cout << " --> TO: " << edgeReference[i]->getTo()->getId() << endl;
	}	
}