// 'Hello World!' program 
 
#include <iostream>
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"
#include "Jzon.h"

using namespace std;

// void processData(Jzon::Node &s) {

//         if (name == "instance") {
//     	cout << name << " = ";
//         if (s.IsValue())
//         {
//                 switch (s.AsValue().GetValueType())
//                 {
//                 case Jzon::Value::VT_NULL   : cout << "null"; break;
//                 case Jzon::Value::VT_STRING : 
//                 	cout << "This is a: " << s.ToString(); break;
//                 	//check if a node or an edge.
//                 	if (s.ToString() == "node") {
//                 		//pass s to node creating function
//                 	} else if (s.ToString() == "edge") {
//                 		// pass s to edge creating function
//                 	}
//                 case Jzon::Value::VT_NUMBER : 
//                 	cout << "This is a: " << s.ToFloat(); break;
//                 case Jzon::Value::VT_BOOL   :
//                 	cout << "This is a: " << (s.ToBool()?"true":"false"); break;
//                 }
//         }
//         else if (s.IsArray())
//         {
//                 std::cout << "*Array*";
//                 const Jzon::Array &stuff = s.AsArray();
// 		        for (Jzon::Array::const_iterator it = stuff.begin(); it != stuff.end(); ++it)
// 		        {
// 		                cout << (*it).ToString() << endl;
// 		        }
//         }
//         else if (s.IsObject())
//         {
//                 cout << "*Object*";
//         }
//         cout << endl;
//     }
// }
void parseJsonFileToNode(string filename) {
	Jzon::Object root;
    Jzon::FileReader::ReadFile(filename, root);

    // cout << "Name: " << root.Get("name").ToString() << std::endl;
    // cout << "Number: " << root.Get("number").ToString() << std::endl;
    // cout << "AnotherNumber: " << root.Get("anothernumber").ToString() << std::endl;
    // cout << "Stuff: " << root.Get("stuff").ToString() << std::endl;

        for (Jzon::Object::iterator it = root.begin(); it != root.end(); ++it)
        {
                std::string name = (*it).first;
                Jzon::Node &s = (*it).second;

                // cout << node.AsValue() << endl;
                if (name == "instance") {
                	if (s.IsValue()) {
                		switch (s.AsValue().GetValueType()) {
                			case Jzon::Value::VT_NULL   : cout << "null"; break;
                			case Jzon::Value::VT_NUMBER : cout << "number"; break;
                			case Jzon::Value::VT_BOOL   : cout << "boolean"; break;
                			case Jzon::Value::VT_STRING : 
			                	cout << "This is a: " << s.ToString() << endl; break;
			                	//check if a node or an edge.
			                	if (s.ToString() == "node") {
			                		cout << "this is a node" << endl;
			                		//pass s to node creating function
			                	} else if (s.ToString() == "edge") {
			                		// pass s to edge creating function
			                		cout << "this is an edge" << endl;
			                	}
			                	break;
	                		}
                	}
                }

         	
 
        }


}
 
int main()
{
	parseJsonFileToNode("file.json");
 




	Node n1;
	Node n2;

	n1.addLabel("Alex");

	Node web, html;
	Edge e;

	e.setEnd1(&n1);
	e.setEnd2(&n2);

	e.addType("a type");
	e.addProperty("propertyKey", "propertyValue");

	vector<string> types = e.getTypes();

	for(int i=0; i < e.getTypes().size(); i++){
   		cout <<	e.getTypes()[i] << endl;
	}

	map<std::string, std::string>::iterator it;

	for(it = e.getProperties().begin(); it!=e.getProperties().end(); ++it) {
			
			cout << it->first << endl;
			cout << it->second << endl;
			
		}

  	cout << "Denise and Alex's insane graph database" << endl;
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
 	e2.setEnd1(&web);
	e2.setEnd2(&html);
	e2.addType("includes"); //can we do this all in one step so that in that step the node functions get called too in order to update the nodes?
	e2.addProperty("strength","5"); //must enforce one type so that the property unambiguously matches a type
	html.addEdge(&e2);
	web.addEdge(&e2);


	Edge e3;
 	e3.setEnd1(&html);
	e3.setEnd2(&web);
	e3.addType("included_in"); //can we do this all in one step so that in that step the node functions get called too in order to update the nodes?
	e3.addProperty("strength","5"); //must enforce one type so that the property unambiguously matches a type
	html.addEdge(&e3);
	web.addEdge(&e3);


 	web.printNode();
 	html.printNode();

 	// e.getEnd1("Web"); e.get


  return 0;
}