// # 2014 Walking Software
#ifndef __BASE_NODE_HPP_
#define __BASE_NODE_HPP_

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm> 
#include <iterator>
#include <string.h>
#include <stdio.h>
#include <numeric>
#include <map>
#include "BaseEdge.hpp"

namespace graphDB {

	class BaseEdge;

	class BaseNode {

		///BaseGraph is the only thing able to access the private constructor
		friend class BaseGraph;
		///BaseEdge is the only thing able to add Edges to a Node
		friend class BaseEdge;

	public:
		///Returns the unique ID of the Node
		std::string getId(){ return id;}
		///Sets the name of the Node - optional
		void setName(std::string name){ this->name = name;}
		///returns the name of the Node
		std::string getName(){ return name;}
		///Adds a label to the Node
		void addLabel(std::string labelName);
		///Adds a property to the Node
		void addProperty(std::string propertyName, std::string propertyValue);
		///Adds an array of properties to the Node
		void addProperty(std::string propertyName, std::vector<std::string> propertyValue);
		///Sets the group of the Node
		void setGroup(int group) { this->group = group;}
		///Returns the Group of the Node
		int getGroup() { return group;}
		// void addOutgoingEdge(Edge *the_edge);
		// void addReceivingEdge(Edge *the_edge);

		// vector <*Edge> getOutgoingEdges();
		// vector <*Edge> getIncomingEdges();
		///Returns vector of edges attached to the Node
		std::vector <BaseEdge*> getAllEdges();
		///Returns vector of edges with specific type
		std::vector <BaseEdge*> *getEdgesWithType(std::string type);

		// map <string, vector <*Edge> > getOutgoingMap(){ return sentEdges_map; }
		// map <string, vector <*Edge> > getIncomingMap(){ return receivedEdges_map; }

		///Returns all of the properties on the Node
		std::map <std::string, std::vector <std::string> > getProperties();
		///Returns all the labels on the node
		std::vector <std::string> getLabels();
		///Returns a specific property array of a node
		std::vector <std::string> getProperty(std::string PropertyName){ 
			std::map <std::string, std::vector <std::string> > tempProperties = getProperties();
			std::vector <std::string> property = tempProperties[PropertyName];
			return property;
		}

		///prints out the node, for debugging.
		std::string printNode();

		
	private:
		BaseNode(std::string id);
		void addEdge (BaseEdge *edge){ edges.push_back(edge); }
		std::string id;
		std::string name;
		int group;
		std::vector <std::string> labels;
		std::map <std::string, std::vector <std::string> > properties;
		std::vector <BaseEdge*> edges;

	};
}
#endif