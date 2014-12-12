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

		/// Sets the automatically generated id to an edge
		void setId(std::string id){ this->id = id; }

		/// Returns the id of an edge
		std::string getId(){ return id;}
		
		/// Returns a pointer to the fromNode
		Node *getFrom(){return fromNode;}

		/// Returns a pointer to the toNode
		Node *getTo(){return toNode;}

		/** Sets the from node. For this a graph function is called to identify the node by its
		name. The function should call Node::addEdge so that the Node class is aware that a node has been
		added. In principle, we should also specify that this is an outgoing edge. */
		void setFrom(Node *node) {
			fromNode = node;
			// fromNode->addEdge(this); //SOS this needs debugging
		}
		
		/** Sets the from node. For this a graph function is called to identify the node by its
		name. The function should call Node::addEdge so that the Node class is aware that a node has been
		added. In principle, we should also specify that this is an incoming edge. */
		void setTo(Node *node) {
			toNode = node;
			// toNode->addEdge(this); // SOS this needs debugging
		}
		
		// Sets the edge type
		void setType(std::string type) {type = type;}

		// Sets the edge weight
		void setWeight(int weight) { this->weight = weight; }

		// Returns the edge weight
		int getWeight() {return weight; }

		// Adds a type to the edge, assuming a vector of types. An edge though should only have one type.
		void addType(std::string typeName) { types.push_back(typeName); }

		// Adds a property to an edge
		void addProperty(std::string propertyName, std::string propertyValue) { properties[propertyName].push_back( propertyValue ); }
		std::string getType(std::string type) {return type;}

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
		std::map<std::string, std::vector<std::string> > properties;
		Node *fromNode;
		Node *toNode;
		int weight;
		std::string type;
	};
}
#endif