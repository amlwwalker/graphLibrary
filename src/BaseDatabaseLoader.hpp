// # 2014 Walking Software
#ifndef __BASE_DATABASELOADER_HPP_
#define __BASE_DATABASELOADER_HPP_

#include <string.h>
#include <iostream>
#include <vector>
#include "GraphObjects/BaseGraph.hpp"
#include "../../rapidjson/document.h"		// rapidjson's DOM-style API
#include "../../rapidjson/prettywriter.h"	// for stringify JSON
#include "../../rapidjson/filestream.h"	// wrapper of C stream for prettywriter as output

namespace graphDB {
	///This is the basis for a databaseLoader. It needs to be subclassed as this is pure virtual. It cannot be instantiated
	class BaseDatabaseLoader {

		public:
			///Needs a filename to read from and a graph to load the data into
			BaseDatabaseLoader(std::string aFileName, BaseGraph graph) {mFileName = aFileName; mGraph = graph; }
			// ~BaseDatabaseLoader();
			///Each databaseLoader needs to create a loadDatabase() function to understand how to load the file
			virtual void loadDatabase() = 0;
		protected:

			std::string mFileName;
			BaseGraph mGraph;
	};
}

#endif
