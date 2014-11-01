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

	cout << "Denise and Alex's insane graph database" << endl;

	Graph graph;
	
	//creating nodes and edges from a JSON file
	DatabaseLoader db("sample.json", graph.getNodeReference(), graph.getEdgeReference());
	db.loadDatabase();
	

/*****************************************************/

	//creating nodes and edges algorithmically
	Node dynWeb, dynHtml;
 	// web.setName("Web");
 	dynWeb.set_id("dyn_web");
 	dynWeb.addLabel("Field");
 	dynWeb.addLabel("Parent");
 	dynWeb.addProperty("name","dyn_web");
 	dynWeb.addProperty("show_name","dyn_web");
 	
 	graph.addNode(&dynWeb);
	
	// graph.printEdges();
 	dynHtml.set_id("dyn_HTML");
 	dynHtml.addLabel("Topic");
 	dynHtml.addLabel("Parent");
 	dynHtml.addProperty("name","dyn_HTML");
 	dynHtml.addProperty("show_name","dyn_HTML");
 	dynHtml.addProperty("show_name","dyn_HTML2");

 	graph.addNode(&dynHtml);

 	

 	Edge e2;
 	//function to set id, from and to nodes directly.
	e2.setEdge("7363", &dynHtml, &dynWeb);
	e2.addType("includes"); //can we do this all in one step so that in that step the node functions get called too in order to update the nodes?
	e2.addProperty("strength","5"); //must enforce one type so that the property unambiguously matches a type
	dynHtml.addEdge(&e2);
	dynWeb.addEdge(&e2);

	graph.addEdge(&e2);
	

	Edge e3;
	e3.setEdge("2037", &dynWeb, &dynHtml);
 	
	e3.addType("included_in"); //can we do this all in one step so that in that step the node functions get called too in order to update the nodes?
	e3.addProperty("strength","5"); //must enforce one type so that the property unambiguously matches a type
	dynHtml.addEdge(&e3);
	dynWeb.addEdge(&e3);
	graph.addEdge(&e3);
	graph.printNodes();
	
  return 0;
}