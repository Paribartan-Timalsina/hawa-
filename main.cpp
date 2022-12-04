#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
    Graph g1;
    cout << g1.isEmpty() << endl;
    cout << g1.isDirected() << endl;
   g1.removeVertex(300);
    g1.addVertex(10);
    g1.removeVertex(200);
    g1.addVertex(20);
    g1.addVertex(30);
    g1.addVertex(40);
    g1.traverse();
    g1.addEdge(30, 10);
    g1.addEdge(30, 20);
   g1.addEdge(30, 40);
   g1.traverse();
   g1.removeEdge(30, 40);
   g1.removeEdge(30, 20);
   g1.removeEdge(30, 100);
    g1.traverse();
    g1.removeVertex(10);
     g1.removeVertex(100);
     g1.removeVertex(90);
   g1.traverse();
  cout<<"The total number of vertices are: "<< g1.numVertices()<<endl;
   cout<<g1.inDegree(40)<<endl;
    cout<<g1.outDegree(30)<<endl;
   cout<<g1.degree(30)<<endl;
}