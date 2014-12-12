// # 2014 Walking Software

#include <string.h>
#include <iostream>
#include <vector>
#include "../src/GraphObjects/Node.hpp"
#include "../src/GraphObjects/Edge.hpp"
#include "../src/GraphObjects/Graph.hpp"
#include "../src/rapidjson/document.h"		// rapidjson's DOM-style API
#include "../src/rapidjson/prettywriter.h"	// for stringify JSON
#include "../src/rapidjson/filestream.h"	// wrapper of C stream for prettywriter as output
namespace graphDB {

	class SampleDataLoader {

	public:
		SampleDataLoader(std::string filename, Graph &graph);
		~SampleDataLoader();
		void loadDatabase();
	private:
		std::string mFileName;
		Graph &mGraph;
	};
}