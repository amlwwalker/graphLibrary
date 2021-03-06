// # 2014 Walking Software

#include <string.h>
#include <iostream>
#include <vector>
#include "../graphLibrary/src/GraphObjects/Node.hpp"
#include "../graphLibrary/src/GraphObjects/Edge.hpp"
#include "../graphLibrary/src/GraphObjects/Graph.hpp"
#include "../rapidjson/include/document.h"		// rapidjson's DOM-style API
#include "../rapidjson/include/prettywriter.h"	// for stringify JSON
#include "../rapidjson/include/filestream.h"	// wrapper of C stream for prettywriter as output

namespace graphDB {

	class DatabaseLoader {

	public:
		DatabaseLoader(std::string filename, Graph &graph);
		~DatabaseLoader();
		void loadDatabase();
	private:
		std::string mFileName;
		Graph &mGraph;
	};
}