
#include "Graph.hpp"

void Graph::printNodes(vector<Node*> nodeList){
	for (int i = 0; i < nodeList.size(); i++) {
		cout << "\nNode; ID: " << nodeList[i]->getId() << endl;

		vector <string> tempLabels = nodeList[i]->getLabels();

		for (int j = 0; j < tempLabels.size(); j++){
			cout << "\tLabel: " << j << " : " << tempLabels[j] << endl;
		}
		
		cout << "Properties:" << endl;
		//print the properies
		map<string, vector<string>> tempProperties = nodeList[i]->getProperties();
		 for (map<string, vector<string>>::iterator it=tempProperties.begin(); it!=tempProperties.end(); ++it) {
		 		//we now have the vector. Now loop over that....
		 			for (int j = 0; j < it->second.size(); j++){
						cout << "\t\t"<< it->first << " : " << it->second[j] << endl;
					}
		 }

		 cout << "Edges:" << endl;
		 vector <Edge*> listOfEdges = nodeList[i]->getAllEdges();
		 for (int j = 0; j < listOfEdges.size(); j++) {
		 	//need a property of an edge

		 	cout << "ID: " << listOfEdges[j]->getId() << endl;
		 }
	}
}

void Graph::printEdges(vector<Edge*> edgeList) {
	for (int i = 0; i < edgeList.size(); i++) {
		//print out its types
		vector <string> tempTypes = edgeList[i]->getTypes();
		for (int j = 0; j < tempTypes.size(); j++){
			cout << "\nEdge:\nType: " << tempTypes[j] << endl;
		}
		cout << "Properties:" << endl;
		//print out its properties
		map<string, vector<string>> tempProperties = edgeList[i]->getProperties();
		 for (map<string, vector<string>>::iterator it=tempProperties.begin(); it!=tempProperties.end(); ++it) {
		 		//now have the vector. Now loop over that....
		 			for (int j = 0; j < it->second.size(); j++){
						cout << "\t\t"<< it->first << " : " << it->second[j] << endl;
					}
		 }
		//print out where it comes from
    	cout << "FROM: " << edgeList[i]->getFrom()->getId();
    	//print out where it goes to
    	cout << " --> TO: " << edgeList[i]->getTo()->getId() << endl;
	}	
}