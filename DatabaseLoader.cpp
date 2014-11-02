

#include "DatabaseLoader.hpp"

DatabaseLoader::DatabaseLoader(string aFileName, vector<Node*> &aNodeList, vector<Edge*> &aEdgeList) 
										: mFileName(aFileName), nodeList(aNodeList), edgeList(aEdgeList) {
	//constructor
}
DatabaseLoader::~DatabaseLoader(){

}
void DatabaseLoader::loadDatabase(){
	FILE * pFile = std::fopen (mFileName.c_str() , "r");
	rapidjson::FileStream fs(pFile);
	rapidjson::Document document;
	document.ParseStream<0>(fs);

	printf("\nParsing document succeeded.\n");


//loading nodes:
	const rapidjson::Value& nodes = document["nodes"];
	// assert(nodes.IsArray());
	for(rapidjson::Value::ConstMemberIterator it=nodes.MemberBegin(); it != nodes.MemberEnd(); it++) {


		Node *tempNode;
		tempNode = new(Node);

		tempNode->set_id(it->name.GetString());
		
		assert(it->value["label"].IsArray());
		for (rapidjson::SizeType i = 0; i < it->value["label"].Size(); i++) {
			// cout << it->value["label"][i].GetString() << endl;
        	tempNode->addLabel(it->value["label"][i].GetString());
		} 

		assert(it->value["properties"].IsObject());
		for(rapidjson::Value::ConstMemberIterator innerIt=it->value["properties"].MemberBegin(); innerIt != it->value["properties"].MemberEnd(); innerIt++) {
			// cout << innerIt->name.GetString() << endl;
			assert(innerIt->value.IsArray());
			for (rapidjson::SizeType i = 0; i < innerIt->value.Size(); i++) {
        		tempNode->addProperty(innerIt->name.GetString(), innerIt->value[i].GetString());
			} 
		}
   		nodeList.push_back(tempNode);
	}



//loading edges:
	


	const rapidjson::Value& edges = document["edges"];

	for (rapidjson::SizeType i = 0; i < edges.Size(); i++) {
		Edge *tempEdge;
		tempEdge = new(Edge);

		//assert(it->["properties"].IsObject());
		// //type is an array
		// for (int j = 0; j < edges.size(); j++) {
		
		tempEdge->setId(edges[i]["id"].GetString());

		assert(edges[i]["type"].IsArray());
		for (rapidjson::SizeType i = 0; i < edges[i]["type"].Size(); i++) {
			// cout << it->value["label"][i].GetString() << endl;
        	tempEdge->addType(edges[i]["type"][i].GetString());
		} 
		
		//from is a Node, not a string
		//to is a Node, not a string...

		//assert(edges[i]["properties"].IsObject());
		for(rapidjson::Value::ConstMemberIterator innerIt=edges[i]["properties"].MemberBegin(); innerIt != edges[i]["properties"].MemberEnd(); innerIt++) {
			// cout << innerIt->name.GetString() << endl;
			assert(innerIt->value.IsArray());
			for (rapidjson::SizeType i = 0; i < innerIt->value.Size(); i++) {
        		tempEdge->addProperty(innerIt->name.GetString(), innerIt->value[i].GetString());
			} 
		}
		assert(edges[i]["from"].IsString());
		bool fromSet = false;
		bool toSet = false;
		for (int j = 0; j < nodeList.size(); j++) {

			if (nodeList[j]->getId() == edges[i]["from"].GetString()) {
				nodeList[j]->addEdge(tempEdge);
				 // cout << "(from) NODE: " << nodeList[j].getId() << " : " << edges[i]["from"].GetString() << endl;
				tempEdge->setFrom(nodeList[j]);
				fromSet = true;
			} else if (nodeList[j]->getId() == edges[i]["to"].GetString()) {
				 // cout << "(to) NODE: " << nodeList[j].getId() << " : " << edges[i]["to"].GetString() << endl;
				nodeList[j]->addEdge(tempEdge);
				tempEdge->setTo(nodeList[j]);
				toSet = true;
			}
			if (fromSet && toSet){
				break;
			}
		}
		edgeList.push_back(tempEdge);
	}

	// 	for(rapidjson::Value::ConstMemberIterator it=nodes.MemberBegin(); it != nodes.MemberEnd(); it++) {
	// 	Edge *tempEdge;
	// 	tempEdge = new(Edge);
	// 	assert(it->value["properties"].IsObject());
	// 	for(rapidjson::Value::ConstMemberIterator innerIt=it->value["properties"].MemberBegin(); innerIt != it->value["properties"].MemberEnd(); innerIt++) {
	// 		// cout << innerIt->name.GetString() << endl;
	// 		assert(innerIt->value.IsArray());
	// 		for (rapidjson::SizeType i = 0; i < innerIt->value.Size(); i++) {
 //        		tempEdge->addProperty(innerIt->name.GetString(), innerIt->value[i].GetString());
	// 		} 
	// 	}
	// 	cout << "HEREHEREHERE: " << it->value["from"][0].GetString() << endl ;
	// 	//assert(it->value["from"].IsString());
	// 	// assert(it->value["from"].IsString());
	// 	bool fromSet = false;
	// 	bool toSet = false;
	// 	// for (int j = 0; j < nodeList.size(); j++) {

	// 	// 	if (nodeList[j]->getId() == it->value["from"].GetString()) {
	// 	// 		nodeList[j]->addEdge(tempEdge);
	// 	// 		 // cout << "(from) NODE: " << nodeList[j].getId() << " : " << edges[i]["from"].GetString() << endl;
	// 	// 		tempEdge->setFrom(nodeList[j]);
	// 	// 		fromSet = true;
	// 	// 	} else if (nodeList[j]->getId() == it->value["to"].GetString()) {
	// 	// 		 // cout << "(to) NODE: " << nodeList[j].getId() << " : " << edges[i]["to"].GetString() << endl;
	// 	// 		nodeList[j]->addEdge(tempEdge);
	// 	// 		tempEdge->setTo(nodeList[j]);
	// 	// 		toSet = true;
	// 	// 	}
	// 	// 	if (fromSet && toSet){
	// 	// 		break;
	// 	// 	}
	// 	// }
	// 	edgeList.push_back(tempEdge);
	// }
 	
}

