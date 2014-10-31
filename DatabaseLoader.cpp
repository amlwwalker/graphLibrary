

#include "DatabaseLoader.hpp"

DatabaseLoader::DatabaseLoader(string aFileName) : mFileName(aFileName){
	//constructor
}
DatabaseLoader::~DatabaseLoader(){

}

void DatabaseLoader::printNodes(){

	for (int i = 0; i < nodeList.size(); i++) {
			cout << nodeList[i].getId() << endl;
	}

}
void DatabaseLoader::loadDatabase(){
	FILE * pFile = std::fopen (mFileName.c_str() , "r");
	rapidjson::FileStream is(pFile);
	rapidjson::Document document;
	document.ParseStream<0>(is);

	printf("\nParsing to document succeeded.\n");

	printf("\nAccess values in document:\n");

	const rapidjson::Value& nodes = document["nodes"];
	
	for(rapidjson::Value::ConstMemberIterator it=nodes.MemberBegin(); it != nodes.MemberEnd(); it++) {

		Node tempNode;
		tempNode.set_id(it->name.GetString());
		
		assert(it->value["label"].IsArray());
		for (rapidjson::SizeType i = 0; i < it->value["label"].Size(); i++) {
			cout << it->value["label"][i].GetString() << endl;
        	tempNode.addLabel(it->value["label"][i].GetString());
		} 

		assert(it->value["properties"].IsObject());
		for(rapidjson::Value::ConstMemberIterator innerIt=it->value["properties"].MemberBegin(); innerIt != it->value["properties"].MemberEnd(); innerIt++) {
			cout << innerIt->name.GetString() << endl;
			assert(innerIt->value.IsArray());
			for (rapidjson::SizeType i = 0; i < innerIt->value.Size(); i++) {
        		tempNode.addLabel(innerIt->value[i].GetString());
			} 
		}
   		nodeList.push_back(tempNode);
	}
}
