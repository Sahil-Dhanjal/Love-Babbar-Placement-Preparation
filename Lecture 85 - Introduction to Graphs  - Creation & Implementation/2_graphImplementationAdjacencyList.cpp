// Adjacency List Representation of a Graph
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// In order to make the graph Generic, we'll use a Template
template < typename T >

class Graph{
    // CLASS PROPERTIES
    // Map Being Used for mapping the vertices to their respective list of Adjacents.
    unordered_map< T , list<T> > adjList;

    // Is the graph Directed or Undirected?
    // isDirected - 1 : means that the graphs is directed
	// isDirected - 0: means that the graph is undirected
    bool isDirected;

    // What are the Number of Vertices/nodes in the graph?
    int numVertices;

    public:

    // CONSTRUCTOR FUNCTION
    Graph(int numVertices, bool isDirected){
        this->numVertices = numVertices;
        this->isDirected = isDirected;
    }

    // Add edges
    void addEdge(T u, T v){
        adjList[u].push_back(v);

        // If the graph would've been undirected, we'll have to add an edge from v to u as well.
        if(!isDirected){
            adjList[v].push_back(u);
        }
    }

    // Printing the Adjacency list
    void printAdjList(){
        for(auto i : adjList){

            cout<<"Vertex "<<i.first<<" : ";
            for(auto j: i.second){
                cout<<j<<" ";
            }

            cout<<endl;
        }
    }
};

int main(){
    int numVertices;
    cout<<"Enter the number of vertices : ";
    cin>>numVertices;

    int numEdges;
    cout<<"\nEnter the number of Edges : ";
    cin>>numEdges;

    bool isDirected;
    cout<<"\nIs you graph directed? : ";
    cin>>isDirected;

    Graph<int> g(numVertices , isDirected);

    // Taking input for the Edges
    for(int i = 0; i<numEdges; i++){
        // You need to change the below Datatype as per your value of T you chose for your Graph.
        int u,v;
        cin >> u >> v;
        g.addEdge(u , v);
    }

    // print the Graph
    g.printAdjList();

}