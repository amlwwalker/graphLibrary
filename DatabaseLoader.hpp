

#include <string.h>
#include <iostream>
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"
#include "rapidjson/document.h"		// rapidjson's DOM-style API
#include "rapidjson/prettywriter.h"	// for stringify JSON
#include "rapidjson/filestream.h"	// wrapper of C stream for prettywriter as output
using namespace std;

class DatabaseLoader {

public:
	DatabaseLoader(string filename);
	~DatabaseLoader();
	void loadDatabase();
	vector <Node> getNodes(){return nodeList;}
	vector <Edge> getEdges(){return edgeList;}
	void printNodes();
private:
	string mFileName;
	vector <Node> nodeList; 
	vector <Edge> edgeList;
};