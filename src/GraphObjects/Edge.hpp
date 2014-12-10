// # 2014 Walking Software

#ifndef __EDGE_HPP_
#define __EDGE_HPP_

#include <vector>
#include <map>
#include <string.h>
#include "Node.hpp"

namespace graphDB {
	class Node;

	class Edge {

	public:
		
		void setUpEdge(std::string aId, Node* aFromNode, Node *aToNode);

		std::string printEdge();
		void setId(std::string id){ this->id = id; }
		std::string getId(){ return id;}
		
		Node *getFrom(){return fromNode;}
		Node *getTo(){return toNode;}
		void setFrom(Node *node) {fromNode= node;}
		void setTo(Node *node) {toNode = node;}
		void setWeight(int weight) { this->weight = weight; }
		int getWeight() {return weight; }
		void addType(std::string typeName) { types.push_back(typeName); }
		void addProperty(std::string propertyName, std::string propertyValue) { properties[propertyName].push_back( propertyValue ); }


		std::vector<std::string> getTypes() { return types; }

		std::map<std::string, std::vector<std::string> > getProperties() { return properties; }
		std::vector <std::string> getProperty(std::string propertyName){ 
			std::map <std::string, std::vector <std::string> > all_properties = getProperties();
			std::vector <std::string> property = all_properties[propertyName];
			return property;
		}
	private:
		std::string id;
		std::vector<std::string>	types;
		std::map<std::string, std::vector<std::string> >		properties;
		Node *fromNode;
		Node *toNode;
		int weight;
	};
}
#endif