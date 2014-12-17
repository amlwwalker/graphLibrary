// # 2014 Walking Software
#include "BaseEdge.hpp"

using namespace graphDB;

BaseEdge::BaseEdge(std::string id){
	this->id = id;
} 
void BaseEdge::setUpEdge(std::string aName, BaseNode* aFromNode, BaseNode *aToNode) {

		aName = name;
		setFrom(aFromNode);
		setTo(aToNode);
}

void BaseEdge::setFrom(BaseNode *node) {
	fromNode= node;
	node->addEdge(this);
}
void BaseEdge::setTo(BaseNode *node) {
	toNode = node;
	node->addEdge(this);
}

std::string BaseEdge::printEdge() {
			//print out its types
		std::string jsonTypes = "[";
		std::vector <std::string> tempTypes = getTypes();
		for (int j = 0; j < tempTypes.size(); j++){
			jsonTypes += "\""+tempTypes[j]+"\"";
			if (j != tempTypes.size()-1) {
				jsonTypes += ",";
			}
		}
		jsonTypes += "]";
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
		 
		 std::string json = "{\"id\": \""+getName()+"\", \"id\":\""+getId()+"\", \"type\":"+jsonTypes+", \"properties\":"+ jsonProperties+", \"source\":"+jsonFrom+",\"target\":"+jsonTo+", \"value\":"+std::to_string(getWeight())+"}";
    return json;
}