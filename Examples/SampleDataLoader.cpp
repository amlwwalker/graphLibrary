

#include "DatabaseLoader.hpp"

using namespace graphDB;

DatabaseLoader::DatabaseLoader(std::string aFileName, Graph &graph) 
										: mFileName(aFileName), mGraph(graph) {
	//constructor
}
DatabaseLoader::~DatabaseLoader(){
//destructor
}
void DatabaseLoader::loadDatabase(){
	FILE * pFile = std::fopen (mFileName.c_str() , "r");
	rapidjson::FileStream fs(pFile);
	rapidjson::Document document;
	document.ParseStream<0>(fs);

	printf("\nParsing document succeeded.\n");


//loading nodes:
	const rapidjson::Value& nodes = document["nodes"];

	for(rapidjson::Value::ConstMemberIterator it=nodes.MemberBegin(); it != nodes.MemberEnd(); it++) {


		Node *tempNode;
		tempNode = new(Node);

		std::cout << it->name.GetString() << std::endl;

		tempNode->setId(it->name.GetString());
		
		assert(it->value["label"].IsArray());
		for (rapidjson::SizeType i = 0; i < it->value["label"].Size(); i++) {
			 std::cout << it->value["label"][i].GetString() << std::endl;
        	tempNode->addLabel(it->value["label"][i].GetString());
		} 

		assert(it->value["properties"].IsObject());
		//loading properties
		for(rapidjson::Value::ConstMemberIterator innerIt=it->value["properties"].MemberBegin(); innerIt != it->value["properties"].MemberEnd(); innerIt++) {
			assert(innerIt->value.IsArray());
			for (rapidjson::SizeType i = 0; i < innerIt->value.Size(); i++) {
        		tempNode->addProperty(innerIt->name.GetString(), innerIt->value[i].GetString());
			} 
		}
   		mGraph.addNode(tempNode);
	}

//loading edges:
	
	const rapidjson::Value& edges = document["edges"];

	for (rapidjson::SizeType i = 0; i < edges.Size(); i++) {

		Edge *tempEdge;
		tempEdge = new(Edge);

		assert(edges[i].IsObject());
		std::cout << edges[i].IsObject() << std::endl;

		std::cout << "ID: " << edges[i]["id"].GetString() << std::endl;
		tempEdge->setId(edges[i]["id"].GetString());

		std::cout << "Types: " << std::endl;
		for (rapidjson::SizeType j = 0; j < edges[i]["type"].Size(); j++) {
	 		std::cout << edges[i]["type"][j].GetString() << std::endl;
			tempEdge->addType(edges[i]["type"][j].GetString());
		}
		std::cout << "Properties: " << std::endl;
		for(rapidjson::Value::ConstMemberIterator innerIt=edges[i]["properties"].MemberBegin(); innerIt != edges[i]["properties"].MemberEnd(); innerIt++) {
			for (rapidjson::SizeType i = 0; i < innerIt->value.Size(); i++) {
        		std::cout << innerIt->name.GetString() << " " << innerIt->value[i].GetString() << std::endl;
				tempEdge->addProperty(innerIt->name.GetString(), innerIt->value[i].GetString());
			} 
		}


		std::cout << "To: " << edges[i]["to"].GetString() << std::endl;
		Node *toNode = mGraph.findNodeWithId(edges[i]["to"].GetString());

		std::cout << "From: " << edges[i]["from"].GetString() << std::endl;
		Node *fromNode = mGraph.findNodeWithId(edges[i]["from"].GetString());

		bool fromSet = false;
		bool toSet = false;

			if (toNode != NULL) { //if node exists
				toNode->addEdge(tempEdge);
				tempEdge->setFrom(toNode);
				fromSet = true;
			}
			if (fromNode != NULL) {
				fromNode->addEdge(tempEdge);
				tempEdge->setTo(toNode);
				toSet = true;
			}
			if (toSet && fromSet) { //only add the edge if it is attached on both ends
				mGraph.addEdge(tempEdge);
			}
	}
}

