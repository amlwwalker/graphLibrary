// 'Hello World!' program 
 
#include <iostream>
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"
#include "DatabaseLoader.hpp"
#include "Graph.hpp"

using namespace std;
 
int main()
{
	DatabaseLoader db("sample.json");
	Graph graph;
	db.loadDatabase();
	graph.printNodes(db.getNodes());
	graph.printEdges(db.getEdges());
	
    cout << "\n\n" << endl;
	Node n1;
	Node n2;

	n1.addLabel("Alex");

	Node web, html;
	Edge e;

	e.setTo(&n1);
	e.setFrom(&n2);

	e.addType("a type");
	e.addProperty("propertyKey", "propertyValue");

	vector<string> types = e.getTypes();

	for(int i=0; i < e.getTypes().size(); i++){
   		cout <<	e.getTypes()[i] << endl;
	}

	// map<std::string, std::string>::iterator it;

	// for(it = e.getProperties().begin(); it!=e.getProperties().end(); ++it) {
			
	// 		cout << it->first << endl;
	// 		cout << it->second << endl;
			
	// 	}

  cout << "Denise and Alex's insane graph database" << endl;

 	// web.setName("Web");
 	web.addLabel("Field");
 	web.addLabel("Parent");
 	web.addProperty("name","Web");
 	web.addProperty("show_name","Web");

 	// html.setName("HTML");
 	html.addLabel("Topic");
 	html.addLabel("Parent");

 	html.addProperty("name","HTML");
 	html.addProperty("show_name","HTML");
 	html.addProperty("show_name","HTML2");

 	Edge e2;
 	e2.setTo(&web);
 	e2.setId("09876");
	e2.setFrom(&html);
	e2.addType("includes"); //can we do this all in one step so that in that step the node functions get called too in order to update the nodes?
	e2.addProperty("strength","5"); //must enforce one type so that the property unambiguously matches a type
	html.addEdge(&e2);
	web.addEdge(&e2);


	Edge e3;
 	e3.setTo(&html);
 	e3.setId("12345");
	e3.setFrom(&web);
	e3.addType("included_in"); //can we do this all in one step so that in that step the node functions get called too in order to update the nodes?
	e3.addProperty("strength","5"); //must enforce one type so that the property unambiguously matches a type
	html.addEdge(&e3);
	web.addEdge(&e3);


 	web.printNode();
 	html.printNode();

 	// e.getEnd1("Web"); e.get


  return 0;
}