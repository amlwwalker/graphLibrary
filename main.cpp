// 'Hello World!' program 
 
#include "main.h"
using namespace std;



Graph *graph;
DatabaseLoader *db;

//WEB SERVER STUFF:
static const char *s_no_cache_header =
  "Cache-Control: max-age=0, post-check=0, "
  "pre-check=0, no-store, no-cache, must-revalidate\r\n";

static void showAllNodes(struct mg_connection *conn) {
  mg_printf_data(conn, graph->printNodesToJson().c_str());
}

static void showAllEdges(struct mg_connection *conn) {
  mg_printf_data(conn, graph->printEdgesToJson().c_str());
}

static void showNode(struct mg_connection *conn) {
	char nodeId[100];
	mg_get_var(conn, "id", nodeId, sizeof(nodeId));
	//crashes if the id doesnt exist (or isnt set)
	Node *n = graph->findNodeWithId(nodeId);
	if (n == NULL){
		mg_printf_data(conn, "Sorry no node found...");
		return;
	}

  mg_printf_data(conn, graph->printNodeToJson(n).c_str());
}

static void showEdge(struct mg_connection *conn) {
	char edgeId[100];
	mg_get_var(conn, "id", edgeId, sizeof(edgeId));
	//crashes if the id doesnt exist (or isnt set)
	Edge *e = graph->findEdgeWithId(edgeId);
	if (e == NULL){
		mg_printf_data(conn, "Sorry no edge found...");
		return;
	}

  mg_printf_data(conn, graph->printEdgeToJson(e).c_str());
}

static void exampleCalc(struct mg_connection *conn) {
  char n1[100], n2[100]; //could be buffer overflowed???12345

  // Get form variables
  mg_get_var(conn, "n1", n1, sizeof(n1));
  mg_get_var(conn, "n2", n2, sizeof(n2));

  mg_printf_data(conn, "{ \"result\": %lf }", strtod(n1, NULL) + strtod(n2, NULL));

}

static int ev_handler(struct mg_connection *conn, enum mg_event ev) {
  switch (ev) {
    case MG_AUTH: return MG_TRUE;
    case MG_REQUEST:
          if (!strcmp(conn->uri, "/example/calc")) {
        exampleCalc(conn);
        return MG_TRUE;
      }
      else if (!strcmp(conn->uri, "/showAllNodes")) {
        showAllNodes(conn);
        return MG_TRUE;
      }
      else if (!strcmp(conn->uri, "/showNode")) {
        showNode(conn);
        return MG_TRUE;
      }
      else if (!strcmp(conn->uri, "/showAllEdges")) {
        showAllEdges(conn);
        return MG_TRUE;
      }
      else if (!strcmp(conn->uri, "/showEdge")) {
        showEdge(conn);
        return MG_TRUE;
      }
      mg_send_file(conn, "index.html", s_no_cache_header);
      return MG_MORE;
    default: return MG_FALSE;
  }
}

void startWebServer(){
	struct mg_server *server;	

	// // Create and configure the server
  server = mg_create_server(NULL, ev_handler);
  mg_set_option(server, "listening_port", "8000");

  // Serve request. Hit Ctrl-C to terminate the program
  printf("Starting on port %s\n", mg_get_option(server, "listening_port"));
  for (;;) {
    mg_poll_server(server, 1000);
  }

  // Cleanup, and free server instance
  mg_destroy_server(&server);
}
//////


 
int main ( int argc, char *argv[] )
{	
	// char* database;
	if ( argc != 2 ) { // argc should be 2 for correct execution
    // We print argv[0] assuming it is the program name
    	cout<<"usage: "<< argv[0] <<" <database name>\n";
		return 0;
	}

	cout << "Denise and Alex's insane graph database. \n\tUsing database: " << argv[1] << endl;

	
	graph = new Graph();
	  	//creating nodes and edges from a JSON file
	db = new DatabaseLoader(argv[1], graph->getNodeReference(), graph->getEdgeReference());


	db->loadDatabase();	

// /*****************************************************/

	//creating nodes and edges algorithmically
	Node dynWeb, dynHtml;
 	// web.setName("Web");
 	dynWeb.set_id("dyn_web");
 	dynWeb.addLabel("Field");
 	dynWeb.addLabel("Parent");
 	dynWeb.addProperty("name::","dyn_web");
 	dynWeb.addProperty("show_name","dyn_web");
 	vector<string> dynWebDimensions;
 	// dynWebDimensions = new(vector<string>);
 	dynWebDimensions.push_back("33");
 	dynWebDimensions.push_back("84");
 	dynWeb.addProperty("dimensions", dynWebDimensions);
 	
 	graph->addNode(&dynWeb);
	
	// graph.printEdges();
 	dynHtml.set_id("dyn_HTML");
 	dynHtml.addLabel("Topic");
 	dynHtml.addLabel("Parent");
 	dynHtml.addProperty("name::","dyn_HTML");
 	dynHtml.addProperty("show_name","dyn_HTML");
	vector<string> dynHtmlDimensions; //as this is a value and not a pointer it will be destroyed later
	dynHtmlDimensions.push_back("33");
 	dynHtmlDimensions.push_back("66");
 	dynHtml.addProperty("dimensions", dynHtmlDimensions);
 	
 	graph->addNode(&dynHtml);

 	

 	Edge e2;
 	//function to set id, from and to nodes directly.
	e2.setUpEdge("7363", &dynHtml, &dynWeb);
	e2.addType("includes"); //can we do this all in one step so that in that step the node functions get called too in order to update the nodes?
	e2.addProperty("weight","5"); //must enforce one type so that the property unambiguously matches a type
	dynHtml.addEdge(&e2);
	dynWeb.addEdge(&e2);

	graph->addEdge(&e2);
	

	Edge e3;
	e3.setUpEdge("2037", graph->findNodeWithId("web"), &dynHtml);
 	
	e3.addType("included_in"); //can we do this all in one step so that in that step the node functions get called too in order to update the nodes?
	e3.addProperty("weight","3"); //must enforce one type so that the property unambiguously matches a type
	dynHtml.addEdge(&e3);
	dynWeb.addEdge(&e3);
	
	graph->addEdge(&e3);
	
	//graph.printNodes();
	//graph.printEdges();

	//testing if can get edges of a certain type:

	vector <Edge*> * edgeList = dynHtml.getEdgesWithType("includes");
	//why do I need two loops to do this, this suggests that this is a vector <vector <Edge*>> - whats going on?
	for (int i = 0; i < edgeList->size(); i++) {
		vector <Edge*> tempEdge = edgeList[i];
		for (int j = 0; j < tempEdge.size(); j++){
			cout << tempEdge[i]->getId() << endl;
		}
	}

	startWebServer();
  return 0;
}

