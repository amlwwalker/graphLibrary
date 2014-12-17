// # 2014 Walking Software
#include "Edge.hpp"

using namespace graphDB;

void Edge::setUpEdge(std::string aId, Node* aFromNode, Node *aToNode) {

		id = aId;
		fromNode = aFromNode;
		toNode = aToNode;
}

// template <typename T> 
// string convertToString(T val){
// 	stringstream convert;
// 	convert << val;
// 	string result;
// 	result = convert.str();
// 	return result;
// }

std::string Edge::printEdge() {
			//print out its types
		std::string jsonTypes = getType();
		
		std::string jsonProperties = "{";
		std::map<std::string, std::vector<std::string> > tempProperties = getProperties();
		int position = 0; //to check if we have gone over all but one.
		 for (std::map<std::string, std::vector<std::string> >::iterator it=tempProperties.begin(); it!=tempProperties.end(); ++it) {
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

		 std::string jsonFrom = std::to_string(getFrom()->getGroup());
		 std::string jsonTo = std::to_string(getTo()->getGroup());
		 
		 std::string json = "{\"id\": \""+getId()+"\", \"type\":"+jsonTypes+", \"properties\":"+ jsonProperties+", \"source\":"+jsonFrom+",\"target\":"+jsonTo+", \"value\":"+std::to_string(getWeight())+"}";
    return json;
}