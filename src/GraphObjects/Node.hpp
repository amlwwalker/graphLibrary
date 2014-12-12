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

		/// Sets the (automatically generated) id for a node. The id is unique.
		void setId(std::string id){ this->id = id; }
		
		/// Sets the name for a node. This is either read from file or defined in code. The name is unique.
		void setName(std::string name){ this->name = name; }
		
		/// Returns a node's id
		std::string getId(){ return id;}
		
		/// Returns a node's name
		std::string getName(){ return name;}
		
		/// Add the labels of a node to a vector
		void addLabel(std::string labelName);
		
		/// Adds a property and its value to a map; the key is the property name
		void addProperty(std::string propertyName, std::string propertyValue);
		
		/** Adds a property and its values to a map; the key is the property name. The difference between
		this and the previous function is that it take a vector as the parameter for the values.
		*/
		void addProperty(std::string propertyName, std::vector<std::string> propertyValue);

		/** Adds the pointer to an Edge to the vector of all edges associated with this node. */
		void addEdge (Edge *the_edge){ allEdges.push_back(the_edge); }

		/** Adds the pointer to an outgoing Edge to the vector of all edges going out from this node. */
		void addOutgoingEdge (Edge *the_edge){ allOutgoingEdges.push_back(the_edge); }

		/** Adds the pointer to an incoming Edge to the vector of all edges coming into this node. */
		void addIncomingEdge (Edge *the_edge){ allIncomingEdges.push_back(the_edge); }

		/** This does sth for the d3. The required parameter used to uint64_t but is now switched to int so it 
		compiles on vagrant */
		void setGroup(int group) { this->group = group;}
		
		/** This returns the d3 group. The required output used to uint64_t but is now switched to int so it 
		compiles on vagrant */
		int getGroup() { return group;}
		
		// void addOutgoingEdge(Edge *the_edge);
		// void addReceivingEdge(Edge *the_edge);

		// vector <*Edge> getOutgoingEdges();
		// vector <*Edge> getIncomingEdges();

		/** Returns a vector with pointers to all associated with this node. */
		std::vector <Edge*> getAllEdges();

		/** Returns a vector with pointers to all outgoing edges from this node. */
		std::vector <Edge*> getAllOutgoingEdges();

		/** Returns a vector with pointers to all incoming edges to this node. */
		std::vector <Edge*> getAllIncomingEdges();

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

		/// Prints (in json) all details for node
		std::string printNode();
		//void addProperty(std::string propertyName, std::vector <std::string> propertyValue);

		// function for us

		
	private:
		std::string id;
		std::string name;
		int group; //uint64_t
		std::vector <std::string> labels;
		std::map <std::string, std::vector <std::string> > properties;
		std::vector <Edge*> allEdges;
		std::vector <Edge*> allOutgoingEdges;
		std::vector <Edge*> allIncomingEdges;

	};
}
#endif