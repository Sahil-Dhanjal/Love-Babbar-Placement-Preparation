// Adjacency Matrix Representation fo a Graph
#include<iostream>
using namespace std;

class Graph{
    // CLASS PROPERTIES

    // What are the Number of Vertices that our graph has?
    int numVertices;

    // A 2D Array made specifically for the Graph - Dynamically!
    bool **adjMatrix;

	// Is the graph a directed or an Undirected Graph?
	// isDirected - 1 : means that the graphs is directed
	// isDirected - 0: means that the graph is undirected
	bool isDirected;

    // CLASS FUNCTIONALITIES
    public:
       // CONSTRUCTOR FUNCTION made to initialize the 2D Array with 0.
	   Graph(int numVertices, bool isDirected){

			this->numVertices = numVertices;
			this->isDirected = isDirected;

			adjMatrix = new bool*[numVertices];

			// Row-Wise Operation
			for(int i = 0; i < numVertices; i++){
				// Assign Each row its own 1D Array
				adjMatrix[i] = new bool[numVertices];
				// Column-Wise Operation
				for(int j = 0; j < numVertices; j++){
					adjMatrix[i][j] = false;
				}
			}
	   }

	   // Adding Edges
	   void addEdges(int u, int v){
			adjMatrix[u][v] = true;

			if(!isDirected){
				// If the graph is not directed, so add the edge from v to u as well
				adjMatrix[v][u] = true;
			}
	   }

	   // Removing Edges
	   void removeEdges(int u, int v){

			adjMatrix[u][v] = false;

			if(!isDirected){
				// If the graph is not directed, so remove the edge from v to u as well
				adjMatrix[v][u] = false;
			}
	   }

	   // Printing the Adjacency matrix
	   void printAdjMatrix(){
			for(int i = 0; i < numVertices; i++){
				cout<<"Vertex "<<i<<" : ";
				
				for(int j = 0; j < numVertices; j++){
					cout<<adjMatrix[i][j]<<" ";
				}

				cout<<endl;
			}
	   }

	   // DESTRUCTOR FUNCTION
	   ~Graph(){
			// FREE memory of the individual rows first
			for(int i = 0; i < numVertices; i++){
				delete[] adjMatrix[i];
			}

			// Free the memory for the pointers Array next, that contained the addresses for the rows!
			delete[] adjMatrix;
	   }
};


int main(){

	Graph g(3, true);

	g.addEdges(0,1);
	g.addEdges(0,2);
	g.addEdges(2,0);
	g.addEdges(2,1);

	g.printAdjMatrix();
	
	return 0;
}