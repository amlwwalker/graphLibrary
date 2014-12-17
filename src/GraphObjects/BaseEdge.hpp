// # 2014 Walking Software

#ifndef __BASE_EDGE_HPP_
#define __BASE_EDGE_HPP_

#include <vector>
#include <map>
#include <string.h>
#include "BaseNode.hpp"

namespace graphDB {
	class BaseNode;

	class BaseEdge {
		friend class BaseGraph;
	public:
		///Sets the from node, to node and name of an Edge
		void setUpEdge(std::string aName, BaseNode* aFromNode, BaseNode *aToNode);

		///prints the Edge out - for debugging
		std::string printEdge();
		///Sets the name of the Edge
		void setName(std::string name){ this->name = name; }
		///Returns the ID of the Edge
		std::string getId(){ return id;}
		///Returns the name of the edge
		std::string getName(){ return name;}
		///Returns the Source Node of the Edge
		BaseNode *getFrom(){return fromNode;}
		///Returns the Destination Node of the Edge
		BaseNode *getTo(){return toNode;}
		///Sets the From node of the edge (note this also sets in on the node)
		void setFrom(BaseNode *node);
		///Sets the To node of the edge (note this also sets in on the node)
		void setTo(BaseNode *node);
		///Sets the weight of the Edge
		void setWeight(int weight) { this->weight = weight; }
		///Returns the weight of the Edge
		int getWeight() {return weight; }
		///Sets the Type of the Edge
		void addType(std::string typeName) { types.push_back(typeName); }
		///Adds a property to the Edge
		void addProperty(std::string propertyName, std::string propertyValue) { properties[propertyName].push_back( propertyValue ); }

		///Returns the Types of the Edge
		std::vector<std::string> getTypes() { return types; }
		///Returns the properties of the Edge
		std::map<std::string, std::vector<std::string> > getProperties() { return properties; }
		///Returns a specific property of the Edge
		std::vector <std::string> getProperty(std::string propertyName){ 
			std::map <std::string, std::vector <std::string> > tempProperties = getProperties();
			std::vector <std::string> property = tempProperties[propertyName];
			return property;
		}
	private:
		BaseEdge(std::string id);
		std::string id;
		std::string name; 
		std::vector<std::string>	types;
		std::map<std::string, std::vector<std::string> >		properties;
		BaseNode *fromNode;
		BaseNode *toNode;
		int weight;
	};
}
#endif