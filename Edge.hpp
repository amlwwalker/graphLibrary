// #include "Node.hpp"

#ifndef __EDGE_HPP_
#define __EDGE_HPP_

#include <vector>
#include <map>
#include <string.h>
#include "Node.hpp"

using namespace std;

class Node;

class Edge {

public:
	
	void setUpEdge(string aId, Node* aFromNode, Node *aToNode);

	string printEdge();
	void setId(string id){ this->id = id; }
	string getId(){ return id;}
	
	Node *getFrom(){return fromNode;}
	Node *getTo(){return toNode;}
	void setFrom(Node *node) {fromNode= node;}
	void setTo(Node *node) {toNode = node;}

	void addType(string typeName) { types.push_back(typeName); }
	void addProperty(string propertyName, string propertyValue) { properties[propertyName].push_back( propertyValue ); }

	vector<string> getTypes() { return types; }

	map<string, vector<string> > getProperties() { return properties; }
	vector <string> getProperty(string propertyName){ 
		map <string, vector <string> > all_properties = getProperties();
		vector <string> property = all_properties[propertyName];
		return property;
	}
private:
	string id;
	vector<string>	types;
	map<string, vector<string> >		properties;
	Node *fromNode;
	Node *toNode;
};

#endif