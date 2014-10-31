
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
using namespace std;

// template <typename T>
// void COUT(vector <T>& Vect){ for (int i=0; i<Vect.size(); i++){ cout<<Vect[i]<<" "; }cout<<endl; }


class Node {

public:

	void set_id(){ cout<<"need to automatically set an id to this node"<<endl; }
	void addLabel(string labelName);
	void addProperty(string propertyName, string propertyValue);

	void addOutgoingEdge(Edge the_edge) { 
	
		sentEdges.push_back(the_edge); allEdges.push_back(the_edge); 
		// //if ( sentEdges_map.find("f") == sentEdges_map.end() ) {
		// vector <string> edge_types = the_edge.getTypes();
		// for (var i = 0; i < edge_types.size(); i++){
		// 	sentEdges_map[i].push_back(the_edge); //regardless of whether type i already exists in the map;
		// }
	}

	void addReceivingEdge(Edge the_edge) { 
	
		receivedEdges.push_back(the_edge); allEdges.push_back(the_edge); 
		// //if ( receivedEdges_map.find("f") == receivedEdges_map.end() ) {
		// vector <string> edge_types = the_edge.getTypes();
		// for (var i = 0; i < edge_types.size(); i++){
		// 	receivedEdges_map[i].push_back(the_edge); //regardless of whether type i already exists in the map;
		// }
	}

	vector <Edge> getOutgoingEdges();
	vector <Edge> getIncomingEdges();
	vector <Edge> getAllEdges();

	map <string, string> getProperties();
	vector <string> getLabels();

	void printNode();

	
private:
	string id;
	vector <string> labels;
	map <string, string> properties;
	
	map <string, vector <Edge> > receivedEdges_map;
	map <string, vector <Edge> > sentEdges_map;

	vector <Edge> sentEdges;
	vector <Edge> receivedEdges;
	vector <Edge> allEdges;

};

#endif