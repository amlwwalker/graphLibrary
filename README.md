##SUPER AWESOME GRAPH LIBRARY


###To Do:

* Make Graph Object own lists of nodes and edges.
* Graph Object should have methods to perform on nodes and edges (i.e print them out).
* The Graph Object should pass references to the nodes/edges-lists to the database loader.
	* The database loader then fills the lists.
	* The database loader can then close itself down (call destroy on everything it has finished with)
	* Concern over what will get destroyed - i.e memory leak.
* Create an interface for edges and nodes, so you can call similar methods on them if necessary (like printOut...)
* remove pointers and make everything references
* 