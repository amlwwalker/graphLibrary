// # 2014 Walking Software

#include <string.h>
#include <iostream>
#include <vector>
#include "../GraphObjects/Node.hpp"
#include "../GraphObjects/Edge.hpp"
#include "../Graph.hpp"
#include "../rapidjson/document.h"		// rapidjson's DOM-style API
#include "../rapidjson/prettywriter.h"	// for stringify JSON
#include "../rapidjson/filestream.h"	// wrapper of C stream for prettywriter as output
using namespace std;

class DatabaseLoader {

public:
	DatabaseLoader(string filename, Graph &graph);
	~DatabaseLoader();
	void loadDatabase();
private:
	string mFileName;
	Graph &mGraph;
};