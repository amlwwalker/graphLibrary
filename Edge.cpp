#include "Edge.hpp"


void Edge::setEdge(string aId, Node* aFromNode, Node *aToNode) {

		id = aId;
		fromNode = aFromNode;
		toNode = aToNode;
}

string Edge::printEdge() {
			//print out its types
		string jsonTypes = "[";
		vector <string> tempTypes = getTypes();
		for (int j = 0; j < tempTypes.size(); j++){
			// cout << "\nEdge:\nType:\t\t" << tempTypes[j] << endl;
			jsonTypes += "\""+tempTypes[j]+"\"";
			if (j != tempTypes.size()-1) {
				jsonTypes += ",";
			}
		}
		jsonTypes += "]";
		// cout << "Properties:" << endl;
		//print out its properties
		string jsonProperties = "{";
		map<string, vector<string> > tempProperties = getProperties();
		int position = 0; //to check if we have gone over all but one.
		 for (map<string, vector<string> >::iterator it=tempProperties.begin(); it!=tempProperties.end(); ++it) {
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
			
			// cout << "position: " << position << " size: " << tempProperties.size() << endl;
			if (position < tempProperties.size()-1) {
				jsonProperties += ",";
			}

			// cout << endl;
			position++;
		 }
		 jsonProperties += "}";

		 string jsonFrom = getFrom()->getId();
		 string jsonTo = getTo()->getId();
		//print out where it comes from
    	// cout << "Direction:\t" << getFrom()->getId();
    	//print out where it goes to
    	// cout << " --> " << getTo()->getId() << endl;

    string json = "{ \"id\": \""+getId()+"\", \"type\":"+jsonTypes+", \"properties\":"+ jsonProperties+", \"from\":\""+jsonFrom+"\",\"to\":\""+jsonTo+"\"}";
    return json;
}