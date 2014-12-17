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

	class BaseDatabaseLoader {

		public:
			BaseDatabaseLoader(std::string aFileName, std::string graph);
			// ~BaseDatabaseLoader();
			void loadDatabase();
		protected:

			std::string mFileName;
			std::string mGraph;
	};
}

#endif
