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
		enum EdgeDir { NONE, OUT, IN};

		///Sets the name of the Edge, the from node and the to node
		void setUpEdge(std::string aName, BaseNode* aFromNode, BaseNode *aToNode);
		///Sets the from node, to node and the type of the Edge
		void setUpEdge(BaseNode* aFromNode, BaseNode *aToNode, std::string aType);

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
		///Sets the From node of the edge (note this also sets it on the node)
		void setFrom(BaseNode *node);
		///Sets the To node of the edge (note this also sets it on the node)
		void setTo(BaseNode *node);
		///Sets the weight of the Edge
		void setWeight(int weight) { this->weight = weight; }
		///Returns the weight of the Edge
		int getWeight() {return weight; }
		///Sets the Type of the Edge
		void setType(std::string typeName) { this->type = typeName; }
		///Adds a property to the Edge
		void addProperty(std::string propertyName, std::string propertyValue) { properties[propertyName].push_back( propertyValue ); }

		///Returns the Type of the Edge
		std::string getType(){ return type; }
		///Returns the address of the properties of the Edge
		std::map<std::string, std::vector<std::string> > * getProperties() { return & properties; }
		///Returns a specific property of the Edge. This function needs fixing to avoid dereferencing.
		std::vector <std::string> getProperty(std::string propertyName){ 
			std::map <std::string, std::vector <std::string> > tempProperties = *getProperties();
			std::vector <std::string> property = tempProperties[propertyName];
			return property;
		}
	private:

		BaseEdge(std::string id);
		std::string id;
		std::string name; 
		std::string type;
		// std::vector<std::typesstring>	types;
		std::map<std::string, std::vector<std::string> >		properties;
		BaseNode *fromNode;
		BaseNode *toNode;
		int weight;
	};
}
#endif