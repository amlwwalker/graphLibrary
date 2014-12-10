// # 2014 Walking Software
#ifndef __NODE_HPP_
#define __NODE_HPP_

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
#include "Edge.hpp"

namespace graphDB {

	class Edge;

	class Node {

	public:

		void setId(std::string id){ this->id = id; }
		std::string getId(){ return id;}
		void addLabel(std::string labelName);
		void addProperty(std::string propertyName, std::string propertyValue);
		void addProperty(std::string propertyName, std::vector<std::string> propertyValue);
		void addEdge (Edge *the_edge){ allEdges.push_back(the_edge); }
		void setGroup(uint64_t group) { this->group = group;}
		uint64_t getGroup() { return group;}
		// void addOutgoingEdge(Edge *the_edge);
		// void addReceivingEdge(Edge *the_edge);

		// vector <*Edge> getOutgoingEdges();
		// vector <*Edge> getIncomingEdges();
		std::vector <Edge*> getAllEdges();
		std::vector <Edge*> *getEdgesWithType(std::string type);

		// map <string, vector <*Edge> > getOutgoingMap(){ return sentEdges_map; }
		// map <string, vector <*Edge> > getIncomingMap(){ return receivedEdges_map; }

		std::map <std::string, std::vector <std::string> > getProperties();
		std::vector <std::string> getLabels();
		std::vector <std::string> getProperty(std::string PropertyName){ 
			std::map <std::string, std::vector <std::string> > all_properties = getProperties();
			std::vector <std::string> property = all_properties[PropertyName];
			return property;
		}

		std::string printNode();

		
	private:
		std::string id;
		uint64_t group;
		std::vector <std::string> labels;
		std::map <std::string, std::vector <std::string> > properties;
		std::vector <Edge*> allEdges;

	};
}
#endif