##SUPER AWESOME GRAPH LIBRARY


###To Do:

#####Methods Graph should have access to:

	* get all edges on node with certain property
	* check if node is connected to edge of certain ID

	* get all nodes with certain label
	* get all nodes with a certain property

	* get nodes at other end of edges attached to a node (i.e neighours)
	* get nodes at other end of edges attached to a node with specific label (i.e neighbours who are also parents)

### OPTIMIZATIONS:

* Graph Object should have methods to perform on nodes and edges (i.e print them out).
* Create an interface for edges and nodes, so you can call similar methods on them if necessary (like printOut...)
* remove pointers and make everything references
* add optimisation class that holds lists that are used alot. There should be a dirty flag set whenever a node/edge is added/removed to say that the optimisation is out of date

	* The database loader can then close itself down (call destroy on everything it has finished with)

### ISSUES

* Concern over what will get destroyed - i.e memory leak.
* concern over buffer overflows with queries - currently 100 bytes and no check
* concern over DB injection, although everything is read only at the moment.
* need to make sure nothing that can be destroyed, isnt being destroyed and there is a memory leak.


/*

{
  "nodes":[
    {"name":"Myriel","group":1},
   {"name":"Child1","group":10},
    {"name":"Child2","group":10},
    {"name":"Brujon","group":4},
    {"name":"Mme.Hucheloup","group":8}
  ],
  "links":[
    {"source":1,"target":0,"value":1},
    {"source":2,"target":0,"value":8},
    {"source":3,"target":0,"value":10},
    {"source":3,"target":2,"value":6},
    {"source":4,"target":0,"value":1},
    {"source":76,"target":58,"value":1}
  ]
}

*/

