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

	public:
		// BaseEdge();
		void setUpEdge(std::string aId, BaseNode* aFromNode, BaseNode *aToNode);

		std::string printEdge();
		void setId(std::string id){ this->id = id; }
		std::string getId(){ return id;}
		
		BaseNode *getFrom(){return fromNode;}
		BaseNode *getTo(){return toNode;}
		void setFrom(BaseNode *node);// {fromNode= node; node->addEdge(this);}
		void setTo(BaseNode *node);// {toNode = node; node->addEdge(this);}
		void setWeight(int weight) { this->weight = weight; }
		int getWeight() {return weight; }
		void addType(std::string typeName) { types.push_back(typeName); }
		void addProperty(std::string propertyName, std::string propertyValue) { properties[propertyName].push_back( propertyValue ); }


		std::vector<std::string> getTypes() { return types; }

		std::map<std::string, std::vector<std::string> > getProperties() { return properties; }
		std::vector <std::string> getProperty(std::string propertyName){ 
			std::map <std::string, std::vector <std::string> > tempProperties = getProperties();
			std::vector <std::string> property = tempProperties[propertyName];
			return property;
		}
	private:
		
		std::string id;
		std::vector<std::string>	types;
		std::map<std::string, std::vector<std::string> >		properties;
		BaseNode *fromNode;
		BaseNode *toNode;
		int weight;
	};
}
#endif