// 'Hello World!' program 
 
// class Edge;
// class Node;
#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"


using namespace std;

 
int main()
{

	Node web, html;
	Edge e;
	e.printSomething();

 	cout << "Denise and Alex's insane graph database" << endl;

 	// web.setName("Web");
 	web.addLabel("Field");
 	web.addLabel("Parent");
 	web.addProperty("show_name","Web");

 	web.printNode();

 	// html.setName("HTML");
 	html.addLabel("Topic");
 	html.addLabel("Parent");
 	html.addProperty("show_name","HTML");


 	html.printNode();

 	// e.getEnd1("Web"); e.get


  return 0;
}