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
		friend class BaseEdge;

	public:
		// BaseNode();
		void setId(std::string id){ this->id = id; }
		std::string getId(){ return id;}
		void addLabel(std::string labelName);
		void addProperty(std::string propertyName, std::string propertyValue);
		void addProperty(std::string propertyName, std::vector<std::string> propertyValue);
		void setGroup(int group) { this->group = group;}
		int getGroup() { return group;}
		// void addOutgoingEdge(Edge *the_edge);
		// void addReceivingEdge(Edge *the_edge);

		// vector <*Edge> getOutgoingEdges();
		// vector <*Edge> getIncomingEdges();
		std::vector <BaseEdge*> getAllEdges();
		std::vector <BaseEdge*> *getEdgesWithType(std::string type);

		// map <string, vector <*Edge> > getOutgoingMap(){ return sentEdges_map; }
		// map <string, vector <*Edge> > getIncomingMap(){ return receivedEdges_map; }

		std::map <std::string, std::vector <std::string> > getProperties();
		std::vector <std::string> getLabels();
		std::vector <std::string> getProperty(std::string PropertyName){ 
			std::map <std::string, std::vector <std::string> > tempProperties = getProperties();
			std::vector <std::string> property = tempProperties[PropertyName];
			return property;
		}

		std::string printNode();

		
	private:
		
		void addEdge (BaseEdge *edge){ edges.push_back(edge); }
		std::string id;
		int group;
		std::vector <std::string> labels;
		std::map <std::string, std::vector <std::string> > properties;
		std::vector <BaseEdge*> edges;

	};
}
#endif