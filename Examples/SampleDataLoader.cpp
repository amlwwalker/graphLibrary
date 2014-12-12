

#include "SampleDataLoader.hpp"

using namespace graphDB;

SampleDataLoader::SampleDataLoader(std::string aFileName, Graph &graph) 
										: mFileName(aFileName), mGraph(graph) {
	//constructor
}
SampleDataLoader::~SampleDataLoader(){
//destructor
}
void SampleDataLoader::loadDatabase(){
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

	for(rapidjson::Value::ConstMemberIterator it=nodes.MemberBegin(); it != nodes.MemberEnd(); it++) {

		Edge *tempEdge;
		tempEdge = new(Edge);

		std::cout << it->value["id"].GetString() << std::endl;
		tempEdge->setId(it->value["id"].GetString());

		//loading properties
		for(rapidjson::Value::ConstMemberIterator innerIt=it->value["properties"].MemberBegin(); innerIt != it->value["properties"].MemberEnd(); innerIt++) {
			assert(innerIt->value.IsArray());
			for (rapidjson::SizeType i = 0; i < innerIt->value.Size(); i++) {
        		tempEdge->addProperty(innerIt->name.GetString(), innerIt->value[i].GetString());
			} 
		}
		// assert(it->value["from"].IsString());
		bool fromSet = false;
		bool toSet = false;

		Node *toNode = mGraph.findNodeWithId(it->value["from"].GetString());
		Node *fromNode = mGraph.findNodeWithId(it->value["to"].GetString());

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

