##SUPER AWESOME GRAPH LIBRARY

REQUIRED:
Mongoose web server.
Rapidjson.
File structure:

~~~
.
├── SampleGraph
│   ├── Documentation
│   │   └── Docs
│   │       └── html
│   └── web
├── graphLibrary
│   ├── Examples
│   └── src
│       └── GraphObjects
├── rapidjson
│   └── internal
└── webserver
~~~

* This assumes Doxygen is being used to handle documentation. In the above tree all Doxygen files are in Documentation, which also stores the documentation. By commenting methods and functions like this:
* The directory webserver is where the mongoose files are
* The web directory stores any files that are to do with your specific project, hosted by mongoose.subl
* Download `rapidjson` from here: https://code.google.com/p/rapidjson/downloads/detail?name=rapidjson-0.11.zip&can=2&q=
	* In the directory include is another directory called rapidjson. This is all you need. Copy this to your project folder.
* Download `mongoose` from here. It is a git repository: https://github.com/cesanta/mongoose
* Example usage in Examples.
* src stores all of the files required for the library.


~~~
/**
This is a comment
*/
void function() {
	
}
~~~
* Then Doxygen will pick up on the comment because of the two * at the beginning.
* A single line comment will be picked up if it leads with three forward slases:
~~~
///this is a comment
~~~

DatabaseLoader.cpp loads the json in. The only cpp file required to be edited
See the example that loads some json data of qpr vs burnley.
To understand how to load json see tutorial.cpp
Check graph.html to see how the d3 works.
Mongoose is the webserver, all end points are in main.cpp
Can add more end points to kick off queries within the DB.

Graph object should own the lists of nodes and edges and should do standard queries on them.
A new class (Algorithms.cpp or something) should handle specific queries for a specific problem.
The d3 can hit any end point that returns json - however putting limits on the data doesnt currently work as my understanding of d3 is not very good. I.e the length get parameter that can be added currently is not used.










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




