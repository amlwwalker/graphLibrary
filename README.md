##SUPER AWESOME GRAPH LIBRARY


###To Do:


### TO DO NEXT:

Methods Graph should have access to:

	* get all edges on node - DONE
	* get all edges on node of certain type (for now only one type is allowed) - DONE (but odd???)
	* get all edges on node with certain property
	* check if node is connected to edge of certain ID

	* get all nodes with certain label
	* get all nodes with a certain property
	* get node with a certain name

	* get nodes at other end of edges attached to a node (i.e neighours)
	* get nodes at other end of edges attached to a node with specific label (i.e neighbours who are also parents)

--- OPTIMIZATIONS:

* Graph Object should have methods to perform on nodes and edges (i.e print them out).
* Create an interface for edges and nodes, so you can call similar methods on them if necessary (like printOut...)
* remove pointers and make everything references
* add optimisation class that holds lists that are used alot. There should be a dirty flag set whenever a node/edge is added/removed to say that the optimisation is out of date

	* The database loader can then close itself down (call destroy on everything it has finished with)
	* Concern over what will get destroyed - i.e memory leak.



 - Get it building..
 - Add web server so can get results back in json format
