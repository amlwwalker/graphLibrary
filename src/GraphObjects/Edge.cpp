// # 2014 Walking Software
#include "Edge.hpp"


void Edge::setUpEdge(string aId, Node* aFromNode, Node *aToNode) {

		id = aId;
		fromNode = aFromNode;
		toNode = aToNode;
}

string Edge::printEdge() {
			//print out its types
		string jsonTypes = "[";
		vector <string> tempTypes = getTypes();
		for (int j = 0; j < tempTypes.size(); j++){
			jsonTypes += "\""+tempTypes[j]+"\"";
			if (j != tempTypes.size()-1) {
				jsonTypes += ",";
			}
		}
		jsonTypes += "]";
		string jsonProperties = "{";
		map<string, vector<string> > tempProperties = getProperties();
		int position = 0; //to check if we have gone over all but one.
		 for (map<string, vector<string> >::iterator it=tempProperties.begin(); it!=tempProperties.end(); ++it) {
		 		//we now have the vector. Now loop over that....

		 	jsonProperties += "\""+it->first+"\":[";
	 			for (int j = 0; j < it->second.size(); j++){
	 				jsonProperties += "\""+it->second[j]+"\"";
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

		 string jsonFrom = to_string(getFrom()->getGroup());
		 string jsonTo = to_string(getTo()->getGroup());
		 
		 string json = "{\"id\": \""+getId()+"\", \"type\":"+jsonTypes+", \"properties\":"+ jsonProperties+", \"source\":"+jsonFrom+",\"target\":"+jsonTo+", \"value\":"+to_string(getWeight())+"}";
    return json;
}